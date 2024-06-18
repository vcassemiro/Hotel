#ifndef HOTEL_H
#define HOTEL_H

#include "Pessoa.h"
#include "Avaliacao.h"
#include "Cliente.h"
#include "Hospede.h"
#include "Pagamento.h"
#include "Quarto.h"
#include "Quarto_Luxo.h"
#include "Quarto_Simples.h"
#include "Quarto_Suite.h"
#include "Reserva.h"
#include "Servico.h"

#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Hotel {
private:
    int idHotel;
    std::string nome;
    std::string endereco;
    std::vector<Quarto> quartos;
    std::vector<Hospede> hospedes;
    std::vector<Avaliacoes> avaliacoes;
    std::vector<Pagamento> pagamentos;

public:
    Hotel(int idHotel, const std::string& nome, const std::string& endereco);
    ~Hotel();

    void addQuarto(const Quarto& quarto);
    std::vector<Quarto> getQuartos() const;

    void addHospede(const Hospede& hospede);
    std::vector<Hospede> getHospedes() const;

    void addAvaliacao(const Avaliacoes& avaliacao);
    std::vector<Avaliacoes> getAvaliacoes() const;

    void addPagamento(const Pagamento& pagamento);
    std::vector<Pagamento> getPagamentos() const;

    void salvarEmCSV(const std::string& nomeArquivo) const;
};

#endif // HOTEL_H
