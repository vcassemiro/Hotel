#ifndef SERVICO_H
#define SERVICO_H

#include <string>

using std::string;

class Servico {
private:
    int idServico;
    string descricao;
    double preco;

public:
    Servico(int idServico, string descricao, double preco);
    ~Servico();

    // Getters e Setters...

    // Método para CSV
    string paraCSV();
};

#endif // SERVICO_H
