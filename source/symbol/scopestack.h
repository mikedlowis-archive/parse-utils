#ifndef SCOPE_TREE_H
#define SCOPE_TREE_H

#include <string>
#include <list>
#include <map>
#include "symbol.h"

typedef std::pair<std::string,Symbol> sym_pair_t;
typedef std::map<std::string,Symbol> sym_table_t;

class ScopeStack {
    protected:
        std::list<sym_table_t> scope_stack;
    public:
        ScopeStack();
        virtual ~ScopeStack();

        void startScope();
        void stopScope();
        void define(const std::string& name);
        void define(const std::string& name, symtype_t type);
        const Symbol* lookup(const std::string& name);
        bool isLocal(const std::string& name) const;
        bool isGlobal(const std::string& name) const;
};

#endif
