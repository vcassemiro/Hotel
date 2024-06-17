
#include "Pagamento.h"
#include <sstream>
#include <iomanip>

// Implementações dos Getters e Setters...

// Construtor
Pagamento::Pagamento(double valor, const std::string& metodo, const std::tm& data)
: valor(valor), metodo(metodo), data(data) {
    // Adicionar validação aqui
}

// Destrutor
Pagamento::~Pagamento() {}

// Método para converter informações do pagamento em formato CSV
std::string Pagamento::paraCSV() const {
    std::stringstream ss;
    
    ss << std::fixed << std::setprecision(2) << valor << "," << metodo << ",";
    
    // Usando put_time para formatar a data
    ss << std::put_time(&data, "%d/%m/%Y");
    
    return ss.str();
}

// Método fromCSV com tratamento de erros
Pagamento Pagamento::fromCSV(const std::string& csv) {
    std::istringstream iss(csv);
    
    double valor;
    std::string metodo;
    std::tm data = {};
    
    // Parse do valor
    if (!(iss >> valor)) {
        throw std::runtime_error("Erro ao ler o valor do pagamento");
    }
    
    // Parse do método
    if (!std::getline(iss, metodo, ',')) {
        throw std::runtime_error("Erro ao ler o método do pagamento");
    }
    
    // Parse da data (a implementar)
    
    return Pagamento(valor, metodo, data);
}
