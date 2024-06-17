#ifndef QUARTO_H
#define QUARTO_H

#include <string>
#include <vector>
#include "Reserva.h"
#include "Hospede.h"
#include "Servico.h"

class Quarto {
private:
    int idQuarto;
    int idHotel;
    std::string tipo;
    double preco;
    bool disponivel;
    std::vector<Reserva> reservas;
    std::vector<Hospede> hospedes;
    std::vector<Servico> servicos;

public:
    Quarto(int idQuarto, int idHotel, const std::string& tipo, double preco, bool disponivel);
    ~Quarto();

    // Getters e Setters
    int getIdQuarto() const { return idQuarto; }
    void setIdQuarto(int val) { idQuarto = val; }

    int getIdHotel() const { return idHotel; }
    void setIdHotel(int val) { idHotel = val; }

    const std::string& getTipo() const { return tipo; }
    void setTipo(const std::string& val) { tipo = val; }

    double getPreco() const { return preco; }
    void setPreco(double val) { preco = val; }

    bool isDisponivel() const { return disponivel; }
    void setDisponivel(bool val) { disponivel = val; }

    // Métodos para gerenciar reservas
    void addReserva(const Reserva& reserva);
    const std::vector<Reserva>& getReservas() const { return reservas; }

    // Métodos para gerenciar hóspedes
    void addHospede(const Hospede& hospede);
    const std::vector<Hospede>& getHospedes() const { return hospedes; }

    // Métodos para gerenciar serviços
    void addServico(const Servico& servico);
    const std::vector<Servico>& getServicos() const { return servicos; }

    // Métodos para CSV
    std::string paraCSV() const;
    static Quarto fromCSV(const std::string& csv);
};

#endif // QUARTO_H
