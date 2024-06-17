#ifndef HOSPEDE_H
#define HOSPEDE_H

#include "Pessoa.h"
#include "Cliente.h"
#include "Reserva.h"
#include "Avaliacao.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Hospede : public Cliente {
private:
    string email;
    vector<Reserva> reservas;
    vector<Avaliacoes> avaliacoes; // Corrected type

public:
    Hospede(const string& nome, const string& cpf, const string& telefone, const string& email);
    virtual ~Hospede() = default; // Use default destructor

    // Getters e Setters...

    void addReserva(const Reserva& reserva);
    vector<Reserva> getReservas() const;

    void addAvaliacao(const Avaliacoes& avaliacao); // Corrected type
    vector<Avaliacoes> getAvaliacoes() const; // Corrected type

    // Método para CSV
    string paraCSV() const;
    static Hospede fromCSV(const std::string& csv);
};

#endif // HOSPEDE_H
