#ifndef SERVICO_H
#define SERVICO_H

#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Servico {
private:
    int idServico;
    string descricao;
    double preco;

public:
    Servico(int idServico, const string& descricao, double preco);
    ~Servico();

    int getIdServico() const {
        return idServico;
    }

    string getDescricao() const {
        return descricao;
    }

    double getPreco() const {
        return preco;
    }

    void setIdServico(int id) {
        idServico = id;
    }

    void setDescricao(const string& desc) {
        descricao = desc;
    }

    void setPreco(double p) {
        preco = p;
    }

    string paraCSV() const;
    static Servico fromCSV(const string& csv);
};

#endif // SERVICO_H
