#ifndef PESSOA_H
#define PESSOA_H

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



class Pessoa {
protected:
    std::string nome;
    std::string cpf;
    std::string telefone;

public:
    Pessoa(const std::string& nome, const std::string& cpf, const std::string& telefone);
    virtual ~Pessoa();

    std::string getNome() const;
    void setNome(const std::string& nome);

    std::string getCpf() const;
    void setCpf(const std::string& cpf);

    std::string getTelefone() const;
    void setTelefone(const std::string& telefone);

    std::string paraCSV() const;
    static Pessoa fromCSV(const std::string& csv);
};


#endif // PESSOA_H
