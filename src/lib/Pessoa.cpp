#include "Pessoa.h"

Pessoa::Pessoa(const std::string& nome, const std::string& cpf, const std::string& telefone)
    : nome(nome), cpf(cpf), telefone(telefone) {
}

Pessoa::~Pessoa() {
}

std::string Pessoa::getNome() const {
    return nome;
}

std::string Pessoa::getCpf() const {
    return cpf;
}

std::string Pessoa::getTelefone() const {
    return telefone;
}

void Pessoa::setNome(const std::string& nome) {
    this->nome = nome;
}

void Pessoa::setCpf(const std::string& cpf) {
    this->cpf = cpf;
}

void Pessoa::setTelefone(const std::string& telefone) {
    this->telefone = telefone;
}

std::string Pessoa::paraCSV() const {
    std::stringstream ss;
    ss << nome << "," << cpf << "," << telefone;
    return ss.str();
}
