#include "simplify.h"
#include <cmath>
#include <limits>
#include <qglobal.h>

namespace client
{
  num_type::num_type() {}
  num_type::num_type(double _value) : value(_value), is_double(true) {}

  collapsed_type::collapsed_type() {}
  collapsed_type::collapsed_type(double _value) : value(_value), can_collapse(true) {}

  num_type num_visitor::operator()(nil &t) const
  {
    Q_UNUSED(t);
    return num_type();
  }
  num_type num_visitor::operator()(double &t) const { return num_type(t); }
  num_type num_visitor::operator()(std::string &t) const
  {
    if (not var_map)
      return num_type();
    if (var_map->find(t) == var_map->end())
      return num_type();
    return num_type((*var_map)[t]);
  }
  num_type num_visitor::operator()(binary_operation &t) const
  {
    Q_UNUSED(t);
    return num_type();
  }
  num_type num_visitor::operator()(unary_operation &t) const
  {
    Q_UNUSED(t);
    return num_type();
  }

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

  num_visitor::num_visitor() {}
  num_visitor::num_visitor(std::unordered_map<std::string, double> *_map) : var_map(_map) {}

  collapse_visitor::collapse_visitor() : num_visitor_m(std::unique_ptr<num_visitor>(new num_visitor())) {}

  collapse_visitor::collapse_visitor(std::unordered_map<std::string, double> *_map)
      : num_visitor_m(std::unique_ptr<num_visitor>(new num_visitor(_map)))
  {
  }

  collapsed_type collapse_visitor::operator()(nil &t) const
  {
    Q_UNUSED(t);
    return collapsed_type();
  }

  collapsed_type collapse_visitor::operator()(double &t) const
  {
    Q_UNUSED(t);
    return collapsed_type(t);
  }

  collapsed_type collapse_visitor::operator()(std::string &t) const
  {
    num_type n_type = num_visitor_m->operator()(t);
    if (n_type.is_double)
      return collapsed_type(n_type.value);

    return collapsed_type();
  }

  collapsed_type collapse_visitor::operator()(binary_operation &t) const
  {
    collapsed_type c = boost::apply_visitor(*this, t.left.type);
    if (c.can_collapse)
      t.left.type = c.value;

    c = boost::apply_visitor(*this, t.right.type);
    if (c.can_collapse)
      t.right.type = c.value;

    num_type left  = boost::apply_visitor(*num_visitor_m, t.left.type);
    num_type right = boost::apply_visitor(*num_visitor_m, t.right.type);
    if (left.is_double && right.is_double)
      return collapsed_type(get_val(left.value, right.value, t.tag));

    return collapsed_type();
  }

  collapsed_type collapse_visitor::operator()(unary_operation &t) const
  {
    collapsed_type c = boost::apply_visitor(*this, t.tree.type);
    if (c.can_collapse)
      t.tree.type = c.value;

    num_type tree = boost::apply_visitor(*num_visitor_m, t.tree.type);
    if (tree.is_double)
      return collapsed_type(get_val(tree.value, t.tag));

    return collapsed_type();
  }
}
