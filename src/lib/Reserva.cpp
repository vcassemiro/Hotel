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



Reserva::Reserva(const std::string& dtCheckIN, const std::string& dtCheckOUT, Hospede* hospede, Quarto* quarto, double valor, const std::vector<Servico>& servicos, const std::vector<Pagamento>& pagamentos, int idReserva, int idHospede, int idQuarto, int idHotel)
    : dtCheckIN(dtCheckIN), dtCheckOUT(dtCheckOUT), hospede(hospede), quarto(quarto), valor(valor), idReserva(idReserva), idHospede(idHospede), idQuarto(idQuarto), idHotel(idHotel) {
    this->servicos = servicos;
    this->pagamentos = pagamentos;
}

Reserva::~Reserva() {}

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
void Reserva::addPagamento(const Pagamento& pagamento) { pagamentos.push_back(pagamento); }
const std::vector<Pagamento>& Reserva::getPagamentos() const { return pagamentos; }
const std::vector<Servico>& Reserva::getServicos() const { return servicos; }

void Reserva::addPagamento(const Pagamento& pagamento) { pagamentos.push_back(pagamento); }
const std::vector<Pagamento>& Reserva::getPagamentos() const { return pagamentos; }

std::string Reserva::paraCSV() const {
    std::stringstream ss;
    ss << dtCheckIN << "," << dtCheckOUT << "," <<  "," << quarto->getIdQuarto() << "," << valor;

    for (const Servico& servico : servicos) {
        ss << "," << servico.getIdServico();
    }
}
Reserva Reserva::fromCSV(const std::string& csv) {
    std::stringstream ss(csv);
    std::string dtCheckIN, dtCheckOUT;
    std::getline(ss, dtCheckIN, ',');
    std::getline(ss, dtCheckOUT, ',');
    int idReserva, idHospede, idQuarto, idHotel;
    double valor;
    ss >> idReserva >> idHospede >> idQuarto >> idHotel >> valor;


    Reserva reserva(dtCheckIN, dtCheckOUT, nullptr, nullptr, valor, {}, {}, idReserva, idHospede, idQuarto, idHotel);
    return reserva;
}

    void Reserva::addServico(const Servico& servico) {
    servicos.push_back(servico);
}


    const std::vector<Servico>& Reserva::getServicos() const {
    return servicos;}

