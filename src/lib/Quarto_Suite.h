#ifndef QUARTO_SUITE_H
#define QUARTO_SUITE_H

#include "Quarto.h"

#include <fstream>
#include <iostream>

using namespace std;

class Quarto_Suite : public Quarto {
public:
    Quarto_Suite(int idQuarto, int idHotel, double preco, bool disponivel);
    ~Quarto_Suite(); 
};

#endif // QUARTO_SUITE_H
