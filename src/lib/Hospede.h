#ifndef HOSPEDE_H
#define HOSPEDE_H

#include "Pessoa.h"
#include "Avaliacao.h"
#include "Cliente.h"
#include "Reserva.h"
#include "Avaliacao.h" 
#include <sstream>
#include <string>
#include <vector>
class Reserva;

class Hospede : public Cliente {
private:
    int idHospede;
    std::vector<Reserva> reservas;
    std::vector<Avaliacoes> avaliacoes;

public:
    Hospede(const std::string& nome, const std::string& cpf, const std::string& telefone, const std::string& email, int idHospede);
    virtual ~Hospede() = default;

    int getIdHospede() const;
    void setIdHospede(int id);

    void addReserva(const Reserva& reserva);
    std::vector<Reserva> getReservas() const;

    void addAvaliacao(const Avaliacoes& avaliacao);
    std::vector<Avaliacoes> getAvaliacoes() const;

    std::string paraCSV() const override;
    static Hospede fromCSV(const std::string& csv);
};

#endif // HOSPEDE_H
