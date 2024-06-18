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

Dados dados("Dados.csv");

void mensagem_inicial() { //Mensagem padrao inicializacao sistema
    cout << "==========================================" << endl;
    cout << "Seja bem-vindo ao sistema de hotelaria!" << endl;
    cout << "==========================================" << endl << endl;
}

void mensagem_menu() { //Mensagem padrao exibir menu (usada diversas vezes)
    cout << "1 -> Cadastrar Quarto Simples" << endl;
    cout << "2 -> Cadastrar Quarto Suite" << endl;
    cout << "3 -> Cadastrar Quarto Luxo" << endl;
    cout << "4 -> Cadastrar Hospede" << endl;
    cout << "5 -> Cadastrar Reserva" << endl;
    cout << "6 -> Cadastrar Pagamento" << endl;
    cout << "7 -> Cadastrar Avaliacao" << endl;
    cout << "8 -> Listar Quartos" << endl;
    cout << "9 -> Listar Hospedes" << endl;
    cout << "10 -> Listar Reservas" << endl;
    cout << "11 -> Listar Pagamentos" << endl;
    cout << "12 -> Listar Avaliacoes" << endl;
    cout << "13 -> Sair" << endl;
    cout << endl;
}

void cadastrarQuartoSimples(Dados& dados) { //Funcao void 1, cadastra quartos simples (heranca de quarto)
    int idQuarto, idHotel;
    double preco;
    bool disponivel;

    cout << "Digite o ID do quarto: ";
    cin >> idQuarto;

    cout << "Digite o ID do hotel: ";
    cin >> idHotel;

    cout << "Digite o preco: ";
    cin >> preco;

    cout << "O quarto esta diponivel? (1 para sim, 0 para nao): ";
    cin >> disponivel;

    Quarto_Simples newRoom(idQuarto, idHotel, preco, disponivel);
    vector<Quarto> rooms;
    rooms.push_back(newRoom);
    dados.salvarQuartos(rooms);
}

void cadastrarQuartoSuite(Dados& dados) { //Funcao void 2, cadastra quartos suites (heranca de quarto)
    int idQuarto, idHotel;
    double preco;
    bool disponivel;

    cout << "Digite o ID do quarto: ";
    cin >> idQuarto;

    cout << "Digite o ID do hotel: ";
    cin >> idHotel;

    cout << "Digite o preco: ";
    cin >> preco;

    cout << "O quarto esta diponivel? (1 para sim, 0 para nao): ";
    cin >> disponivel;

    Quarto_Suite newRoom(idQuarto, idHotel, preco, disponivel);
    vector<Quarto> rooms;
    rooms.push_back(newRoom);
    dados.salvarQuartos(rooms);
}

void cadastrarQuartoLuxo(Dados& dados) { //Funcao void 3, cadastra quartos luxo (heranca de quarto)
    int idQuarto, idHotel;
    double preco;
    bool disponivel;

    cout << "Digite o ID do quarto: ";
    cin >> idQuarto;

    cout << "Digite o ID do hotel: ";
    cin >> idHotel;

    cout << "Digite o preco: ";
    cin >> preco;

    cout << "O quarto esta diponivel? (1 para sim, 0 para nao): ";
    cin >> disponivel;

    Quarto_Luxo newRoom(idQuarto, idHotel, preco, disponivel);
    vector<Quarto> rooms;
    rooms.push_back(newRoom);
    dados.salvarQuartos(rooms);
}
void cadastrarHospede(Dados& dados) { //Funcao void 4, cadastra hospedes (heranca de cliente -> pessoa)
    string nome, telefone, email;
    int idHospede;

    cout << "Digite o nome do usuario: ";
    cin >> nome;

    cout << "Digite o telefone do usuario: ";
    cin >> telefone;

    cout << "Digite o email do usuario: ";
    cin >> email;


    cout << "Digite o idHospede do usuario: ";
    cin >> idHospede;

    Hospede newGuest(nome, telefone, email, idHospede);
    vector<Hospede> guests;
    guests.push_back(newGuest);
    dados.salvarHospedes(guests);
}






