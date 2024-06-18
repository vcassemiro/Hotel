#ifndef RESERVA_H
#define RESERVA_H

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

class Reserva {
public:
    Reserva(const std::string& dtCheckIN, const std::string& dtCheckOUT, Hospede* hospede, Quarto* quarto, double valor, const std::vector<Servico>& servicos, const std::vector<Pagamento>& pagamentos, int idReserva, int idHospede, int idQuarto, int idHotel)
        : dtCheckIN(dtCheckIN), dtCheckOUT(dtCheckOUT), hospede(hospede), quarto(quarto), valor(valor), servicos(servicos), pagamentos(pagamentos), idReserva(idReserva), idHospede(idHospede), idQuarto(idQuarto), idHotel(idHotel) {}

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

    void addServico(const Servico& servico);
    const std::vector<Servico>& getServicos() const;

    void addPagamento(const Pagamento& pagamento);
    const std::vector<Pagamento>& getPagamentos() const;

    void addServico(const Servico& servico); 
    
    const std::vector<Servico>& getServicos() const;

    int getIdReserva() const;
    void setIdReserva(int id);

    int getIdHospede() const;
    void setIdHospede(int id);

    int getIdQuarto() const;
    void setIdQuarto(int id);

    int getIdHotel() const;
    void setIdHotel(int id);
    

    std::string paraCSV() const;
    static Reserva fromCSV(const std::string& csv);

private:
    std::string dtCheckIN;
    std::string dtCheckOUT;
    Hospede* hospede;
    Quarto* quarto;
    double valor;
    std::vector<Servico> servicos;
    std::vector<Pagamento> pagamentos;
    int idReserva;
    int idHospede;
    int idQuarto; 
    int idHotel; 
};




#endif // RESERVA_H

