#include "Avaliacao.h"

Avaliacoes::Avaliacoes(std::string comentario, int nota) : comentario(comentario), nota(nota) {}

Avaliacoes::~Avaliacoes() {}

std::string Avaliacoes::getComentario() {
    return comentario;
}

int Avaliacoes::getNota() {
    return nota;
}

void Avaliacoes::setComentario(std::string comentario) {
    this->comentario = comentario;
}

void Avaliacoes::setNota(int nota) {
    this->nota = nota;
}

std::string Avaliacoes::paraCSV() const {
    std::stringstream ss;
    ss << comentario << "," << nota;
    return ss.str();
}

Avaliacoes Avaliacoes::fromCSV(const std::string& csv) {
    std::stringstream ss(csv);
    std::string comentario, notaStr;
    std::getline(ss, comentario, ',');
    std::getline(ss, notaStr, ',');

    int nota = 0;

    try {
        nota = std::stoi(notaStr);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument for nota: " << e.what() << '\n';
        // Handle the error or return
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range for nota: " << e.what() << '\n';
        // Handle the error or return
    }

    return Avaliacoes(comentario, nota);
}

