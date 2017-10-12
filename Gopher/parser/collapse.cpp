#include "collapse.h"
#include "print.h"
#include <QDebug>

namespace Parser
{
  double Error = -1000000.0;

  struct is_num
  {
    bool is_a_number = false;
    double value;
  };

  class is_num_visitor
  {
  public:
    is_num operator()(nil &t) const { return {false}; }
    is_num operator()(double t) const { return {true, t}; }
    is_num operator()(std::string &t) const { return {false}; }
    is_num operator()(binary_operation &t) const { return {false}; }
    is_num operator()(unary_operation &t) const { return {false}; }
  };

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

  class collapse_visitor
  {
  public:
    ast operator()(nil t) const { return t; }
    ast operator()(double t) const { return t; }
    ast operator()(std::string t) const { return t; }
    ast operator()(binary_operation t) const
    {
      t.left.type  = boost::apply_visitor(*this, t.left.type).type;
      t.right.type = boost::apply_visitor(*this, t.right.type).type;
      is_num r_val, l_val;

      if (((r_val = boost::apply_visitor(is_num_visitor{}, t.right.type)).is_a_number == true) &&
          ((l_val = boost::apply_visitor(is_num_visitor{}, t.left.type)).is_a_number == true))
      {
        qDebug() << l_val.value << ", " << r_val.value;
        return get_val(l_val.value, r_val.value, t.tag);
      }

      return t;
    }
    ast operator()(unary_operation t) const
    {
      t.tree.type = boost::apply_visitor(*this, t.tree.type).type;

      is_num val;

      if ((val = boost::apply_visitor(is_num_visitor{}, t.tree.type)).is_a_number == true)
      {
        qDebug() << val.value;
        return get_val(val.value, t.tag);
      }
      return t;
    }
  };

  class partial_collapse_visitor
  {
  public:
    partial_collapse_visitor(std::string &_var, double _value)
    {
      var   = _var;
      value = _value;
    }

    ast operator()(nil &t) const { return t; }
    ast operator()(double &t) const { return t; }
    ast operator()(std::string &t) const
    {
      if (t == var)
        return value;
      return t;
    }
    ast operator()(binary_operation &t) const { return t; }
    ast operator()(unary_operation &t) const { return t; }

  private:
    std::string var;
    double value;
  };

  ast::ast_type collapse(expression &expr)
  {
    auto t = boost::apply_visitor(collapse_visitor{}, expr.syntax_tree.type).type;
    print_visitor p;
    boost::apply_visitor(p, t);
    qDebug() << *(p.str);

    return t;
  }

  ast::ast_type partial_collapse(expression &expr, std::string var, double value)
  {
    partial_collapse_visitor visitor(var, value);
    ast::ast_type collapsed = boost::apply_visitor(visitor, collapsed).type;
    return boost::apply_visitor(collapse_visitor{}, collapsed).type;
  }
}
