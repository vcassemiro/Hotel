#include "Reserva.h"
#include <sstream>

// Construtor
Reserva::Reserva(const std::string& dtCheckIN, const std::string& dtCheckOUT, Hospede* hosp, Quarto* quart, double val)
    : dtCheckIN(dtCheckIN), dtCheckOUT(dtCheckOUT), hospede(hosp), quarto(quart), valor(val) {}

// Métodos para gerenciar serviços
void Reserva::addServico(const Servico& servico) {
    servicos.push_back(servico);
}

const std::vector<Servico>& Reserva::getServicos() const {
    return servicos;
}

// Métodos para gerenciar pagamentos
void Reserva::addPagamento(const Pagamento& pagamento) {
    pagamentos.push_back(pagamento);
}

const std::vector<Pagamento>& Reserva::getPagamentos() const {
    return pagamentos;
}

// Método para converter informações da reserva em formato CSV
std::string Reserva::paraCSV() const {
    std::stringstream ss;
    
    ss << dtCheckIN << "," << dtCheckOUT << "," << hospede->paraCSV() << "," << quarto->paraCSV() << "," << valor;

    // Implementar lógica para converter servicos e pagamentos para CSV, se necessário

    return ss.str();
}

// Método para criar um objeto Reserva a partir de uma string CSV
Reserva Reserva::fromCSV(const std::string& csv) {
    std::istringstream iss(csv);
    std::string token;

    std::string dtCheckIN, dtCheckOUT;
    std::getline(iss, dtCheckIN, ',');
    std::getline(iss, dtCheckOUT, ',');

    // Exemplo de como seria a implementação (assumindo que Hospede e Quarto tenham métodos fromCSV)
    Hospede* hospede = Hospede::fromCSV(iss.str()); // Implementação de exemplo; pode variar conforme necessário
    Quarto* quarto = Quarto::fromCSV(iss.str()); // Implementação de exemplo; pode variar conforme necessário

    double valor;
    iss >> valor; // Supondo que o valor seja o próximo campo no CSV

    return Reserva(dtCheckIN, dtCheckOUT, hospede, quarto, valor);
}
