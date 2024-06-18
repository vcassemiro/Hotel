#include "Cliente.h"
#include <iostream>

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
    std::string nome, cpf, telefone, email;
    std::getline(iss, nome, ',');
    std::getline(iss, cpf, ',');
    std::getline(iss, telefone, ',');
    std::getline(iss, email, ',');
    return Cliente(nome, cpf, telefone, email);
}