void cadastrarReserva(Dados& dados) { //Funcao void 5, cadastra reservas (heranca de cliente -> pessoa)
    int idHospede, idQuarto;
    string dataInicio, dataFim;

    cout << "Digite o codigo do usuario: ";
    cin >> idHospede;

    cout << "Digite o codigo do quarto: ";
    cin >> idQuarto;

    cout << "Digite a data de entrada (AAAA-MM-DD): ";
    cin >> dataInicio;

    cout << "Digite a data de saida (AAAA-MM-DD): ";
    cin >> dataFim;

    Reserva newReservation(dataInicio, dataFim, nullptr, nullptr, 0.0, {}, {}, 0, idHospede, idQuarto, 0);
    vector<Reserva> reservations;
    reservations.push_back(newReservation);
    dados.salvarReservas(reservations);
}


void cadastrarPagamento(Dados& dados) {
    double bla;
    string metodo, data;

    cout << "Digite o valor do pagamento: ";
    cin >> bla;

    cout << "Digite o metodo de pagamento: ";
    cin >> metodo;

    cout << "Digite a data de pagamento (AAAA-MM-DD): ";
    cin >> data;

    Pagamento newPayment (bla, metodo, data);
    vector<Pagamento> payments;
    payments.push_back(newPayment);
    dados.salvarPagamentos(payments);
}

void cadastrarAvaliacao(Dados& dados) { //Funcao void 7, cadastro de avalicaos (classe avaliacoes)
    int idAvaliacao, idHospede, nota;
    string comentario;
    cout << "Digite a nota (1-5): ";
    cin >> nota;

    cout << "Digite o comentario: ";
    cin.ignore();
    getline(cin, comentario);

    Avaliacoes newEvaluation(comentario,nota);
    vector<Avaliacoes> evaluations;
    evaluations.push_back(newEvaluation);
    dados.salvarAvaliacoes(evaluations);
}

void listarQuartos(Dados& dados) { //Funcao void 8, lista quartos registrados.
    vector<Quarto> quartos = dados.carregarQuartos();
    for (const auto& quarto : quartos) {
        cout << "Quarto ID: " << quarto.getIdQuarto() << endl;
        cout << "Hotel ID: " << quarto.getIdHotel() << endl;
        cout << "Preco: " << quarto.getPreco() << endl;
        cout << "Disponibilidade: " << (quarto.isDisponivel() ? "Yes" : "No") << endl;
        cout << endl;
    }
}

void listarHospedes(Dados& dados) { //Funcao void 9, lista hospedes registrados.
    vector<Hospede> hospedes = dados.carregarHospedes();
    for (const auto& hospede : hospedes) {
        cout << "Nome usuario: " << hospede.getNome() << endl;
        cout << "Numero telefone: " << hospede.getTelefone() << endl;
        cout << "Email: " << hospede.getEmail() << endl;
        cout << endl;
    }
}

void listarReservas(Dados& dados) { //Funcao void 10, lista reservas registradas.
    vector<Reserva> reservas = dados.carregarReservas();
    for (const auto& reserva : reservas) {
        cout << "Codigo de reserva: " << reserva.getIdReserva() << endl;
        cout << "Codigo de usuario: " << reserva.getIdHospede() << endl;
        cout << "Codigo do quarto: " << reserva.getIdQuarto() << endl;
        cout << "Data de entrada: " << reserva.getDtCheckIN() << endl;
        cout << "Data de saida: " << reserva.getDtCheckOUT() << endl;
        cout << endl;
    }
}

void listarPagamentos(Dados& dados) { //Funcao void 11, lista pagamentos registrados.
    vector<Pagamento> pagamentos = dados.carregarPagamentos();
    for (const auto& pagamento : pagamentos) {
        cout << "Valor: " << pagamento.getValor() << endl;
        cout << "Data: "; pagamento.getData();
        cout << endl;
    }
}

void listarAvaliacoes(Dados& dados) { //Funcao void 12, lista avalicacoes registradas.
    vector<Avaliacoes> avaliado = dados.carregarAvaliacoes();
    int i=0;
    for (const auto& Avaliacoes : avaliado) {
        cout << "Avalicao: " << avaliado[i].getNota();
        cout << "Comentario: " << avaliado[i].getComentario(); 
        cout << endl;
        i++;
    }
}

int main() { //principal
    
    mensagem_inicial();

    bool continuar = true; //variavel tipo bool para controlar continuidade do while.
    int escolha; //variavel tipo int para receber entrada de interacao usuario e interface.

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
