#include "symbol.h"

Symbol::Symbol(const std::string& name) : sym_name(name), sym_type(0)
{
}

Symbol::Symbol(const std::string& name, symtype_t type) : sym_name(name), sym_type(0)
{
}

Symbol::~Symbol()
{
}

symtype_t Symbol::type() const
{
    return sym_type;
}

void Symbol::type(symtype_t type)
{
    sym_type = type;
}

const std::string& Symbol::name() const
{
    return sym_name;
}

void Symbol::name(const std::string& name)
{
    sym_name = name;
}

