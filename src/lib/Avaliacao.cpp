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
    Avaliacoes(string comentario, int nota) : comentario(comentario), nota(nota) {}
    ~Avaliacoes() {}

    string getComentario() {
        return comentario;
    }

    int getNota() {
        return nota;
    }

    void setComentario(string comentario) {
        this->comentario = comentario;
    }

    void setNota(int nota) {
        this->nota = nota;
    }

    std::string paraCSV() const {
        std::stringstream ss;
        ss << comentario << "," << nota;
        return ss.str();
    }

    static Avaliacoes fromCSV(const std::string& csv) {
        std::stringstream ss(csv);
        std::string comentario, notaStr;
        std::getline(ss, comentario, ',');
        std::getline(ss, notaStr, ',');

        int nota = std::stoi(notaStr);

        return Avaliacoes(comentario, nota);
    }
};
