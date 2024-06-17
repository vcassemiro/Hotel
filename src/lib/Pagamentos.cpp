#include "Pagamentos.h"

#include <iostream>
#include <string>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

    Pagamentos::Pagamentos(string metodo, double valor)
    : metodo(metodo), valor(valor)
    {

    }

    Pagamentos::~Pagamentos()
    {

    }

    string Pagamentos::getMetodo() {
        return metodo;
    }

    double Pagamentos::getValor(){
        return valor;
    }

    void Pagamentos::setMetodo(string metodo){
        this->metodo = metodo;
    }

    void Pagamentos::setValor(double valor){
        this->valor = valor;
    }
