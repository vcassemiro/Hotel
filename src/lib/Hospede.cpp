#include "Hospede.h"

#include <string>
#include <sstream>
#include <iostream>


Hospede::Hospede(const std::string& nome, const std::string& cpf, const std::string& telefone, const std::string& email, int idHospede)
    : Cliente(nome, cpf, telefone, email), idHospede(idHospede) {}

int Hospede::getIdHospede() const {
    return idHospede;
}

void Hospede::setIdHospede(int id) {
    idHospede = id;
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
    ss << Cliente::paraCSV() << "," << idHospede;
    return ss.str();
}


Hospede Hospede::fromCSV(const std::string& csv) {
    std::stringstream ss(csv);
    std::string nome, cpf, telefone, email, idStr;

    getline(ss, nome, ',');
    getline(ss, cpf, ',');
    getline(ss, telefone, ',');
    getline(ss, email, ',');
    getline(ss, idStr, ',');

    int id = 0;

    try {
        id = std::stoi(idStr);
    } catch (const std::invalid_argument& e) {
        std::cerr << "argumento invalido id: " << e.what() << '\n';
        
    } catch (const std::out_of_range& e) {
        std::cerr << "valor invalido id: " << e.what() << '\n';
        
    }

    return Hospede(nome, cpf, telefone, email, id);
}
