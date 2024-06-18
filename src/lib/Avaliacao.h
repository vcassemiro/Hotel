#ifndef AVALIACAO_H
#define AVALIACAO_H

#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Avaliacoes {
private:
    std::string comentario;
    int nota;

public:
    Avaliacoes(std::string comentario, int nota);
    ~Avaliacoes();

    std::string getComentario();
    int getNota();
    void setComentario(std::string comentario);
    void setNota(int nota);
    std::string paraCSV() const;
    static Avaliacoes fromCSV(const std::string& csv);

};

#endif // AVALIACAO_H
