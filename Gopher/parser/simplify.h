#ifndef SIMPLIFY__H
#define SIMPLIFY__H

#include "parser.h"
#include <memory>
#include <unordered_map>

namespace client
{
  struct num_type
  {
    num_type();
    num_type(double _value);
    double value   = 0.0;
    bool is_double = false;
  };

  class num_visitor : public boost::static_visitor<num_type>
  {
  public:
    num_visitor();
    num_visitor(std::unordered_map<std::string, double> *_map);
    num_type operator()(nil &t) const;
    num_type operator()(double &t) const;
    num_type operator()(std::string &t) const;
    num_type operator()(binary_operation &t) const;
    num_type operator()(unary_operation &t) const;

  private:
    std::unordered_map<std::string, double> *var_map = nullptr;
  };

  struct collapsed_type
  {
    collapsed_type();
    collapsed_type(double _value);
    double value      = 0.0;
    bool can_collapse = false;
  };

  class collapse_visitor : public boost::static_visitor<collapsed_type>
  {
  public:
    collapse_visitor();
    collapse_visitor(std::unordered_map<std::string, double> *_map);
    collapsed_type operator()(nil &t) const;
    collapsed_type operator()(double &t) const;
    collapsed_type operator()(std::string &t) const;
    collapsed_type operator()(binary_operation &t) const;
    collapsed_type operator()(unary_operation &t) const;

  private:
    std::unique_ptr<num_visitor> num_visitor_m;
  };
}

#endif
