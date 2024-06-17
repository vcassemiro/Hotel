#ifndef PAGAMENTO_H
#define PAGAMENTO_H

#include <string>
#include <ctime>

class Pagamento {
private:
    double valor;
    std::string metodo;
    std::tm data;

    // Construtor de cópia e operador de atribuição privados para evitar cópia
    Pagamento(const Pagamento&) = delete;
    Pagamento& operator=(const Pagamento&) = delete;

public:
    Pagamento(double valor, const std::string& metodo, const std::tm& data);
    ~Pagamento();

    // Getters e Setters...
    double getValor() const;
    void setValor(double valor);
    
    std::string getMetodo() const;
    void setMetodo(const std::string& metodo);
    
    std::tm getData() const;
    void setData(const std::tm& data);

    // Método para CSV
    std::string paraCSV() const;
    static Pagamento fromCSV(const std::string& csv);
};

#endif // PAGAMENTO_H
