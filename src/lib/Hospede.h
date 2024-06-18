#ifndef HOSPEDE_H
#define HOSPEDE_H

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

class Hospede : public Cliente {
private:
    int idHospede;
    std::string email;
    std::vector<Reserva> reservas;
    std::vector<Avaliacoes> avaliacoes;

public:
    Hospede(const std::string& nome, const std::string& email, const std::string& telefone, int idHospede);
    virtual ~Hospede() = default;

    int getIdHospede() const {
        return idHospede;
    }

    void setIdHospede(int id) {
        idHospede = id;
    }

    std::string getEmail() const;
    void setEmail(const std::string& email);

    void addReserva(const Reserva& reserva);
    std::vector<Reserva> getReservas() const;

    void addAvaliacao(const Avaliacoes& avaliacao);
    std::vector<Avaliacoes> getAvaliacoes() const;

    std::string paraCSV() const;
    static Hospede fromCSV(const std::string& csv);
};


#endif // HOSPEDE_H
