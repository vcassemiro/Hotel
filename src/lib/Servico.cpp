#include "Servico.h"
#include <sstream>

// Construtor
Servico::Servico(int idServico, string descricao, double preco)
: idServico(idServico), descricao(descricao), preco(preco) {}

// Destrutor
Servico::~Servico() {}

// Getters e Setters...

// Método para converter informações do serviço em formato CSV
string Servico::paraCSV() {
    std::stringstream ss;
    ss << idServico << "," << descricao << "," << preco;
    return ss.str();
}
