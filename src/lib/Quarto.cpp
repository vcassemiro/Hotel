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

    int idQuarto = 0;
    int idHotel = 0;
    double preco = 0.0;
    bool disponivel = (disponivelStr == "1");

    try {
        idQuarto = std::stoi(idQuartoStr);
    } catch (const std::invalid_argument& e) {
        std::cerr << "argumento invalido para idQuarto: " << e.what() << '\n';
        
    } catch (const std::out_of_range& e) {
        std::cerr << "valor invalido para  idQuarto: " << e.what() << '\n';
       
    }

    try {
        idHotel = std::stoi(idHotelStr);
    } catch (const std::invalid_argument& e) {
        std::cerr << "argumento invalido para  idHotel: " << e.what() << '\n';
        
    } catch (const std::out_of_range& e) {
        std::cerr << "valor invalido para idHotel: " << e.what() << '\n';
        
    }

    try {
        preco = std::stod(precoStr);
    } catch (const std::invalid_argument& e) {
        std::cerr << "argumento invalido para preco: " << e.what() << '\n';
        
    } catch (const std::out_of_range& e) {
        std::cerr << "argumento invalido para  preco: " << e.what() << '\n';
        
    }

    Quarto quarto(idQuarto, idHotel, tipo, preco, disponivel);

    std::string idStr;
    while (getline(ss, idStr, ',')) {
        try {
            int id = 0;
            if (!idStr.empty()) {
                id = std::stoi(idStr.substr(1)); 
            }
            if (idStr.front() == 'R') {
                quarto.addReserva(dados.carregarReservas().at(id));
            } else if (idStr.front() == 'H') {
                quarto.addHospede(dados.carregarHospedes().at(id));
            } else if (idStr.front() == 'S') {
                quarto.addServico(dados.carregarServicos().at(id));
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << "argumento invalido para  ID: " << e.what() << '\n';
            
        } catch (const std::out_of_range& e) {
            std::cerr << "argumento invalido para  ID: " << e.what() << '\n';
           
        }
    }
    
    return quarto;
}