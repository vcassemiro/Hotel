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
    virtual ~Reserva(); // Virtual destructor to allow polymorphism

    // Getters and Setters
    const std::string& getDtCheckIN() const;
    void setDtCheckIN(const std::string& dt);

    const std::string& getDtCheckOUT() const;
    void setDtCheckOUT(const std::string& dt);

    Hospede* getHospede() const;
    void setHospede(Hospede* h);

    Quarto* getQuarto() const;
    void setQuarto(Quarto* q);

    double getValor() const;
    void setValor(double v);

    // Methods to manage services
    void addServico(const Servico& servico);
    const std::vector<Servico>& getServicos() const;

    // Methods to manage payments
    void addPagamento(const Pagamento& pagamento);
    const std::vector<Pagamento>& getPagamentos() const;

    // Method to convert reservation information to CSV format
    std::string paraCSV() const;
    static Reserva fromCSV(const std::string& csv);
};

#endif // RESERVA_H