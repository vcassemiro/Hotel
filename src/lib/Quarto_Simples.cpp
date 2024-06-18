
#include "Pessoa.h"
#include "Avaliacao.h"
#include "Cliente.h"
#include "Hospede.h"
#include "Hotel.h"
#include "Pagamento.h"
#include "Quarto.h"
#include "Quarto_Luxo.h"
#include "Quarto_Simples.h"
#include "Quarto_Suite.h"
#include "Reserva.h"
#include "Dados.h"
#include "Servico.h"

#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


Quarto_Simples::Quarto_Simples(int idQuarto, int idHotel, double preco, bool disponivel)
: Quarto(idQuarto, idHotel, "Simples", preco, disponivel) {}

Quarto_Simples::~Quarto_Simples() {}
