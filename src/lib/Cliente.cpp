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


Cliente::Cliente(const std::string& nome, const std::string& cpf, const std::string& telefone, const std::string& email)
: Pessoa(nome, cpf, telefone), email(email) {
}

Cliente::~Cliente() {
    std::cout << "Destruindo o Objeto Cliente" << std::endl;
}

std::string Cliente::getEmail() const {
    return email;
}

void Cliente::setEmail(const std::string& novoEmail) {
    email = novoEmail;
}

std::string Cliente::paraCSV() const {
    std::stringstream ss;

    ss << Pessoa::paraCSV() << "," << email;

    return ss.str();
}

std::vector<Pagamento> Dados::carregarPagamentos() {
    std::vector<Pagamento> pagamentos;
    std::ifstream file(fileName);
    std::string line;

    while (std::getline(file, line)) {
        if (line.find("Pagamento") == 0) {
            pagamentos.push_back(Pagamento::fromCSV(line));
        }
    }

    return pagamentos;
}

std::vector<Avaliacoes> Dados::carregarAvaliacoes() {
    std::vector<Avaliacoes> avaliacoes;
    std::ifstream file(fileName);
    std::string line;

    while (std::getline(file, line)) {
        if (line.find("Avaliacao") == 0) {
            avaliacoes.push_back(Avaliacoes::fromCSV(line));
        }
    }

    return avaliacoes;
}

void Dados::salvarQuartos(const std::vector<Quarto>& quartos) {
    std::ofstream file(fileName, std::ios::app);

}

std::string Cliente::paraCSV() const {
}

std::vector<Pagamento> Dados::carregarPagamentos() {
    std::vector<Pagamento> pagamentos;
    std::ifstream file(fileName);
    std::string line;

    while (std::getline(file, line)) {
        if (line.find("Pagamento") == 0) {
            pagamentos.push_back(Pagamento::fromCSV(line));
        }
    }

    return pagamentos;
}

std::vector<Avaliacoes> Dados::carregarAvaliacoes() {
    std::vector<Avaliacoes> avaliacoes;
    std::ifstream file(fileName);
    std::string line;

    while (std::getline(file, line)) {
        if (line.find("Avaliacao") == 0) {
            avaliacoes.push_back(Avaliacoes::fromCSV(line));
        }
    }

    return avaliacoes;
}

void Dados::salvarQuartos(const std::vector<Quarto>& quartos) {
    std::ofstream file(fileName, std::ios::app);
    for (const auto& quarto : quartos) {
        file << "Quarto," << quarto.paraCSV() << std::endl;
    }
}

void Dados::salvarHospedes(const std::vector<Hospede>& hospedes) {
    std::ofstream file(fileName, std::ios::app);
    for (const auto& hospede : hospedes) {
        file << "Hospede," << hospede.paraCSV() << std::endl;
    }
}

void Dados::salvarReservas(const std::vector<Reserva>& reservas) {
    std::ofstream file(fileName, std::ios::app);
    for (const auto& reserva : reservas) {
        file << "Reserva," << reserva.paraCSV() << std::endl;
    }
}

void Dados::salvarPagamentos(const std::vector<Pagamento>& pagamentos) {
    std::ofstream file(fileName, std::ios::app);
    for (const auto& pagamento : pagamentos) {
        file << "Pagamento," << pagamento.paraCSV() << std::endl;
    }
}

void Dados::salvarAvaliacoes(const std::vector<Avaliacoes>& avaliacoes) {
    std::ofstream file(fileName, std::ios::app);
    for (const auto& avaliacao : avaliacoes) {
        file << "Avaliacao," << avaliacao.paraCSV() << std::endl;
    }
}


Cliente::Cliente(const std::string& nome, const std::string& cpf, const std::string& telefone, const std::string& email)
: Pessoa(nome, cpf, telefone), email(email) {

}


Cliente::~Cliente() {
    std::cout << "Destruindo o Objeto Cliente" << std::endl;
}


std::string Cliente::getEmail() const {
    return email;
}

void Cliente::setEmail(const std::string& novoEmail) {
   
    email = novoEmail;
}

std::string Cliente::paraCSV() const {
    std::stringstream ss;
    
    ss << Pessoa::paraCSV() << "," << email; 
    
    return ss.str();
}

Cliente Cliente::fromCSV(const std::string& csv) {
    std::istringstream iss(csv);
    
    
    std::string nome;    
    std::string cpf;      
    std::string telefone; 
    std::string email;    
    return Cliente(nome, cpf, telefone, email);
}



