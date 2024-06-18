#ifndef SERVICO_H
#define SERVICO_H

#include "Pessoa.h"
#include "Avaliacao.h"
#include "Cliente.h"
#include "Hospede.h"
#include "Hotel.h"
#include "Pagamento.h"
#include "Quarto.h"
#include "Quarto_Luxo.h"
#include "Quarto_Simples.h"
#include "Quarto_Suite.h"
#include "Reserva.h"
#include "Dados.h"
#include "Servico.h"

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
    Servico(int idServico, string descricao, double preco);
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

    string paraCSV();
    static Servico fromCSV(const std::string& csv);
};


#endif // SERVICO_H

