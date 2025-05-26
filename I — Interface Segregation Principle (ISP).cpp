#include <stdexcept>

struct Document {};


struct IMultiFunctionDevice {
    virtual void print(const Document& doc) = 0;
    virtual void scan(const Document& doc)  = 0;
};


class MultiFunctionPrinter : public IMultiFunctionDevice {
public:
    void print(const Document& doc) override {

    }
    void scan(const Document& doc) override {

    }
};


class OldPrinter : public IMultiFunctionDevice {
public:
    void print(const Document& doc) override {

    }
    void scan(const Document& doc) override {

        throw std::logic_error("Operação não suportada");
    }
};
 

/*
No exemplo acima, OldPrinter herda da interface IMultiFunctionDevice completa, mas não deveria ter que implementar scan(). 
Isso fere o ISP. Para corrigir, segregamos as interfaces:

*/


struct IPrinter {
    virtual void print(const Document& doc) = 0;
};

struct IScanner {
    virtual void scan(const Document& doc) = 0;
};


class BetterPrinter : public IPrinter {
public:
    void print(const Document& doc) override {

    }
};


class BetterScanner : public IScanner {
public:
    void scan(const Document& doc) override {

    }
};
