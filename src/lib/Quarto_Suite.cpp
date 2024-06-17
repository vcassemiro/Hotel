#include "Quarto_Suite.h"

// Construtor
Quarto_Suite::Quarto_Suite(int idQuarto, int idHotel, double preco, bool disponivel)
: Quarto(idQuarto, idHotel, "Suite", preco, disponivel) {}

// Destrutor
Quarto_Suite::~Quarto_Suite() {}
