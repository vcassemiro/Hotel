#include "Avaliacoes.h"

// Construtor
Avaliacoes::Avaliacoes(string comentario, int nota) : comentario(comentario), nota(nota) {}

// Destrutor
Avaliacoes::~Avaliacoes() {}

// Método para obter o comentário
string Avaliacoes::getComentario() {
    return comentario;
}

// Método para obter a nota
int Avaliacoes::getNota() {
    return nota;
}

// Método para definir o comentário
void Avaliacoes::setComentario(string comentario) {
    this->comentario = comentario;
}

// Método para definir a nota
void Avaliacoes::setNota(int nota) {
    this->nota = nota;
}
