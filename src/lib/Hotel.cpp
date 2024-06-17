#include "Hotel.h"
#include <fstream>
#include <iostream>

// Construtor
Hotel::Hotel(int idHotel, string nome, string endereco)
: idHotel(idHotel), nome(nome), endereco(endereco) {}

// Destrutor
Hotel::~Hotel() {}

// Getters e Setters...

// Métodos para gerenciar hóspedes...
void Hotel::addHospede(Hospede hospede) {
    hospedes.push_back(hospede);
}

vector<Hospede> Hotel::getHospedes() {
    return hospedes;
}

// Métodos para gerenciar avaliações...
void Hotel::addAvaliacao(Avaliacoes avaliacao) {
    avaliacoes.push_back(avaliacao);
}

vector<Avaliacoes> Hotel::getAvaliacoes() {
    return avaliacoes;
}

// Métodos para gerenciar pagamentos...
void Hotel::addPagamento(Pagamento pagamento) {
    pagamentos.push_back(pagamento);
}

vector<Pagamento> Hotel::getPagamentos() {
    return pagamentos;
}

// Método para salvar informações do hotel em CSV
void Hotel::salvarEmCSV(const string& nomeArquivo) {
    std::ofstream arquivo(nomeArquivo, std::ios::app);
    
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return;
    }

    // Salva informações do hotel
    arquivo << idHotel << "," << nome << "," << endereco << "\n";

    // Salva informações dos quartos...
    
    // Salva informações dos hóspedes...
    
    // Salva informações das avaliações...
    
    // Salva informações dos pagamentos...

    arquivo.close();
}
