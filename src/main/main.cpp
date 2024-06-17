#include <iostream>
#include <string>
#include <vector>

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

using namespace std;

void mensagem_inicial() {
    std::cout << "==========================================" << std::endl;
    std::cout << "Seja bem-vindo ao sistema de hotelaria!" << std::endl;
    std::cout << "==========================================" << std::endl << std::endl;
}

void mensagem_menu() {
    cout << "1 -> Cadastrar Quarto Simples" << std::endl;
    cout << "2 -> Cadastrar Quarto Suite" << std::endl;
    cout << "3 -> Cadastrar Quarto Luxo" << std::endl;
    cout << "4 -> Cadastrar Hospede" << std::endl;
    cout << "5 -> Cadastrar Reserva" << std::endl;
    cout << "6 -> Cadastrar Pagamento" << std::endl;
    cout << "7 -> Cadastrar Avaliacao" << std::endl;
    cout << "8 -> Listar Quartos" << std::endl;
    cout << "9 -> Listar Hospedes" << std::endl;
    cout << "10 -> Listar Reservas" << std::endl;
    cout << "11 -> Listar Pagamentos" << std::endl;
    cout << "12 -> Listar Avaliacoes" << std::endl;
    cout << "13 -> Sair" << std::endl;
    cout << std::endl;
}

void cadastrarQuartoSimples(Dados& dados) {
    int numero;
    double preco;

    cout << "Digite o numero do quarto: ";
    cin >> numero;
    cout << "Digite o preco do quarto: ";
    cin >> preco;

    Quarto_Simples quarto(numero, preco);
    dados.salvar(to_string(quarto.getNumero()) + "," + to_string(quarto.getPreco()));
}

void cadastrarQuartoSuite(Dados& dados) {
    int numero;
    double preco;

    cout << "Digite o numero do quarto: ";
    cin >> numero;
    cout << "Digite o preco do quarto: ";
    cin >> preco;

    Quarto_Suite quarto(numero, preco);
    dados.salvar(to_string(quarto.getNumero()) + "," + to_string(quarto.getPreco()));
}

void cadastrarQuartoLuxo(Dados& dados) {
    int numero;
    double preco;

    cout << "Digite o numero do quarto: ";
    cin >> numero;
    cout << "Digite o preco do quarto: ";
    cin >> preco;

    Quarto_Luxo quarto(numero, preco);
    dados.salvar(to_string(quarto.getNumero()) + "," + to_string(quarto.getPreco()));
}

void cadastrarHospede(Dados& dados) {
    string nome, cpf, telefone, email;

    cout << "Digite o nome do hospede: ";
    cin >> nome;
    cout << "Digite o CPF do hospede: ";
    cin >> cpf;
    cout << "Digite o telefone do hospede: ";
    cin >> telefone;
    cout << "Digite o email do hospede: ";
    cin >> email;

    Hospede hospede(nome, cpf, telefone, email);
    dados.salvar(hospede.getNome() + "," + hospede.getCpf() + "," + hospede.getTelefone() + "," + hospede.getEmail());
}

void cadastrarReserva(Dados& dados) {
    string dtCheckIN, dtCheckOUT;
    Hospede* hospede;
    Quarto* quarto;
    double valor;

    // Aqui você deve inicializar hospede e quarto com os valores apropriados

    cout << "Digite a data de check-in: ";
    cin >> dtCheckIN;
    cout << "Digite a data de check-out: ";
    cin >> dtCheckOUT;
    cout << "Digite o valor: ";
    cin >> valor;

    Reserva reserva(dtCheckIN, dtCheckOUT, hospede, quarto, valor);
    dados.salvar(reserva.getDtCheckIN() + "," + reserva.getDtCheckOUT() + "," + to_string(reserva.getValor()));
}

void cadastrarPagamento(Dados& dados) {
    string metodo;
    double valor;

    cout << "Digite o metodo de pagamento: ";
    cin >> metodo;
    cout << "Digite o valor do pagamento: ";
    cin >> valor;

    Pagamento pagamento(metodo, valor);
    dados.salvar(pagamento.getMetodo() + "," + to_string(pagamento.getValor()));
}

void cadastrarAvaliacao(Dados& dados) {
    string comentario;
    int nota;

    cout << "Digite o comentario da avaliacao: ";
    cin >> comentario;
    cout << "Digite a nota da avaliacao: ";
    cin >> nota;

    Avaliacao avaliacao(comentario, nota);
    dados.salvar(avaliacao.getComentario() + "," + to_string(avaliacao.getNota()));
}

void listarQuartos(Dados& dados) {
    vector<Quarto> quartos = dados.carregarQuartos();
    for (const Quarto& quarto : quartos) {
        cout << "Quarto Numero: " << quarto.getNumero() << ", Preco: " << quarto.getPreco() << endl;
    }
}

void listarHospedes(Dados& dados) {
    vector<Hospede> hospedes = dados.carregarHospedes();
    for (const Hospede& hospede : hospedes) {
        cout << "Nome: " << hospede.getNome() << ", CPF: " << hospede.getCpf() << ", Telefone: " << hospede.getTelefone() << ", Email: " << hospede.getEmail() << endl;
    }
}

void listarReservas(Dados& dados) {
    vector<Reserva> reservas = dados.carregarReservas();
    for (const Reserva& reserva : reservas) {
        cout << "Check-in: " << reserva.getDtCheckIN() << ", Check-out: " << reserva.getDtCheckOUT() << ", Valor: " << reserva.getValor() << endl;
    }
}

void listarPagamentos(Dados& dados) {
    vector<Pagamento> pagamentos = dados.carregarPagamentos();
    for (const Pagamento& pagamento : pagamentos) {
        cout << "Metodo: " << pagamento.getMetodo() << ", Valor: " << pagamento.getValor() << endl;
    }
}

void listarAvaliacoes(Dados& dados) {
    vector<Avaliacao> avaliacoes = dados.carregarAvaliacoes();
    for (const Avaliacao& avaliacao : avaliacoes) {
        cout << "Comentario: " << avaliacao.getComentario() << ", Nota: " << avaliacao.getNota() << endl;
    }
}

int main() {
    mensagem_inicial();

    // Criar um objeto Dados para o arquivo Dados.csv
    Dados dados("Dados.csv");

    bool continuar = true;
    int escolha;

    while (continuar) {
        mensagem_menu();
        cin >> escolha;

        switch (escolha) {
            case 1:
                cadastrarQuartoSimples(dados);
                break;
            case 2:
                cadastrarQuartoSuite(dados);
                break;
            case 3:
                cadastrarQuartoLuxo(dados);
                break;
            case 4:
                cadastrarHospede(dados);
                break;
            case 5:
                cadastrarReserva(dados);
                break;
            case 6:
                cadastrarPagamento(dados);
                break;
            case 7:
                cadastrarAvaliacao(dados);
                break;
            case 8:
                listarQuartos(dados);
                break;
            case 9:
                listarHospedes(dados);
                break;
            case 10:
                listarReservas(dados);
                break;
            case 11:
                listarPagamentos(dados);
                break;
            case 12:
                listarAvaliacoes(dados);
                break;
            case 13:
                cout << "Escolheu Sair" << endl << endl;
                continuar = false;
                break;
            default:
                cout << "Escolha invalida" << endl << endl;
                break;
        }
    }
    return 0;
}
