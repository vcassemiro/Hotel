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




Hotel::Hotel(int idHotel, string nome, string endereco)
: idHotel(idHotel), nome(nome), endereco(endereco) {}

Hotel::~Hotel() {}

void Hotel::addHospede(Hospede hospede) {
    hospedes.push_back(hospede);
}

vector<Hospede> Hotel::getHospedes() {
    return hospedes;
}

void Hotel::addAvaliacao(Avaliacoes avaliacao) {
    avaliacoes.push_back(avaliacao);
}

vector<Avaliacoes> Hotel::getAvaliacoes() {
    return avaliacoes;
}

void Hotel::addPagamento(Pagamento pagamento) {
    pagamentos.push_back(pagamento);
}

vector<Pagamento> Hotel::getPagamentos() {
    return pagamentos;
}

void Hotel::salvarEmCSV(const string& nomeArquivo) {
    std::ofstream arquivo(nomeArquivo, std::ios::app);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return;
    }

    arquivo << idHotel << "," << nome << "," << endereco << "\n";

    arquivo.close();
}
