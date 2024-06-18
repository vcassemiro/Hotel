#include "Hotel.h"
#include "dados.cpp"

Hotel::Hotel(int idHotel, const std::string& nome, const std::string& endereco)
    : idHotel(idHotel), nome(nome), endereco(endereco) {
}

Hotel::~Hotel() {
}

void Hotel::addQuarto(const Quarto& quarto) {
    quartos.push_back(quarto);
}

std::vector<Quarto> Hotel::getQuartos() const {
    return quartos;
}

void Hotel::addHospede(const Hospede& hospede) {
    hospedes.push_back(hospede);
}

std::vector<Hospede> Hotel::getHospedes() const {
    return hospedes;
}

void Hotel::addAvaliacao(const Avaliacoes& avaliacao) {
    avaliacoes.push_back(avaliacao);
}

std::vector<Avaliacoes> Hotel::getAvaliacoes() const {
    return avaliacoes;
}

void Hotel::addPagamento(const Pagamento& pagamento) {
    pagamentos.push_back(pagamento);
}

std::vector<Pagamento> Hotel::getPagamentos() const {
    return pagamentos;
}

void Hotel::salvarEmCSV(const std::string& nomeArquivo) const {
    std::ofstream file(nomeArquivo);
    if (file.is_open()) {
        file << "Hotel," << idHotel << "," << nome << "," << endereco << std::endl;
        for (const auto& quarto : quartos) {
            file << "Quarto," << quarto.paraCSV() << std::endl;
        }
        for (const auto& hospede : hospedes) {
            file << "Hospede," << hospede.paraCSV() << std::endl;
        }
        for (const auto& avaliacao : avaliacoes) {
            file << "Avaliacao," << avaliacao.paraCSV() << std::endl;
        }
        for (const auto& pagamento : pagamentos) {
            file << "Pagamento," << pagamento.paraCSV() << std::endl;
        }
    }
}
