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
    Dados(const std::string &);
    std::vector<Pagamento> carregarPagamentos(void);
    std::vector<Avaliacoes> carregarAvaliacoes(void);
    std::vector<Quarto> carregarQuartos(void);
    std::vector<Hospede> carregarHospedes(void);
    std::vector<Reserva> carregarReservas(void);
    std::vector<Servico> carregarServicos(void);
    void salvarQuartos(const std::vector<Quarto> &);
    void salvarHospedes(const std::vector<Hospede> &);
    void salvarReservas(const std::vector<Reserva> &);
    void salvarPagamentos(const std::vector<Pagamento> &);
    void salvarAvaliacoes(const std::vector<Avaliacoes> &);
    void salvarServicos(const std::vector<Servico> &);

private:private:
    std::string fileName;
};
extern Dados dados;

#endif // DADOS_H


