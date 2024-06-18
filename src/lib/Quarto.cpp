#include "Quarto.h"
#include <sstream>
#include "dados.h"



Quarto::Quarto(int idQuarto, int idHotel, const std::string& tipo, double preco, bool disponivel)
    : idQuarto(idQuarto), idHotel(idHotel), tipo(tipo), preco(preco), disponivel(disponivel) {}

Quarto::~Quarto() {}

int Quarto::getIdQuarto() const { return idQuarto; }
void Quarto::setIdQuarto(int val) { idQuarto = val; }

int Quarto::getIdHotel() const { return idHotel; }
void Quarto::setIdHotel(int val) { idHotel = val; }

const std::string& Quarto::getTipo() const { return tipo; }
void Quarto::setTipo(const std::string& val) { tipo = val; }

double Quarto::getPreco() const { return preco; }
void Quarto::setPreco(double val) { preco = val; }

bool Quarto::isDisponivel() const { return disponivel; }
void Quarto::setDisponivel(bool val) { disponivel = val; }

void Quarto::addReserva(const Reserva& reserva) { reservas.push_back(reserva); }
const std::vector<Reserva>& Quarto::getReservas() const { return reservas; }

void Quarto::addHospede(const Hospede& hospede) { hospedes.push_back(hospede); }
const std::vector<Hospede>& Quarto::getHospedes() const { return hospedes; }

void Quarto::addServico(const Servico& servico) { servicos.push_back(servico); }
const std::vector<Servico>& Quarto::getServicos() const { return servicos; }

std::string Quarto::paraCSV() const {
    std::stringstream ss;
    ss << idQuarto << "," << idHotel << "," << tipo << "," << preco << "," << (disponivel ? "1" : "0");

    for (const auto& reserva : reservas) {
        ss << "," << reserva.getIdReserva();
    }
    for (const auto& hospede : hospedes) {
        ss << "," << hospede.getIdHospede();
    }
    for (const auto& servico : servicos) {
        ss << "," << servico.getIdServico();
    }
    return ss.str();
}

Quarto Quarto::fromCSV(const std::string& csv) {
    std::stringstream ss(csv);
    std::string idQuartoStr, idHotelStr, tipo, precoStr, disponivelStr;
    getline(ss, idQuartoStr, ',');
    getline(ss, idHotelStr, ',');
    getline(ss, tipo, ',');
    getline(ss, precoStr, ',');
    getline(ss, disponivelStr, ',');

    int idQuarto = std::stoi(idQuartoStr);
    int idHotel = std::stoi(idHotelStr);
    double preco = std::stod(precoStr);
    bool disponivel = (disponivelStr == "1");

    Quarto quarto(idQuarto, idHotel, tipo, preco, disponivel);

    std::string idStr;
    while (getline(ss, idStr, ',')) {
        int id = std::stoi(idStr);
       
        if (idStr.front() == 'R') {
            quarto.addReserva(dados.carregarReservas().at(id));
        } else if (idStr.front() == 'H') {
            quarto.addHospede(dados.carregarHospedes().at(id));
        } else if (idStr.front() == 'S') {
            quarto.addServico(dados.carregarServicos().at(id));
        }
    }
    return quarto;
}
