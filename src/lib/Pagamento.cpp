#include "Pagamento.h"

Pagamento::Pagamento(double valor, const std::string& metodo, const std::string& data)
    : valor(valor), metodo(metodo), data(data), idPagamento(0) {}

Pagamento::Pagamento(const Pagamento& other)
    : valor(other.valor), metodo(other.metodo), data(other.data), idPagamento(other.idPagamento) {}

Pagamento::~Pagamento() {}

double Pagamento::getValor() const {
    return valor;
}

void Pagamento::setValor(double valor) {
    this->valor = valor;
}

std::string Pagamento::getMetodo() const {
    return metodo;
}

void Pagamento::setMetodo(const std::string& metodo) {
    this->metodo = metodo;
}

std::string Pagamento::getData() const {
    return data;
}

void Pagamento::setData(const std::string& data) {
    this->data = data;
}

int Pagamento::getIdPagamento() const {
    return idPagamento;
}

void Pagamento::setIdPagamento(int id) {
    idPagamento = id;
}

std::string Pagamento::paraCSV() const {
    std::stringstream ss;
    ss << valor << "," << metodo << "," << data << "," << idPagamento;
    return ss.str();
}

Pagamento Pagamento::fromCSV(const std::string& csv) {
    std::stringstream ss(csv);
    std::string valorStr, metodo, data, idStr;
    getline(ss, valorStr, ',');
    getline(ss, metodo, ',');
    getline(ss, data, ',');
    getline(ss, idStr, ',');

    double valor = 0.0;
    int id ;

    try {
        valor = std::stod(valorStr);
    } catch (const std::invalid_argument& e) {
        std::cerr << "argumento invalido para valor: " << e.what() << '\n';
        
    } catch (const std::out_of_range& e) {
        std::cerr << "valor invalido para valor: " << e.what() << '\n';
        
    }

    try {
        id = std::stoi(idStr);
    } catch (const std::invalid_argument& e) {
        std::cerr << "argumento invalido para valor: " << e.what() << '\n';
        
    } catch (const std::out_of_range& e) {
        std::cerr << "valor invalido para valor: " << e.what() << '\n';
       
    }

    return Pagamento(valor, metodo, data);
}

Pagamento& Pagamento::operator=(const Pagamento& other) {
    if (this != &other) {
        valor = other.valor;
        metodo = other.metodo;
        data = other.data;
        idPagamento = other.idPagamento;
    }
    return *this;
}
