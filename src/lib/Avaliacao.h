#ifndef AVALIACOES_H
#define AVALIACOES_H

#include <iostream>
#include <string>
#include "Hospede.h"
#include "Reserva.h"

class Avaliacoes {
private:
    std::string comentario;
    int nota;
    Hospede& hospede;
    Reserva& reserva;

public:
    Avaliacoes(const std::string& comentario, int nota, Hospede& hospede, Reserva& reserva);
    ~Avaliacoes();

    // Getters e Setters...
    std::string getComentario() const;
    void setComentario(const std::string& comentario);
    
    int getNota() const;
    void setNota(int nota);
    
    Hospede& getHospede() const;
    Reserva& getReserva() const;

    // Método para CSV
    std::string paraCSV() const;
    static Avaliacoes fromCSV(const std::string& csv);
};

#endif // AVALIACOES_H




