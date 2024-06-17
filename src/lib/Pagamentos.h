#ifndef PAGAMENTOS_H
#define PAGAMENTOS_H

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

    class Pagamentos
    {
    private:
        string metodo;
        double valor;

    public:
        Pagamentos(string metodo, double valor);
        ~Pagamentos();

        string getMetodo();
        double getValor();
        void setMetodo(string metodo);
        void setValor(double valor);

};

#endif // PAGAMENTOS_H
