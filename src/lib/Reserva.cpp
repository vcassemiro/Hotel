#include "Reserva.h"
#include "Hospede.h" // Include the header file for Hospede class
#include "Quarto.h" // Include the header file for Quarto class
#include <sstream>

// Constructor
Reserva::Reserva(const std::string& dtCheckIN, const std::string& dtCheckOUT, Hospede* hospede, Quarto* quarto, double valor)
    : dtCheckIN(dtCheckIN), dtCheckOUT(dtCheckOUT), hospede(hospede), quarto(quarto), valor(valor) {}

// Destructor
Reserva::~Reserva() {}

// Getters and Setters
const std::string& Reserva::getDtCheckIN() const { return dtCheckIN; }
void Reserva::setDtCheckIN(const std::string& dt) { dtCheckIN = dt; }

const std::string& Reserva::getDtCheckOUT() const { return dtCheckOUT; }
void Reserva::setDtCheckOUT(const std::string& dt) { dtCheckOUT = dt; }

Hospede* Reserva::getHospede() const { return hospede; }
void Reserva::setHospede(Hospede* h) { hospede = h; }

Quarto* Reserva::getQuarto() const { return quarto; }
void Reserva::setQuarto(Quarto* q) { quarto = q; }

double Reserva::getValor() const { return valor; }
void Reserva::setValor(double v) { valor = v; }

// Methods to manage services
void Reserva::addServico(const Servico& servico) { servicos.push_back(servico); }
const std::vector<Servico>& Reserva::getServicos() const { return servicos; }

// Methods to manage payments
void Reserva::addPagamento(const Pagamento& pagamento) { pagamentos.push_back(pagamento); }
const std::vector<Pagamento>& Reserva::getPagamentos() const { return pagamentos; }


// Method to convert reservation information to CSV format
std::string Reserva::paraCSV() const {
    std::stringstream ss;
    ss << dtCheckIN << "," << dtCheckOUT << "," <<  "," << quarto->getIdQuarto() << "," << valor;
    
    // Convert servicos to CSV format
    for (const Servico& servico : servicos) {
        ss << "," << servico.getIdServico();
    }
    
    return ss.str();
}

// Method to create a Reserva object from a CSV string
Reserva Reserva::fromCSV(const std::string& csv) {
    std::stringstream ss(csv);
    std::string token;
    std::vector<std::string> tokens;
    
    // Split the CSV string by comma
    while (std::getline(ss, token, ',')) {
        tokens.push_back(token);
    }
    
    // Create a new Reserva object using the extracted information
    Reserva reserva(tokens[0], tokens[1], nullptr, nullptr, std::stod(tokens[4]));
    
    // Set the Hospede and Quarto objects using their IDs
    Hospede* hospede = getHospedeById(tokens[2]);
    Quarto* quarto = getQuartoByNumero(tokens[3]);
    reserva.setHospede(hospede);
    reserva.setQuarto(quarto);
    
    // Add servicos to the Reserva object
    for (size_t i = 5; i < tokens.size(); i++) {
        Servico* servico = getServicoById(tokens[i]);
        if (servico != nullptr) {
            reserva.addServico(*servico);
        }
    }
    
    return reserva;
}

// Define the member functions or methods for the classes Hospede, Quarto, Servico, and Pagamento
// ...

// Define the functions getHospedeById, getQuartoByNumero, and getServicoById
Hospede* getHospedeById(const std::string& id) {
    // Implementation here
    return nullptr;
}

Quarto* getQuartoByNumero(const std::string& numero) {
    // Implementation here
    return nullptr;
}

Servico* getServicoById(const std::string& id) {
    // Implementation here
    return nullptr;
}