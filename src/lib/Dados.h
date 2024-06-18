#ifndef DADOS_H
#define DADOS_H

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

class Dados {
private:
    std::string fileName;
public:
    Dados(const std::string& fileName);
    ~Dados();
    
    std::vector<Quarto> carregarQuartos();
    std::vector<Hospede> carregarHospedes();
    std::vector<Reserva> carregarReservas();
    std::vector<Pagamento> carregarPagamentos();
    std::vector<Avaliacoes> carregarAvaliacoes();

    void salvarQuartos(const std::vector<Quarto>& quartos);
    void salvarHospedes(const std::vector<Hospede>& hospedes);
    void salvarReservas(const std::vector<Reserva>& reservas);
    void salvarPagamentos(const std::vector<Pagamento>& pagamentos);
    void salvarAvaliacoes(const std::vector<Avaliacoes>& avaliacoes);
};

#endif // DADOS_H
