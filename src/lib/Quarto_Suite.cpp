#include "Quarto_Suite.h"
#include "Quarto.h"
#include <iostream>

using namespace std;

Quarto_Suite::Quarto_Suite(int idQuarto, int idHotel, double preco, bool disponivel)
    : Quarto(idQuarto, idHotel, "Suite", preco, disponivel) {}

Quarto_Suite::~Quarto_Suite() {
    cout << "Quarto Suite destruído" << endl;
}
