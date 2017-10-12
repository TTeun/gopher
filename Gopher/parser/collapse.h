#ifndef COLLAPSE_H
#define COLLAPSE_H

#include "parser.h"

namespace Parser
{
  ast::ast_type collapse(expression &expr);
  ast::ast_type partial_collapse(expression &expr, std::string var, double value);
}
#endif // COLLAPSE_H
