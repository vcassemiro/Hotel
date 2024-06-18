#include "Servico.h"

Servico::Servico(int idServico, const string& descricao, double preco)
    : idServico(idServico), descricao(descricao), preco(preco) {}

Servico::~Servico() {}

string Servico::paraCSV() const {
    stringstream ss;
    ss << idServico << "," << descricao << "," << preco;
    return ss.str();
}

Servico Servico::fromCSV(const string& csv) {
    stringstream ss(csv);
    string idStr, desc, precoStr;

    getline(ss, idStr, ',');
    getline(ss, desc, ',');
    getline(ss, precoStr, ',');

    int id = stoi(idStr);
    double preco = stod(precoStr);

    return Servico(id, desc, preco);
}
