#include "Hospede.h"
#include <sstream>

// Constructor
Hospede::Hospede( const std::string& nome, const std::string& email, const std::string& telefone)
: Cliente(nome, "", telefone, ""), email(email) {}

// Getters and Setters
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

// Método para CSV
std::string Hospede::paraCSV() const {
    std::stringstream ss;
    ss << "," << getNome() << "," << getEmail() << "," << getTelefone();
    return ss.str();
}

// Method to create a Hospede object from a CSV string
Hospede Hospede::fromCSV(const std::string& csv) {
    std::stringstream ss(csv);
    std::string nome, email, telefone;
    std::getline(ss, nome, ',');
    std::getline(ss, email, ',');
    std::getline(ss, telefone, ',');
    return Hospede(nome, email, telefone);
}
