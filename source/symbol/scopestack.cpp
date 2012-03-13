#include "scopestack.h"
#include <iostream>

using namespace std;

ScopeStack::ScopeStack()
{
    // Initialize the stack
    sym_table_t table;
    scope_stack.push_front( table );
}

ScopeStack::~ScopeStack()
{
}

void ScopeStack::startScope()
{
    sym_table_t table;
    scope_stack.push_front( table );
}

void ScopeStack::stopScope()
{
    scope_stack.pop_front();
}

void ScopeStack::define(const std::string& name)
{
    sym_pair_t pair(name, Symbol(name));
    scope_stack.front().insert( pair );
}

void ScopeStack::define(const std::string& name, symtype_t type)
{
    sym_pair_t pair(name, Symbol(name,type));
    scope_stack.front().insert( pair );
}

const Symbol* ScopeStack::lookup(const std::string& name)
{
    Symbol* p_sym = NULL;
    list<sym_table_t>::iterator it;
    for(it = scope_stack.begin(); it != scope_stack.end(); it++)
    {
        sym_table_t::iterator p_val = (*it).find(name);
        if( p_val != (*it).end())
        {
            p_sym = &(p_val->second);
        }
    }
    return p_sym;
}

bool ScopeStack::isLocal(const std::string& name) const
{
    bool ret = false;
    sym_table_t::const_iterator p_val = scope_stack.front().find(name);
    if( p_val != scope_stack.front().end())
    {
        ret = true;
    }
    return ret;
}

bool ScopeStack::isGlobal(const std::string& name) const
{
    bool ret = false;
    list<sym_table_t>::const_iterator it;
    for(it = ++(scope_stack.begin()); it != scope_stack.end(); it++)
    {
        sym_table_t::const_iterator p_val = (*it).find(name);
        if( p_val != (*it).end())
        {
            ret = true;
            break;
        }
    }
    return ret;
}

