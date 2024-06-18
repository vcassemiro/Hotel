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



Servico::Servico(int idServico, string descricao, double preco) {
    this->idServico = idServico;
    this->descricao = descricao;
    this->preco = preco;
}

Servico::~Servico() {}

string Servico::paraCSV() {
    stringstream ss;
    ss << idServico << "," << descricao << "," << preco;
    return ss.str();
}

Servico Servico::fromCSV(const std::string& csv) {
    stringstream ss(csv);
    string idServicoStr, descricao, precoStr;
    getline(ss, idServicoStr, ',');
    getline(ss, descricao, ',');
    getline(ss, precoStr, ',');
    }


Hospede* getHospedeById(const std::string& id) {
    return nullptr;
}

Quarto* getQuartoByNumero(const std::string& numero) {
    return nullptr;
}

Servico* getServicoById(const std::string& id) {
    return nullptr;
}

Servico* getServicoById(const std::string& id) {
    return nullptr;
}
