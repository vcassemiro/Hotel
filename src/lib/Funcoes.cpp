#include <fstream>
#include <vector>
#include <sstream>
#include "Reserva.h"

// Função para carregar reservas do arquivo CSV
std::vector<Reserva> carregarReservas(const string& nomeArquivo) {
    std::vector<Reserva> reservas;
    std::ifstream arquivo(nomeArquivo);
    string linha;

    // Verifica se o arquivo foi aberto corretamente
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo de reservas!" << endl;
        return reservas;
    }

    // Lê o arquivo linha por linha
    while (getline(arquivo, linha)) {
        std::stringstream ss(linha);
        string valor;
        std::vector<string> valores;

        // Separa os valores por vírgula
        while (getline(ss, valor, ',')) {
            valores.push_back(valor);
        }

        // Criação dos objetos Reserva com base nos valores
        if (valores.size() == 4) { // Supondo que cada linha tenha 4 valores: código, data de início, data de fim e código do hóspede
            string codigo = valores[0];
            // Convertendo as datas de string para time_t
            struct tm tmInicio, tmFim;
            strptime(valores[1].c_str(), "%d/%m/%Y", &tmInicio);
            strptime(valores[2].c_str(), "%d/%m/%Y", &tmFim);
            time_t dataInicio = mktime(&tmInicio);
            time_t dataFim = mktime(&tmFim);
            string codigoHospede = valores[3];

            Reserva reserva(codigo, dataInicio, dataFim, codigoHospede);
            reservas.push_back(reserva);
        }
    }

    arquivo.close();
    return reservas;
}

// Na função main, você chamaria a função carregarReservas com o nome do arquivo CSV
int main() {
    std::vector<Reserva> reservas = carregarReservas("reservas.csv");
    // Faça o que for necessário com a lista de reservas...

    return 0;
}
