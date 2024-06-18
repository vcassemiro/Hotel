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

#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

Pagamento::Pagamento(double valor, const std::string& metodo, const std::string& data)
: valor(valor), metodo(metodo), data(data) {
}

Pagamento::~Pagamento() {
}

std::string Pagamento::paraCSV() const {
    std::stringstream ss;

    ss << std::fixed << std::setprecision(2) << valor << "," << metodo << ",";


    return ss.str();
}

Pagamento Pagamento::fromCSV(const std::string& csv) {
    std::istringstream iss(csv);

    double valor;
    std::string metodo;
    string data;

   
    return Pagamento(valor, metodo, data);
}
