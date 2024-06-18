#include "Reserva.h"
Reserva::Reserva(const std::string& dtCheckIN, const std::string& dtCheckOUT, Hospede* hospede, Quarto* quarto, double valor, const std::vector<Servico>& servicos, const std::vector<Pagamento>& pagamentos, int idReserva, int idHospede, int idQuarto, int idHotel)
    : dtCheckIN(dtCheckIN), dtCheckOUT(dtCheckOUT), hospede(hospede), quarto(quarto), valor(valor), servicos(servicos), pagamentos(pagamentos), idReserva(idReserva), idHospede(idHospede), idQuarto(idQuarto), idHotel(idHotel) {
}
// Getters and Setters
const string& Reserva::getDtCheckIN() const {
    return dtCheckIN;
}

void Reserva::setDtCheckIN(const string& dt) {
    dtCheckIN = dt;
}

const string& Reserva::getDtCheckOUT() const {
    return dtCheckOUT;
}

void Reserva::setDtCheckOUT(const string& dt) {
    dtCheckOUT = dt;
}

Hospede* Reserva::getHospede() const {
    return hospede;
}

void Reserva::setHospede(Hospede* h) {
    hospede = h;
}

Quarto* Reserva::getQuarto() const {
    return quarto;
}

void Reserva::setQuarto(Quarto* q) {
    quarto = q;
}

double Reserva::getValor() const {
    return valor;
}

void Reserva::setValor(double v) {
    valor = v;
}

void Reserva::addServico(const Servico& servico) {
    servicos.push_back(servico);
}

const vector<Servico>& Reserva::getServicos() const {
    return servicos;
}

void Reserva::addPagamento(const Pagamento& pagamento) {
    pagamentos.push_back(pagamento);
}

const vector<Pagamento>& Reserva::getPagamentos() const {
    return pagamentos;
}

int Reserva::getIdReserva() const {
    return idReserva;
}

void Reserva::setIdReserva(int id) {
    idReserva = id;
}

int Reserva::getIdHospede() const {
    return idHospede;
}

void Reserva::setIdHospede(int id) {
    idHospede = id;
}

int Reserva::getIdQuarto() const {
    return idQuarto;
}

void Reserva::setIdQuarto(int id) {
    idQuarto = id;
}

int Reserva::getIdHotel() const {
    return idHotel;
}

void Reserva::setIdHotel(int id) {
    idHotel = id;
}

// CSV methods
string Reserva::paraCSV() const {
    stringstream ss;
    ss << dtCheckIN << "," << dtCheckOUT << "," << idHospede << "," << idQuarto << "," << valor << "," << idReserva << "," << idHotel;
    for (const auto& servico : servicos) {
        ss << "," << servico.paraCSV();
    }
    for (const auto& pagamento : pagamentos) {
        ss << "," << pagamento.paraCSV();
    }
    return ss.str();
}

Reserva Reserva::fromCSV(const string& csv) {
    stringstream ss(csv);
    string dtCheckIN, dtCheckOUT, idHospedeStr, idQuartoStr, valorStr, idReservaStr, idHotelStr;
    
    getline(ss, dtCheckIN, ',');
    getline(ss, dtCheckOUT, ',');
    getline(ss, idHospedeStr, ',');
    getline(ss, idQuartoStr, ',');
    getline(ss, valorStr, ',');
    getline(ss, idReservaStr, ',');
    getline(ss, idHotelStr, ',');

    int idHospede = stoi(idHospedeStr);
    int idQuarto = stoi(idQuartoStr);
    double valor = stod(valorStr);
    int idReserva = stoi(idReservaStr);
    int idHotel = stoi(idHotelStr);

    vector<Servico> servicos;
    vector<Pagamento> pagamentos;

    // Assume Servico and Pagamento have fromCSV methods
    string servicoStr, pagamentoStr;
    while (getline(ss, servicoStr, ',')) {
        servicos.push_back(Servico::fromCSV(servicoStr));
    }
    while (getline(ss, pagamentoStr, ',')) {
        pagamentos.push_back(Pagamento::fromCSV(pagamentoStr));
    }

    return Reserva(dtCheckIN, dtCheckOUT, nullptr, nullptr, valor, servicos, pagamentos, idReserva, idHospede, idQuarto, idHotel);
}

Reserva* Reserva::getReservaById(const vector<Reserva*>& reservas, int id) {
    for (const auto& reserva : reservas) {
        if (reserva->getIdReserva() == id) {
            return reserva;
        }
    }
    return nullptr;
}