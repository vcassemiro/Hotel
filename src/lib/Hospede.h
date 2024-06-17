#ifndef HOSPEDE_H
#define HOSPEDE_H

#include "Cliente.h"
#include "Reserva.h"
#include "Avaliacao.h"
#include <string>
#include <vector>

class Hospede : public Cliente {
private:
    std::string email;
    std::vector<Reserva> reservas;
    std::vector<Avaliacoes> avaliacoes;

public:
    Hospede(const std::string& nome, const std::string& email, const std::string& telefone);
    virtual ~Hospede() = default;

    // Getters and Setters
    std::string getEmail() const;
    void setEmail(const std::string& email);

    void addReserva(const Reserva& reserva);
    std::vector<Reserva> getReservas() const;

    void addAvaliacao(const Avaliacoes& avaliacao);
    std::vector<Avaliacoes> getAvaliacoes() const;

    // Método para CSV
    std::string paraCSV() const;
    static Hospede fromCSV(const std::string& csv);
};

#endif // HOSPEDE_H
