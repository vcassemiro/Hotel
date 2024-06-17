#include "Quarto.h"
#include "Reserva.h"
#include <sstream>
#include <stdexcept> // Para std::invalid_argument


    Quarto::Quarto(int idQuarto, int idHotel, const std::string& tipo, double preco, bool disponivel) :
     idQuarto(idQuarto), idHotel(idHotel), tipo(tipo), preco(preco), disponivel(disponivel)
    {
        // Add any additional initialization code here if needed
    }
       

    
// Destrutor
Quarto::~Quarto() {
    // Aqui você pode adicionar código para limpar recursos alocados dinamicamente, se necessário
}

// Métodos para gerenciar reservas
void Quarto::addReserva(const Reserva& reserva) {
    reservas.push_back(reserva);
}

const std::vector<Reserva>& Quarto::getReservas() const {
    return reservas;
}

// Métodos para gerenciar hóspedes
void Quarto::addHospede(const Hospede& hospede) {
    hospedes.push_back(hospede);
}

const std::vector<Hospede>& Quarto::getHospedes() const {
    return hospedes;
}

// Métodos para gerenciar serviços
void Quarto::addServico(const Servico& servico) {
    servicos.push_back(servico);
}

const std::vector<Servico>& Quarto::getServicos() const {
    return servicos;
}

// Método para converter informações do quarto em formato CSV
Quarto Quarto::fromCSV(const std::string& csv) {
    std::istringstream iss(csv);
    std::string token;
    int idQ, idH;
    std::string t;
    double p;
    bool d;

    // Lê cada parte do CSV usando getline e converte para os tipos apropriados
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
