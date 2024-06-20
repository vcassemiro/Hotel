#include "Reserva.h"
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
Reserva::Reserva(const std::string& dtCheckIN, const std::string& dtCheckOUT, Hospede* hospede, Quarto* quarto, double valor, const std::vector<Servico>& servicos, const std::vector<Pagamento>& pagamentos, int idReserva, int idHospede, int idQuarto, int idHotel)
    : dtCheckIN(dtCheckIN), dtCheckOUT(dtCheckOUT), hospede(hospede), quarto(quarto), valor(valor), servicos(servicos), pagamentos(pagamentos), idReserva(idReserva), idHospede(idHospede), idQuarto(idQuarto), idHotel(idHotel) {
}
// Getters and Setters
const string& Reserva::getDtCheckIN() const {
    return dtCheckIN;
}

void Reserva::setDtCheckIN(const string& dt) {
    dtCheckIN = dt;
}

const string& Reserva::getDtCheckOUT() const {
    return dtCheckOUT;
}

void Reserva::setDtCheckOUT(const string& dt) {
    dtCheckOUT = dt;
}

Hospede* Reserva::getHospede() const {
    return hospede;
}

void Reserva::setHospede(Hospede* h) {
    hospede = h;
}

Quarto* Reserva::getQuarto() const {
    return quarto;
}

void Reserva::setQuarto(Quarto* q) {
    quarto = q;
}

double Reserva::getValor() const {
    return valor;
}

void Reserva::setValor(double v) {
    valor = v;
}

void Reserva::addServico(const Servico& servico) {
    servicos.push_back(servico);
}

const vector<Servico>& Reserva::getServicos() const {
    return servicos;
}

void Reserva::addPagamento(const Pagamento& pagamento) {
    pagamentos.push_back(pagamento);
}

const vector<Pagamento>& Reserva::getPagamentos() const {
    return pagamentos;
}

int Reserva::getIdReserva() const {
    return idReserva;
}

void Reserva::setIdReserva(int id) {
    idReserva = id;
}

int Reserva::getIdHospede() const {
    return idHospede;
}

void Reserva::setIdHospede(int id) {
    idHospede = id;
}

int Reserva::getIdQuarto() const {
    return idQuarto;
}

void Reserva::setIdQuarto(int id) {
    idQuarto = id;
}

int Reserva::getIdHotel() const {
    return idHotel;
}

void Reserva::setIdHotel(int id) {
    idHotel = id;
}


string Reserva::paraCSV() const {
    stringstream ss;
    ss << dtCheckIN << "," << dtCheckOUT << "," << idHospede << "," << idQuarto << "," << valor << "," << idReserva << "," << idHotel;
    for (const auto& servico : servicos) {
        ss << "," << servico.paraCSV();
    }
    for (const auto& pagamento : pagamentos) {
        ss << "," << pagamento.paraCSV();
    }
    return ss.str();
}


Reserva Reserva::fromCSV(const std::string& csv) {
    std::stringstream ss(csv);
    std::string dtCheckIN, dtCheckOUT, idHospedeStr, idQuartoStr, valorStr, idReservaStr, idHotelStr;
    
    std::getline(ss, dtCheckIN, ',');
    std::getline(ss, dtCheckOUT, ',');
    std::getline(ss, idHospedeStr, ',');
    std::getline(ss, idQuartoStr, ',');
    std::getline(ss, valorStr, ',');
    std::getline(ss, idReservaStr, ',');
    std::getline(ss, idHotelStr, ',');

    int idHospede = 0;
    int idQuarto = 0;
    double valor = 0.0;
    int idReserva = 0;
    int idHotel = 0;

    try {
        idHospede = std::stoi(idHospedeStr);
        idQuarto = std::stoi(idQuartoStr);
        valor = std::stod(valorStr);
        idReserva = std::stoi(idReservaStr);
        idHotel = std::stoi(idHotelStr);
    } catch (const std::invalid_argument& e) {
        std::cerr << "argumento invalido : " << e.what() << '\n';
        
    } catch (const std::out_of_range& e) {
        std::cerr << "argumento invalido: " << e.what() << '\n';
        
    }

    
    std::vector<Servico> servicos;
    std::vector<Pagamento> pagamentos;

   

    return Reserva(dtCheckIN, dtCheckOUT, nullptr, nullptr, valor, servicos, pagamentos, idReserva, idHospede, idQuarto, idHotel);
}

Reserva* Reserva::getReservaById(const vector<Reserva*>& reservas, int id) {
    for (const auto& reserva : reservas) {
        if (reserva->getIdReserva() == id) {
            return reserva;
        }
    }
    return nullptr;
}