#include "collapse.h"
#include <QDebug>

namespace Parser
{
  double get_val(double l, double r, BIN_OP t)
  {
    switch (t)
    {
    case BIN_OP::ADD:
      return l + r;
      break;
    case BIN_OP::SUB:
      return l - r;
      break;
    case BIN_OP::MUL:
      return l * r;
      break;
    case BIN_OP::DIV:
      if (r == 0.0)
        return l >= 0 ? std::numeric_limits<double>::max() : std::numeric_limits<double>::min();
      return l / r;
      break;
    case BIN_OP::POW:
      return pow(l, r);
      break;
    }
    return 0;
  }

  double get_val(double val, UN_OP t)
  {
    switch (t)
    {
    case UN_OP::SIN:
      return sin(val);
      break;
    case UN_OP::COS:
      return cos(val);
      break;
    case UN_OP::TAN:
      return tan(val);
      break;
    case UN_OP::EXP:
      return exp(val);
      break;
    case UN_OP::MIN:
      return -val;
      break;
    }
    return 0;
  }

  ast collapseVisitor::operator()(nil &t) const
  {
    return t;
  }
  ast collapseVisitor::operator()(double &t) const
  {
    return t;
  }
  ast collapseVisitor::operator()(std::string &t) const
  {
    return t;
  }
  ast collapseVisitor::operator()(binary_operation &t) const
  {
    t.left.type  = boost::apply_visitor(*this, t.left.type).type;
    t.right.type = boost::apply_visitor(*this, t.right.type).type;

    isNum l_val = boost::apply_visitor(isNumVisitor{}, t.left.type);
    isNum r_val = boost::apply_visitor(isNumVisitor{}, t.right.type);

    if (l_val.is_a_number && r_val.is_a_number)
      return get_val(l_val.value, r_val.value, t.tag);

    if (l_val.is_a_number || r_val.is_a_number)
    {
      double value = l_val.is_a_number ? l_val.value : r_val.value;
      auto tree    = l_val.is_a_number ? t.right.type : t.left.type;

      switch (t.tag)
      {
      case BIN_OP::ADD:
        if (value == 0)
          return tree;
        break;
      case BIN_OP::MUL:
        if (value == 0)
          return 0.0;
        if (value == 1)
          return tree;
        break;
      case BIN_OP::POW:
        if (value == 0)
          return 1.0;
        if (value == 1)
          return tree;
        break;
      default:
        break;
      }
    }

    if (t.left.type == t.right.type)
    {
      switch (t.tag)
      {
      case BIN_OP::SUB:
        return 0.0;
        break;
      case BIN_OP::ADD:
        return binary_operation(BIN_OP::MUL, 2.0, t.right.type);
        break;
      case BIN_OP::MUL:
        return binary_operation(BIN_OP::POW, t.right.type, 2.0);
        break;
      case BIN_OP::DIV:
        return 1.0;
        break;
      default:
        break;
      }
    }

    return t;
  }
  ast collapseVisitor::operator()(unary_operation &t) const
  {
    t.tree.type = boost::apply_visitor(*this, t.tree.type).type;

    isNum val;

    if ((val = boost::apply_visitor(isNumVisitor{}, t.tree.type)).is_a_number == true)
      return get_val(val.value, t.tag);

    return t;
  }

  ast::ast_type collapse(ast::ast_type &type)
  {
    return boost::apply_visitor(collapseVisitor{}, type).type;
  }
}
