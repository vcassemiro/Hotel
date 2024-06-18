#ifndef HOTEL_H
#define HOTEL_H

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

class Hotel {
private:
    int idHotel;
    string nome;
    string endereco;
    vector<Quarto> quartos;
    vector<Hospede> hospedes;
    vector<Avaliacoes> avaliacoes;
    vector<Pagamento> pagamentos;

public:
    Hotel(int idHotel, string nome, string endereco);
    ~Hotel();

    void addHospede(Hospede hospede);
    vector<Hospede> getHospedes();

    void addAvaliacao(Avaliacoes avaliacao);
    vector<Avaliacoes> getAvaliacoes();

    void addPagamento(Pagamento pagamento);
    vector<Pagamento> getPagamentos();

    void salvarEmCSV(const string& nomeArquivo);
};

#endif // HOTEL_H
