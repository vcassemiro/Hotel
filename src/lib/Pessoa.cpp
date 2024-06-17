#include "Pessoa.h"
#include <sstream>
#include <iostream>

// Construtor
Pessoa::Pessoa(const std::string& nome, const std::string& cpf, const std::string& telefone)
: nome(nome), cpf(cpf), telefone(telefone) {
    // Adicionar validação de CPF e telefone aqui
}

// Destrutor
Pessoa::~Pessoa() {
    std::cout << "Destruindo o Objeto Pessoa" << std::endl;
}

// Getters e Setters
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
    // Adicionar validação de CPF aqui
    cpf = novoCpf;
}

std::string Pessoa::getTelefone() const {
    return telefone;
}

void Pessoa::setTelefone(const std::string& novoTelefone) {
    // Adicionar validação de telefone aqui
    telefone = novoTelefone;
}

// Método para converter informações da pessoa em formato CSV
std::string Pessoa::paraCSV() const {
    std::stringstream ss;
    
    ss << nome << "," << cpf << "," << telefone;
    
    return ss.str();
}

// Método fromCSV para criar um objeto Pessoa a partir de uma string CSV
Pessoa Pessoa::fromCSV(const std::string& csv) {
    std::istringstream iss(csv);
    
    // Parse das informações (a implementar)
    
    // Supondo que temos as variáveis nome, cpf e telefone válidas
    std::string nome;     // Substituir pelo parse real do nome
    std::string cpf;      // Substituir pelo parse real do cpf
    std::string telefone; // Substituir pelo parse real do telefone
    
    return Pessoa(nome, cpf, telefone);
}