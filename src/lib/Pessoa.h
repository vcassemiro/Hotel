#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <sstream>

class Pessoa {
public:
    Pessoa(const std::string& nome, const std::string& cpf, const std::string& telefone);
    virtual ~Pessoa();

    std::string getNome() const;
    std::string getCpf() const;
    std::string getTelefone() const;

    void setNome(const std::string& nome);
    void setCpf(const std::string& cpf);
    void setTelefone(const std::string& telefone);

    virtual std::string paraCSV() const;

private:
    std::string nome;
    std::string cpf;
    std::string telefone;
};

#endif
