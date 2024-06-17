#include "Servico.h"
#include <sstream>

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

    int idServico = stoi(idServicoStr);
    double preco = stod(precoStr);

    return Servico(idServico, descricao, preco);
}