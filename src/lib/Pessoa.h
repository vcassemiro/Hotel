#ifndef PESSOA_H
#define PESSOA_H
#include <string>

class Pessoa {
protected:
    std::string nome;
    std::string cpf;
    std::string telefone;

public:
    Pessoa(const std::string& nome, const std::string& cpf, const std::string& telefone);
    virtual ~Pessoa();

    // Getters e Setters
    std::string getNome() const;
    void setNome(const std::string& nome);

    std::string getCpf() const;
    void setCpf(const std::string& cpf);

    std::string getTelefone() const;
    void setTelefone(const std::string& telefone);

    // Método para CSV
    std::string paraCSV() const;
    static Pessoa fromCSV(const std::string& csv);
};

#endif // PESSOA_H
