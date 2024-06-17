#include "Cliente.h"
#include <sstream>
#include <iostream>

// Construtor
Cliente::Cliente(const std::string& nome, const std::string& cpf, const std::string& telefone, const std::string& email)
: Pessoa(nome, cpf, telefone), email(email) {
    // Adicionar validação de email aqui
}

// Destrutor
Cliente::~Cliente() {
    std::cout << "Destruindo o Objeto Cliente" << std::endl;
}

// Getters e Setters
std::string Cliente::getEmail() const {
    return email;
}

void Cliente::setEmail(const std::string& novoEmail) {
    // Adicionar validação de email aqui
    email = novoEmail;
}

// Método para converter informações do cliente em formato CSV
std::string Cliente::paraCSV() const {
    std::stringstream ss;
    
    ss << Pessoa::paraCSV() << "," << email; // Utilize o método paraCSV da classe base Pessoa
    
    return ss.str();
}

// Método fromCSV para criar um objeto Cliente a partir de uma string CSV
Cliente Cliente::fromCSV(const std::string& csv) {
    std::istringstream iss(csv);
    
    // Parse das informações da Pessoa (a implementar)
    
    // Parse do email (a implementar)
    
    // Supondo que temos as variáveis nome, cpf, telefone e email válidas
    std::string nome;     // Substituir pelo parse real do nome
    std::string cpf;      // Substituir pelo parse real do cpf
    std::string telefone; // Substituir pelo parse real do telefone
    std::string email;    // Substituir pelo parse real do email
    
    return Cliente(nome, cpf, telefone, email);
}