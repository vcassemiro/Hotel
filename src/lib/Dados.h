#ifndef DADOS_H
#define DADOS_H

#include <vector>
#include <string>
#include <fstream>
#include "Pagamento.h"
#include "Avaliacao.h"
#include "Quarto.h"
#include "Hospede.h"
#include "Reserva.h"


class Dados {
public:
    Dados(const std::string& fileName);

    std::vector<Pagamento> carregarPagamentos();
    std::vector<Avaliacoes> carregarAvaliacoes();
    std::vector<Quarto> carregarQuartos();
    std::vector<Hospede> carregarHospedes();
    std::vector<Reserva> carregarReservas();
    std::vector<Servico> carregarServicos();

    void salvarQuartos(const std::vector<Quarto>& quartos);
    void salvarHospedes(const std::vector<Hospede>& hospedes);
    void salvarReservas(const std::vector<Reserva>& reservas);
    void salvarPagamentos(const std::vector<Pagamento>& pagamentos);
    void salvarAvaliacoes(const std::vector<Avaliacoes>& avaliacoes);

private:
    std::string fileName;
};
extern Dados dados;

#endif // DADOS_H

