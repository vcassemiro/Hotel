#ifndef QUARTO_LUXO_H
#define QUARTO_LUXO_H

#include "Quarto.h"
#include <vector>
#include <string>

class Quarto_Luxo : public Quarto {
public:
    Quarto_Luxo(int idQuarto, int idHotel, double preco, bool disponivel)
        : Quarto(idQuarto, idHotel, "Luxo", preco, disponivel) {}

    

private:
   
};

#endif // QUARTO_LUXO_H