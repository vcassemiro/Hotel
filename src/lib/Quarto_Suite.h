#ifndef QUARTO_SUITE_H
#define QUARTO_SUITE_H

#include "Quarto.h"
#include <vector>
#include <string>

class Quarto_Suite : public Quarto {
public:
    Quarto_Suite(int idQuarto, int idHotel, double preco, bool disponivel)
        : Quarto(idQuarto, idHotel, "Suite", preco, disponivel) {}

    

private:
   
};

#endif // QUARTO_SUITE_H