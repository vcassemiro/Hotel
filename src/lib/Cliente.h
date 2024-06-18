#ifndef CLIENTE_H
#define CLIENTE_H

#include "Pessoa.h"
#include <string>
#include <sstream>

class Cliente : public Pessoa {
public:
    Cliente(const std::string& nome, const std::string& cpf, const std::string& telefone, const std::string& email);
    virtual ~Cliente();

    std::string getEmail() const;
    void setEmail(const std::string& novoEmail);

    virtual std::string paraCSV() const override;
    static Cliente fromCSV(const std::string& csv);

private:
    std::string email;
};

#endif
