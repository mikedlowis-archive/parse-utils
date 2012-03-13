#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>

typedef unsigned int symtype_t;

class Symbol {
    protected:
        std::string sym_name;
        symtype_t sym_type;
    public:
        Symbol(const std::string& name);
        Symbol(const std::string& name, symtype_t type);
        virtual ~Symbol();
        symtype_t type() const;
        void type(symtype_t type);
        const std::string& name() const;
        void name(const std::string& name);
};

#endif
