#ifndef PARTIALCOLLAPE_H
#define PARTIALCOLLAPE_H

#include "parser.h"

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

  ast::ast_type partial_collapse(expression &expr, std::string var, double value);
};

#endif // PARTIALCOLLAPE_H
