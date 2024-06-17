#include "Quarto_Luxo.h"

// Construtor
Quarto_Luxo::Quarto_Luxo(int idQuarto, int idHotel, double preco, bool disponivel)
: Quarto(idQuarto, idHotel, "Luxo", preco, disponivel) {}

// Destrutor
Quarto_Luxo::~Quarto_Luxo() {}
