#ifndef COLLAPSE_H
#define COLLAPSE_H

#include "parser.h"

namespace Parser
{

  struct isNum
  {
    bool is_a_number = false;
    double value;
  };

  class isNumVisitor
  {
  public:
    isNum operator()(nil &t) const;
    isNum operator()(double t) const;
    isNum operator()(std::string &t) const;
    isNum operator()(binary_operation &t) const;
    isNum operator()(unary_operation &t) const;
  };

  inline isNum isNumVisitor::operator()(nil &t) const { return isNum(); }
  inline isNum isNumVisitor::operator()(double t) const { return {true, t}; }
  inline isNum isNumVisitor::operator()(std::string &t) const { return isNum(); }
  inline isNum isNumVisitor::operator()(binary_operation &t) const { return isNum(); }
  inline isNum isNumVisitor::operator()(unary_operation &t) const { return isNum(); }

  double get_val(double l, double r, BIN_OP t);
  double get_val(double val, UN_OP t);

  class collapseVisitor
  {
  public:
    ast operator()(nil &t) const;
    ast operator()(double &t) const;
    ast operator()(std::string &t) const;
    ast operator()(binary_operation &t) const;
    ast operator()(unary_operation &t) const;
  };

  ast::ast_type collapse(expression &expr);
}

#endif // COLLAPSE_H
