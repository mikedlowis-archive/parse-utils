#include <sstream>
#include "exception.h"

Exception::Exception() throw() : std::exception()
{
}

Exception::Exception(const Token& tok) throw() : std::exception(), ex_line(tok.line()), ex_column(tok.column())
{
    std::ostringstream oss;
    oss << "(ln " << ex_line << ", col " << ex_column << "): ";
    oss << ((Exception*)this)->message() << std::endl;
    ex_msg = oss.str();
}

Exception::Exception(int line, int column) throw() : std::exception(), ex_line(line), ex_column(column)
{
    std::ostringstream oss;
    oss << "(ln " << ex_line << ", col " << ex_column << "): ";
    oss << ((Exception*)this)->message() << std::endl;
    ex_msg = oss.str();
}

const char* Exception::what() const throw()
{
    return ex_msg.c_str();
}

void Exception::message(const std::string& msg) throw()
{
    ex_msg = msg;
}

const std::string& Exception::message(void) const throw()
{
    return ex_msg;
}

Exception& operator<< (Exception& ex, const std::string& rhs)
{
    ex.ex_msg.append(rhs);
    return ex;
}

Exception& operator<< (Exception& ex, unsigned int rhs)
{
    std::stringstream ss;
    ss << rhs;
    ex.ex_msg.append( ss.str() );
    return ex;
}
