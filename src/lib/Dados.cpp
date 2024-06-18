
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

Dados::Dados(const std::string& fileName) : fileName(fileName) {}

Dados::~Dados() {}

std::vector<Quarto> Dados::carregarQuartos() {
    std::vector<Quarto> quartos;
    std::ifstream file(fileName);
    std::string line;

    while (std::getline(file, line)) {
        if (line.find("Quarto") == 0) {
            quartos.push_back(Quarto::fromCSV(line));
        }
    }

    return quartos;
}

std::vector<Hospede> Dados::carregarHospedes() {
    std::vector<Hospede> hospedes;
    std::ifstream file(fileName);
    std::string line;

    while (std::getline(file, line)) {
        if (line.find("Hospede") == 0) {
            hospedes.push_back(Hospede::fromCSV(line));
        }
    }

    return hospedes;
}

std::vector<Reserva> Dados::carregarReservas() {
    std::vector<Reserva> reservas;
    std::ifstream file(fileName);
    std::string line;

    while (std::getline(file, line)) {
        if (line.find("Reserva") == 0) {
            reservas.push_back(Reserva::fromCSV(line));
        }
    }

    return reservas;
}

std::vector<Pagamento> Dados::carregarPagamentos() {
    std::vector<Pagamento> pagamentos;
    std::ifstream file(fileName);
    std::string line;

    while (std::getline(file, line)) {
        if (line.find("Pagamento") == 0) {
            pagamentos.push_back(Pagamento::fromCSV(line));
        }
    }

    return pagamentos;
}

std::vector<Avaliacoes> Dados::carregarAvaliacoes() {
    std::vector<Avaliacoes> avaliacoes;
    std::ifstream file(fileName);
    std::string line;

    while (std::getline(file, line)) {
        if (line.find("Avaliacao") == 0) {
            avaliacoes.push_back(Avaliacoes::fromCSV(line));
        }
    }

    return avaliacoes;
}
