#include "Hospede.h"
#include "Cliente.h"
#include <sstream>

// Construtor
Hospede::Hospede(const string& nome, const string& cpf, const string& telefone, const string& email)
: Cliente(nome, cpf, telefone), email(email) {}

// Getters e Setters...

void Hospede::addReserva(const Reserva& reserva) {
    reservas.push_back(reserva);
}

vector<Reserva> Hospede::getReservas() const {
    return reservas;
}

void Hospede::addAvaliacao(const Avaliacoes& avaliacao) {
    avaliacoes.push_back(avaliacao);
}

vector<Avaliacoes> Hospede::getAvaliacoes() const {
    return avaliacoes;
}

// Método para converter informações do hóspede em formato CSV
string Hospede::paraCSV() const {
    std::stringstream ss;
    
    ss << Cliente::paraCSV() << "," << email;

    // Implement logic to convert reservas and avaliacoes to CSV if necessary
    
    return ss.str();
}

// Método para criar um objeto Hospede a partir de uma string CSV
Hospede Hospede::fromCSV(const std::string& csv) {
    std::istringstream iss(csv);
    
    // Parse the CSV string properly including reservas and avaliacoes if they are part of the CSV
    
    // Example assuming that Cliente::fromCSV handles its part
    Cliente c = Cliente::fromCSV(iss(csv)); 
    std::string email;
    
    std::getline(iss, email, ',');
    
    Hospede h = Hospede(c.getNome(), c.getCpf(), c.getTelefone(), email);

    // Parse reservas and avaliacoes if they are part of the CSV
    
    return h;
}
