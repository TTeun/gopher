#ifndef PARTIALCOLLAPE_H
#define PARTIALCOLLAPE_H

#include "parser.h"
#include <tuple>

namespace Parser
{
  class partialCollapseVisitor
  {
  public:
    partialCollapseVisitor(std::string &_var, double _value);
    ast operator()(nil &t) const;
    ast operator()(double &t) const;
    ast operator()(std::string &t) const;
    ast operator()(binary_operation &t) const;
    ast operator()(unary_operation &t) const;

  private:
    std::string var;
    double value;
  };

  ast::ast_type partialCollapse(ast::ast_type &type, std::string var, double value);
  inline ast::ast_type partialCollapse(ast::ast_type &type, std::string var, double value)
  {
    return boost::apply_visitor(partialCollapseVisitor{var, value}, type).type;
  }

  double eval(ast::ast_type &type,
              std::pair<std::string, double> const &val1,
              std::pair<std::string, double> const &val2);
};

#endif // PARTIALCOLLAPE_H
