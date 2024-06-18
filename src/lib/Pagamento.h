#ifndef PAGAMENTO_H
#define PAGAMENTO_H

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

class Pagamento {
private:
    double valor;
    std::string metodo;
    std::string data;

    Pagamento(const Pagamento&) = delete;
    Pagamento& operator=(const Pagamento&) = delete;

public:
    Pagamento(double valor, const std::string& metodo, const std::string& data);
    ~Pagamento();

    double getValor() const {
        return valor;
    }
    
    void setValor(double valor) {
        this->valor = valor;
    }
    
    std::string getMetodo() const {
        return metodo;
    }
    
    void setMetodo(const std::string& metodo) {
        this->metodo = metodo;
    }
    
    std::tm getData() const {
        std::tm date;
        // Implement the logic to return the date
        return date;
    }
    
    void setData(const std::tm& data) {
        // Implement the logic to set the date
    }

    std::string paraCSV() const;
    static Pagamento fromCSV(const std::string& csv);
};

#endif // PAGAMENTO_H



