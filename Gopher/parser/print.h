#ifndef PRINT_H
#define PRINT_H

#include "parser.h"
#include <QString>

struct expression;

namespace Parser
{
  class printVisitor
  {
  public:
    ~printVisitor();
    void operator()(nil &t) const;
    void operator()(double &t) const;
    void operator()(std::string &t) const;
    void operator()(binary_operation &t) const;
    void operator()(unary_operation &t) const;

    QString *str = new QString;
  };

  void printTree(expression &expr);
}

#endif // PRINT_H
