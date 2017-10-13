#include "partialcollapse.h"
#include "collapse.h"
#include <QDebug>
#include <stdexcept>

namespace Parser
{
  partialCollapseVisitor::partialCollapseVisitor(std::string &_var, double _value)
  {
    var   = _var;
    value = _value;
  }

  ast partialCollapseVisitor::operator()(nil &t) const
  {
    return t;
  }
  ast partialCollapseVisitor::operator()(double &t) const
  {
    return t;
  }
  ast partialCollapseVisitor::operator()(std::string &t) const
  {
    if (t == var)
      return value;

    return t;
  }
  ast partialCollapseVisitor::operator()(binary_operation &t) const
  {
    return binary_operation(
        t.tag, boost::apply_visitor(*this, t.left.type).type, boost::apply_visitor(*this, t.right.type).type);
  }
  ast partialCollapseVisitor::operator()(unary_operation &t) const
  {
    return unary_operation(t.tag, boost::apply_visitor(*this, t.tree.type).type);
  }

  double eval(ast::ast_type &type,
              std::pair<std::string, double> const &val1,
              std::pair<std::string, double> const &val2)
  {
    auto t       = partialCollapse(type, val1.first, val1.second);
    t            = partialCollapse(t, val2.first, val2.second);
    t            = collapse(t);
    isNum is_num = boost::apply_visitor(isNumVisitor{}, t);
    if (not is_num.is_a_number)
      throw std::string{"Could not collapse ast down to a number"};

    return is_num.value;
  }
}
