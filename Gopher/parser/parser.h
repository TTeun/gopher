#ifndef PARSER__H
#define PARSER__H

#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/variant/variant.hpp>

#include <string>
#include <vector>

namespace qi      = boost::spirit::qi;
namespace ascii   = boost::spirit::ascii;
namespace phoenix = boost::phoenix;

namespace client
{
  enum class BIN_OP
  {
    ADD,
    SUB,
    MUL,
    DIV,
    POW
  };
  enum class UN_OP
  {
    MIN,
    SIN,
    COS,
    TAN,
    EXP
  };

  struct binary_operation;
  struct unary_operation;
  struct nil
  {
  };

  struct ast
  {
    typedef boost::variant<nil,
                           double,
                           std::string,
                           boost::recursive_wrapper<binary_operation>,
                           boost::recursive_wrapper<unary_operation>>
        ast_type;

    ast &operator+=(ast const &rhs);
    ast &operator-=(ast const &rhs);
    ast &operator*=(ast const &rhs);
    ast &operator/=(ast const &rhs);
    ast &operator^=(ast const &rhs);

    ast() : type(nil()) {} // Error state

    template <typename Expr> ast(Expr const &type) : type(type) {}

    ast_type type;
  };

  struct binary_operation
  {
    BIN_OP tag;
    ast left;
    ast right;

    binary_operation(BIN_OP _tag, ast const &_left, ast const &_right) : tag(_tag), left(_left), right(_right)
    {
    }
  };

  struct unary_operation
  {
    UN_OP tag;
    ast tree;

    unary_operation(UN_OP _tag, ast const &_tree) : tag(_tag), tree(_tree) {}
  };

  struct expression
  {
    std::string name;
    std::vector<std::string> arguments;
    ast syntax_tree;
  };
  void print_tree(expression &expr);

  template <typename Iterator> struct exp_parser;
}

BOOST_FUSION_ADAPT_STRUCT(client::expression, name, arguments, syntax_tree)

namespace client
{
  template <typename Iterator> struct exp_parser : qi::grammar<Iterator, expression(), ascii::space_type>
  {
    static ast make_unary(UN_OP op, ast const &tree) { return unary_operation(op, tree); }
    exp_parser() : exp_parser::base_type(all)
    {
      using qi::_val;
      using qi::_1;
      using qi::char_;
      using qi::double_;
      using qi::lit;
      using phoenix::at_c;
      using phoenix::push_back;
      using phoenix::bind;

      all = name >> '(' >> -vars >> ')' >> '=' >> expr;

      // Parsing of actual expression
      expr = term[_val = _1] >> *(('+' >> term[_val += _1]) | ('-' >> term[_val -= _1]));

      term = factor[_val = _1] >> *(('*' >> factor[_val *= _1]) | ('/' >> factor[_val /= _1]));

      factor = base[_val = _1] >> *(('^' >> base[_val ^= _1]));

      base = simple[_val = _1] | '(' >> expr[_val = _1] >> ')' |
             ('-' >> base[_val = bind(make_unary, UN_OP::MIN, _1)]) |
             ("sin" >> base[_val = bind(make_unary, UN_OP::SIN, _1)]) |
             ("cos" >> base[_val = bind(make_unary, UN_OP::COS, _1)]) |
             ("tan" >> base[_val = bind(make_unary, UN_OP::TAN, _1)]) |
             ("exp" >> base[_val = bind(make_unary, UN_OP::EXP, _1)]) | ('+' >> base[_val = _1]);

      prtctd = lit("sin") | "cos" | "tan" | "exp";
      var    = !prtctd >> (ascii::lower | ascii::upper) >> *(ascii::lower | ascii::upper | ascii::digit);
      num    = double_;
      simple = _declared | num | '(' >> expr >> ')';
      name   = ascii::alpha >> *ascii::alnum;
      vars %= var[bind(_declared.add, _1, _1)] % ',';
    }

  private:
    qi::symbols<char, std::string> _declared;

    qi::rule<Iterator, ast(), ascii::space_type> expr, term, base, factor, simple;
    qi::rule<Iterator, expression(), ascii::space_type> all;
    qi::rule<Iterator, std::vector<std::string>(), ascii::space_type> vars;

    // lexemes
    qi::rule<Iterator, std::string()> name, prtctd;
    qi::rule<Iterator, std::string()> var;
    qi::rule<Iterator, double()> num;
  };
}

#endif
