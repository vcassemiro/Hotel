#include "Avaliacao.h"

// Implementações dos Getters e Setters...

// Construtor
Avaliacoes::Avaliacoes(const std::string& comentario, int nota, Hospede& hospede, Reserva& reserva)
: comentario(comentario), nota(nota), hospede(hospede), reserva(reserva) {}

// Destrutor
Avaliacoes::~Avaliacoes() {
    // Decidir se é necessário desalocar os objetos referenciados
}

// Método para converter informações da avaliação em formato CSV
std::string Avaliacoes::paraCSV() const {
    return comentario + "," + std::to_string(nota) + "," +
           hospede.getNome() + "," + reserva.getCodigo();
}

// Método fromCSV com tratamento de erros
Avaliacoes Avaliacoes::fromCSV(const std::string& csv) {
    std::istringstream iss(csv);
    
    std::string comentario;
    int nota;
    
    // Parse do comentário
    if (!std::getline(iss, comentario, ',')) {
        throw std::runtime_error("Erro ao ler o comentário da avaliação");
    }
    
    // Parse da nota (a implementar)
    
    // Criação dos objetos Hospede e Reserva (a implementar)
    
    // Supondo que temos objetos hospede e reserva válidos
    Hospede hospede; // Substituir pela criação real do objeto
    Reserva reserva; // Substituir pela criação real do objeto
    
    return Avaliacoes(comentario, nota, hospede, reserva);
}