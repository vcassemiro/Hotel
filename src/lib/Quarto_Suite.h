#ifndef QUARTO_SUITE_H
#define QUARTO_SUITE_H

#include <iostream>
#include <string>
#include "Quarto.h"

using std::string;
using std::cout;
using std::endl;

class Quarto_Suite : public Quarto {
public:
    Quarto_Suite(int idQuarto, int idHotel, double preco, bool disponivel);
    ~Quarto_Suite();
};

#endif // QUARTO_SUITE_H
