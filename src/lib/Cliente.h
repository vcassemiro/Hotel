#ifndef CLIENTE_H
#define CLIENTE_H

#include "Pessoa.h"
#include <string>

class Cliente : public Pessoa {
private:
    std::string email;

public:
    Cliente(const std::string& nome, const std::string& cpf, const std::string& telefone, const std::string& email);
    ~Cliente();

    // Getters e Setters
    std::string getEmail() const;
    void setEmail(const std::string& email);

    // Método para CSV
    std::string paraCSV() const;
    static Cliente fromCSV(const std::string& csv);
};

#endif // CLIENTE_H