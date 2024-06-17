#ifndef QUARTO_SIMPLES_H
#define QUARTO_SIMPLES_H

#include <iostream>
#include <string>
#include "Quarto.h"

using std::string;
using std::cout;
using std::endl;

class Quarto_Simples : public Quarto {
public:
    Quarto_Simples(int idQuarto, int idHotel, double preco, bool disponivel);
    ~Quarto_Simples();
};

#endif // QUARTO_SIMPLES_H
