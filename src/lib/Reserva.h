#ifndef RESERVA_H
#define RESERVA_H

#include <string>
#include <vector>
#include "Hospede.h"
#include "Quarto.h"
#include "Servico.h"
#include "Pagamento.h"

class Reserva {
private:
    std::string dtCheckIN;
    std::string dtCheckOUT;
    Hospede* hospede;
    Quarto* quarto;
    double valor;
    std::vector<Servico> servicos;
    std::vector<Pagamento> pagamentos;

public:
    Reserva(const std::string& dtCheckIN, const std::string& dtCheckOUT, Hospede* hospede, Quarto* quarto, double valor);
    virtual ~Reserva(); // Destrutor virtual para permitir polimorfismo

    // Getters e Setters
    const std::string& getDtCheckIN() const { return dtCheckIN; }
    void setDtCheckIN(const std::string& dt) { dtCheckIN = dt; }

    const std::string& getDtCheckOUT() const { return dtCheckOUT; }
    void setDtCheckOUT(const std::string& dt) { dtCheckOUT = dt; }

    Hospede* getHospede() const { return hospede; }
    void setHospede(Hospede* h) { hospede = h; }

    Quarto* getQuarto() const { return quarto; }
    void setQuarto(Quarto* q) { quarto = q; }

    double getValor() const { return valor; }
    void setValor(double v) { valor = v; }

    // Métodos para gerenciar serviços
    void addServico(const Servico& servico);
    const std::vector<Servico>& getServicos() const;

    // Métodos para gerenciar pagamentos
    void addPagamento(const Pagamento& pagamento);
    const std::vector<Pagamento>& getPagamentos() const;

    // Método para converter informações da reserva em formato CSV
    std::string paraCSV() const;
    static Reserva fromCSV(const std::string& csv);
};

#endif // RESERVA_H
