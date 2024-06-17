#ifndef QUARTO_LUXO_H
#define QUARTO_LUXO_H

#include <iostream>
#include <string>
#include "Quarto.h"

using std::string;
using std::cout;
using std::endl;

class Quarto_Luxo : public Quarto {
public:
    Quarto_Luxo(int idQuarto, int idHotel, double preco, bool disponivel);
    ~Quarto_Luxo();
};

#endif // QUARTO_LUXO_H
