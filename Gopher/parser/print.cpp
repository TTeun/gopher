#include "print.h"
#include "parser.h"
#include <QString>
#include <qdebug.h>
#include <qglobal.h>

namespace client
{
  class print_visitor
  {
  public:
    ~print_visitor() { delete str; }

    void operator()(nil &t) const
    {
      Q_UNUSED(t);
      qInfo() << "ERROR";
    }
    void operator()(double &t) const { str->append(QString::number(t)); }
    void operator()(std::string &t) const { str->append(t.c_str()); }
    void operator()(binary_operation &t) const
    {
      str->append('(');
      boost::apply_visitor(*this, t.left.type);
      str->append(t.tag == BIN_OP::ADD ? "+" :
                                         t.tag == BIN_OP::SUB ?
                                         "-" :
                                         t.tag == BIN_OP::MUL ?
                                         "*" :
                                         t.tag == BIN_OP::DIV ? "/" : t.tag == BIN_OP::POW ? "^" : "empty");
      boost::apply_visitor(*this, t.right.type);
      str->append(')');
    }
    void operator()(unary_operation &t) const
    {
      str->append(t.tag == UN_OP::MIN ?
                      "-(" :
                      t.tag == UN_OP::SIN ?
                      "sin(" :
                      t.tag == UN_OP::COS ? "cos(" : t.tag == UN_OP::TAN ? "tan(" : "empty(");
      boost::apply_visitor(*this, t.tree.type);
      str->append(')');
    }

    QString *str = new QString;
  };

  void print_tree(expression &expr)
  {
    QString str;
    str.append(expr.name.c_str());
    str.append(" is a function of: ");
    for (auto &a : expr.arguments)
    {
      str.append(a.c_str());
      str.append(" ");
    }
    qDebug() << str;
    print_visitor p;
    boost::apply_visitor(p, expr.syntax_tree.type);
    qDebug() << *(p.str);
  }
}
