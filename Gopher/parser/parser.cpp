#include "parser.h"
#include "simplify.h"
#include <tuple>

namespace client
{
  ast &ast::operator+=(ast const &rhs)
  {
    type = binary_operation(BIN_OP::ADD, type, rhs);
    return *this;
  }

  ast &ast::operator-=(ast const &rhs)
  {
    type = binary_operation(BIN_OP::SUB, type, rhs);
    return *this;
  }

  ast &ast::operator*=(ast const &rhs)
  {
    type = binary_operation(BIN_OP::MUL, type, rhs);
    return *this;
  }

  ast &ast::operator/=(ast const &rhs)
  {
    type = binary_operation(BIN_OP::DIV, type, rhs);
    return *this;
  }

  ast &ast::operator^=(ast const &rhs)
  {
    type = binary_operation(BIN_OP::POW, type, rhs);
    return *this;
  }
}
