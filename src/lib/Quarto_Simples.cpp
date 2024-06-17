#include "Quarto_Simples.h"

// Construtor
Quarto_Simples::Quarto_Simples(int idQuarto, int idHotel, double preco, bool disponivel)
: Quarto(idQuarto, idHotel, "Simples", preco, disponivel) {}

// Destrutor
Quarto_Simples::~Quarto_Simples() {}
