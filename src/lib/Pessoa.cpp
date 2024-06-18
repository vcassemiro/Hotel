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

Pessoa::Pessoa(const std::string& nome, const std::string& cpf, const std::string& telefone)
: nome(nome), cpf(cpf), telefone(telefone) {
}

Pessoa::~Pessoa() {
    std::cout << "Destruindo o Objeto Pessoa" << std::endl;
}

std::string Pessoa::getNome() const {
    return nome;
}

void Pessoa::setNome(const std::string& novoNome) {
    nome = novoNome;
}

std::string Pessoa::getCpf() const {
    return cpf;
}

void Pessoa::setCpf(const std::string& novoCpf) {
    cpf = novoCpf;
}

std::string Pessoa::getTelefone() const {
    return telefone;
}

void Pessoa::setTelefone(const std::string& novoTelefone) {
    telefone = novoTelefone;
}

std::string Pessoa::paraCSV() const {
    std::stringstream ss;

    ss << nome << "," << cpf << "," << telefone;

    return ss.str();
}

Pessoa Pessoa::fromCSV(const std::string& csv) {
    std::istringstream iss(csv);

    std::string nome;
    std::string cpf;
    std::string telefone;

    std::getline(iss, nome, ',');
    std::getline(iss, cpf, ',');
    std::getline(iss, telefone, ',');

    return Pessoa(nome, cpf, telefone);
}
