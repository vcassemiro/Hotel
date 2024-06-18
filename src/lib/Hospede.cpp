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

Hospede::Hospede(const std::string& nome, const std::string& telefone, const std::string& email, int idHospede)
    : Cliente(nome, "", telefone, email), idHospede(idHospede) {}
 


std::string Hospede::getEmail() const {
    return email;
}

void Hospede::setEmail(const std::string& email) {
    this->email = email;
}

void Hospede::addReserva(const Reserva& reserva) {
    reservas.push_back(reserva);
}

std::vector<Reserva> Hospede::getReservas() const {
    return reservas;
}

void Hospede::addAvaliacao(const Avaliacoes& avaliacao) {
    avaliacoes.push_back(avaliacao);
}

std::vector<Avaliacoes> Hospede::getAvaliacoes() const {
    return avaliacoes;
}

std::string Hospede::paraCSV() const {
    std::stringstream ss;
    ss << "," << getNome() << "," << getEmail() << "," << getTelefone();
    return ss.str();
}

Hospede Hospede::fromCSV(const std::string& csv) {
    std::stringstream ss(csv);
    std::string nome, email, telefone;
    std::getline(ss, nome, ',');
    std::getline(ss, email, ',');
    std::getline(ss, telefone, ',');
    int idHospede; 
    ss >> idHospede;
    return Hospede(nome, email, telefone, idHospede); 
}

