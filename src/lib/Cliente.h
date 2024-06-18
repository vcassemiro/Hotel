#ifndef CLIENTE_H
#define CLIENTE_H

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

class Cliente : public Pessoa {
private:
    std::string email;

public:
    Cliente(const std::string& nome, const std::string& cpf, const std::string& telefone, const std::string& email);
    ~Cliente();

    std::string getEmail() const;
    void setEmail(const std::string& email);

    std::string paraCSV() const;
    static Cliente fromCSV(const std::string& csv);
};

#endif // CLIENTE_H