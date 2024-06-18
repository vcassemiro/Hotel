#include <iostream>
#include <vector>
#include "Dados.h"
#include "Quarto.h"

void testListarQuartos() {
    // Create a Dados object and populate it with some sample data
    Dados dados;
    std::vector<Quarto> quartos;
    quartos.push_back(Quarto(1, 1, 100.0, true));
    quartos.push_back(Quarto(2, 1, 150.0, false));
    quartos.push_back(Quarto(3, 2, 200.0, true));
    dados.salvarQuartos(quartos);

    // Call the listarQuartos function
    listarQuartos(dados);
}

int main() {
    testListarQuartos();
    return 0;
}