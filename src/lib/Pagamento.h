#ifndef PAGAMENTO_H
#define PAGAMENTO_H

#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class Pagamento {
public:
    double valor;
    std::string metodo;
    std::string data;
    int idPagamento; 

    Pagamento(const Pagamento&);
    Pagamento& operator=(const Pagamento&);

public:
    Pagamento(double valor, const std::string& metodo, const std::string& data);
    ~Pagamento();

    double getValor() const;
    void setValor(double valor);

    std::string getMetodo() const;
    void setMetodo(const std::string& metodo);

    std::string getData() const;
    void setData(const std::string& data);

    int getIdPagamento() const; 
    void setIdPagamento(int id); 

    std::string paraCSV() const;
    static Pagamento fromCSV(const std::string& csv);
};

#endif // PAGAMENTO_H


