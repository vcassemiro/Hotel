#ifndef QUARTO_H
#define QUARTO_H


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
#include "Servico.h"

#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Quarto {
private:
    int idQuarto;
    int idHotel;
    std::string tipo;
    double preco;
    bool disponivel;
    std::vector<Reserva> reservas;
    std::vector<Hospede> hospedes;
    std::vector<Servico> servicos;

public:
    Quarto(int idQuarto, int idHotel, const std::string& tipo, double preco, bool disponivel);
    ~Quarto();

    int getIdQuarto() const { return idQuarto; }
    void setIdQuarto(int val) { idQuarto = val; }

    int getIdHotel() const { return idHotel; }
    void setIdHotel(int val) { idHotel = val; }

    const std::string& getTipo() const { return tipo; }
    void setTipo(const std::string& val) { tipo = val; }

    double getPreco() const { return preco; }
    void setPreco(double val) { preco = val; }

    bool isDisponivel() const { return disponivel; }
    void setDisponivel(bool val) { disponivel = val; }

    void addReserva(const Reserva& reserva);
    const std::vector<Reserva>& getReservas() const { return reservas; }

    void addHospede(const Hospede& hospede);
    const std::vector<Hospede>& getHospedes() const { return hospedes; }

    void addServico(const Servico& servico);
    const std::vector<Servico>& getServicos() const { return servicos; }

    std::string paraCSV() const;
    static Quarto fromCSV(const std::string& csv);
};

#endif  // QUARTO_H