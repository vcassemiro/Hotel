
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

Quarto::Quarto(int idQuarto, int idHotel, const std::string& tipo, double preco, bool disponivel)
: idQuarto(idQuarto), idHotel(idHotel), tipo(tipo), preco(preco), disponivel(disponivel)
{
}

Quarto::~Quarto() {
}

void Quarto::addReserva(const Reserva& reserva) {
    reservas.push_back(reserva);
}

const std::vector<Reserva>& Quarto::getReservas() const {
    return reservas;
}

void Quarto::addHospede(const Hospede& hospede) {
    hospedes.push_back(hospede);
}

const std::vector<Hospede>& Quarto::getHospedes() const {
    return hospedes;
}

void Quarto::addServico(const Servico& servico) {
    servicos.push_back(servico);
}

const std::vector<Servico>& Quarto::getServicos() const {
    return servicos;
}

Quarto Quarto::fromCSV(const std::string& csv) {
    std::istringstream iss(csv);
    std::string token;
    int idQ, idH;
    std::string t;
    double p;
    bool d;

    std::getline(iss, token, ',');
    try {
        idQ = std::stoi(token);
    } catch (const std::invalid_argument& e) {
        throw std::runtime_error("Erro ao converter idQuarto para inteiro");
    }

    std::getline(iss, token, ',');
    try {
        idH = std::stoi(token);
    } catch (const std::invalid_argument& e) {
        throw std::runtime_error("Erro ao converter idHotel para inteiro");
    }

    std::getline(iss, t, ',');

    std::getline(iss, token, ',');
    try {
        p = std::stod(token);
    } catch (const std::invalid_argument& e) {
        throw std::runtime_error("Erro ao converter preco para double");
    }

    std::getline(iss, token);
    d = (token == "true");

    return Quarto(idQ, idH, t, p, d);
}
