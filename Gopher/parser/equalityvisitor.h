#ifndef EQUALITYVISITOR_H
#define EQUALITYVISITOR_H

#include "parser.h"

namespace Parser
{
  class EqualityVisitor
  {
  public:
    bool operator()(nil &t) const;
    bool operator()(double &t) const;
    bool operator()(std::string &t) const;
    bool operator()(binary_operation &t) const;
    bool operator()(unary_operation &t) const;
  };

  inline bool EqualityVisitor::perator()(nil &t) const
}

#endif // EQUALITYVISITOR_H
