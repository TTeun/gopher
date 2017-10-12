#include "partialcollapse.h"
#include "collapse.h"

namespace Parser
{
  partialCollapseVisitor::partialCollapseVisitor(std::string &_var, double _value)
  {
    var   = _var;
    value = _value;
  }

  ast partialCollapseVisitor::operator()(nil &t) const { return t; }
  ast partialCollapseVisitor::operator()(double &t) const { return t; }
  ast partialCollapseVisitor::operator()(std::string &t) const
  {
    if (t == var)
      return value;

    return t;
  }
  ast partialCollapseVisitor::operator()(binary_operation &t) const
  {
    t.left.type  = boost::apply_visitor(*this, t.left.type).type;
    t.right.type = boost::apply_visitor(*this, t.right.type).type;
    return t;
  }
  ast partialCollapseVisitor::operator()(unary_operation &t) const
  {
    t.tree.type = boost::apply_visitor(*this, t.tree.type).type;
    return t;
  }

  ast::ast_type partial_collapse(expression &expr, std::string var, double value)
  {
    partialCollapseVisitor visitor(var, value);
    auto collapsed = boost::apply_visitor(visitor, expr.syntax_tree.type).type;
    return boost::apply_visitor(collapseVisitor{}, collapsed).type;
  }
}
