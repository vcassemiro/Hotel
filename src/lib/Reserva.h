#ifndef RESERVA_H
#define RESERVA_H

#include <string>
#include <vector>
#include "Hospede.h"
#include "Servico.h"
#include "Pagamento.h"
using namespace std;

class Quarto;  
class Hospede;
class Reserva {
public:
    Reserva(const std::string& dtCheckIN, const std::string& dtCheckOUT, Hospede* hospede, Quarto* quarto, double valor, const std::vector<Servico>& servicos, const std::vector<Pagamento>& pagamentos, int idReserva, int idHospede, int idQuarto, int idHotel);

    Quarto* getQuarto() const;
    void setQuarto(Quarto* q);

    const string& getDtCheckIN() const;
    void setDtCheckIN(const string& dt);

    const string& getDtCheckOUT() const;
    void setDtCheckOUT(const string& dt);

    Hospede* getHospede() const;
    void setHospede(Hospede* h);

    double getValor() const;
    void setValor(double v);

    void addServico(const Servico& servico);
    const vector<Servico>& getServicos() const;

    void addPagamento(const Pagamento& pagamento);
    const vector<Pagamento>& getPagamentos() const;

    int getIdReserva() const;
    void setIdReserva(int id);

    int getIdHospede() const;
    void setIdHospede(int id);

    int getIdQuarto() const;
    void setIdQuarto(int id);

    int getIdHotel() const;
    void setIdHotel(int id);

    string paraCSV() const;
    static Reserva fromCSV(const string& csv);

    static Reserva* getReservaById(const vector<Reserva*>& reservas, int id);

private:
    string dtCheckIN;
    string dtCheckOUT;
    Hospede* hospede;
    Quarto* quarto;
    double valor;
    vector<Servico> servicos;
    vector<Pagamento> pagamentos;
    int idReserva;
    int idHospede;
    int idQuarto;
    int idHotel;
};

#endif // RESERVA_H
