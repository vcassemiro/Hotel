#ifndef QUARTO_H
#define QUARTO_H

#include <string>
#include <vector>
#include "Reserva.h"
#include "Hospede.h"
#include "dados.h"
#include "Servico.h"

class Quarto {
public:
    Quarto(int idQuarto, int idHotel, const std::string& tipo, double preco, bool disponivel);
    ~Quarto();

    int getIdQuarto() const;
    void setIdQuarto(int val);

    int getIdHotel() const;
    void setIdHotel(int val);

    const std::string& getTipo() const;
    void setTipo(const std::string& val);

    double getPreco() const;
    void setPreco(double val);

    bool isDisponivel() const;
    void setDisponivel(bool val);

    void addReserva(const Reserva& reserva);
    const std::vector<Reserva>& getReservas() const;

    void addHospede(const Hospede& hospede);
    const std::vector<Hospede>& getHospedes() const;

    void addServico(const Servico& servico);
    const std::vector<Servico>& getServicos() const;

    std::string paraCSV() const;
    static Quarto fromCSV(const std::string& csv);

private:
    int idQuarto;
    int idHotel;
    std::string tipo;
    double preco;
    bool disponivel;
    std::vector<Reserva> reservas;
    std::vector<Hospede> hospedes;
    std::vector<Servico> servicos;
};

#endif // QUARTO_H
