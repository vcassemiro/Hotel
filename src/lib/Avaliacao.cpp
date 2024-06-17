

#include <string>
#include "Hospede.h"
#include "Reserva.h"
#include <sstream>

Avaliacoes::Avaliacoes(const std::string& comentario, int nota, Hospede& hospede, Reserva& reserva)
    : comentario(comentario), nota(nota), hospede(hospede), reserva(reserva) {
}

Avaliacoes::~Avaliacoes() {
}

std::string Avaliacoes::getComentario() const {
    return comentario;
}

void Avaliacoes::setComentario(const std::string& comentario) {
    this->comentario = comentario;
}

int Avaliacoes::getNota() const {
    return nota;
}

void Avaliacoes::setNota(int nota) {
    this->nota = nota;
}

Hospede& Avaliacoes::getHospede() const {
    return hospede;
}

Reserva& Avaliacoes::getReserva() const {
    return reserva;
}

std::string Avaliacoes::paraCSV() const {
    std::string csv;
    // Convert Avaliacoes object to CSV string
    // Append comentario
    csv += comentario + ",";
    // Append nota
    csv += std::to_string(nota) + ",";
    // Append hospede name
    csv += hospede.getNome() + ",";
    // Append reserva details
    //csv += reserva.getDetalhes() + ",";
    // Remove the last comma
    csv.pop_back();
    return csv;
}

Avaliacoes Avaliacoes::fromCSV(const std::string& csv) {
    // Implementation for creating Avaliacoes object from CSV string
    // ...
    // Split the CSV string into individual values
    std::vector<std::string> values;
    std::istringstream ss(csv); // Use std::istringstream instead of std::stringstream
    std::string token;
    while (std::getline(ss, token, ',')) {
        values.push_back(token);
    }
    
    // Create Avaliacoes object using the values
    std::string comentario = values[0];
    int nota = std::stoi(values[1]);
    std::string hospedeCSV = values[2];
    std::string reservaCSV = values[3];
    
    Hospede hospede = Hospede::fromCSV(hospedeCSV); // Use the fromCSV method to create a Hospede instance
    Reserva reserva = Reserva::fromCSV(reservaCSV); // Use the fromCSV method to create a Reserva instance
    
    Avaliacoes avaliacoes(comentario, nota, hospede, reserva);
    
    return avaliacoes;
    }
