#ifndef QUARTO_SIMPLES_H
#define QUARTO_SIMPLES_H

#include "Quarto.h"
#include <vector>
#include <string>

class Quarto_Simples : public Quarto {
public:
    Quarto_Simples(int idQuarto, int idHotel, double preco, bool disponivel)
        : Quarto(idQuarto, idHotel, "Simples", preco, disponivel) {}

    

private:
   
};

#endif // QUARTO_SIMPLES_H