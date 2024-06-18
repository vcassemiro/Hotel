#ifndef AVALIACAO_H
#define AVALIACAO_H

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

class Avaliacoes {
private:
    string comentario;
    int nota;

public:
    Avaliacoes(string comentario, int nota);
    ~Avaliacoes();

    string getComentario();
    int getNota();
    void setComentario(string comentario);
    void setNota(int nota);
    std::string paraCSV() const;
    static Avaliacoes fromCSV(const std::string& csv) {
    std::stringstream ss(csv);
    std::string comentario, notaStr;
    std::getline(ss, comentario, ',');
    std::getline(ss, notaStr, ',');

    int nota = std::stoi(notaStr);

    return Avaliacoes(comentario, nota);
}
};

#endif // AVALIACAO_H