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

Dados dados("Dados.csv");
void mensagem_inicial() {
    cout << "==========================================" << endl;
    cout << "Seja bem-vindo ao sistema de hotelaria!" << endl;
    cout << "==========================================" << endl << endl;
}

void mensagem_menu() {
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

void cadastrarQuartoSimples(Dados& dados) {
    int idQuarto, idHotel;
    double preco;
    bool disponivel;

    std::cout << "Enter the room ID: ";
    std::cin >> idQuarto;

    std::cout << "Enter the hotel ID: ";
    std::cin >> idHotel;

    std::cout << "Enter the price: ";
    std::cin >> preco;

    std::cout << "Is the room available? (1 for yes, 0 for no): ";
    std::cin >> disponivel;

    Quarto_Simples newRoom(idQuarto, idHotel, preco, disponivel);
    std::vector<Quarto> rooms;
    rooms.push_back(newRoom);
    dados.salvarQuartos(rooms);
}

void cadastrarQuartoSuite(Dados& dados) {
    int idQuarto, idHotel;
    double preco;
    bool disponivel;

    std::cout << "Enter the room ID: ";
    std::cin >> idQuarto;

    std::cout << "Enter the hotel ID: ";
    std::cin >> idHotel;

    std::cout << "Enter the price: ";
    std::cin >> preco;

    std::cout << "Is the room available? (1 for yes, 0 for no): ";
    std::cin >> disponivel;

    Quarto_Suite newRoom(idQuarto, idHotel, preco, disponivel);
    std::vector<Quarto> rooms;
    rooms.push_back(newRoom);
    dados.salvarQuartos(rooms);
}

void cadastrarQuartoLuxo(Dados& dados) {
    int idQuarto, idHotel;
    double preco;
    bool disponivel;

    std::cout << "Enter the room ID: ";
    std::cin >> idQuarto;

    std::cout << "Enter the hotel ID: ";
    std::cin >> idHotel;

    std::cout << "Enter the price: ";
    std::cin >> preco;

    std::cout << "Is the room available? (1 for yes, 0 for no): ";
    std::cin >> disponivel;

    Quarto_Luxo newRoom(idQuarto, idHotel, preco, disponivel);
    std::vector<Quarto> rooms;
    rooms.push_back(newRoom);
    dados.salvarQuartos(rooms);
}

void cadastrarHospede(Dados& dados) {
    std::string nome, telefone, email;

    std::cout << "Enter the guest name: ";
    std::cin.ignore();
    std::getline(std::cin, nome);

    std::cout << "Enter the guest phone number: ";
    std::getline(std::cin, telefone);

    std::cout << "Enter the guest email: ";
    std::getline(std::cin, email);

    Hospede newGuest(nome, telefone, email);
    std::vector<Hospede> guests;
    guests.push_back(newGuest);
    dados.salvarHospedes(guests);
}

void cadastrarReserva(Dados& dados) {
    int idHospede, idQuarto;
    std::string dataInicio, dataFim;

    std::cout << "Enter the guest ID: ";
    std::cin >> idHospede;

    std::cout << "Enter the room ID: ";
    std::cin >> idQuarto;

    std::cout << "Enter the start date (YYYY-MM-DD): ";
    std::cin >> dataInicio;

    std::cout << "Enter the end date (YYYY-MM-DD): ";
    std::cin >> dataFim;

    Reserva newReservation(idHospede, idQuarto, dataInicio, dataFim, 0);
    std::vector<Reserva> reservations;
    reservations.push_back(newReservation);
    dados.salvarReservas(reservations);
}

void cadastrarPagamento(Dados& dados) {
    int idPagamento, idReserva;
    double valor;
    std::string data;

    std::cout << "Enter the payment ID: ";
    std::cin >> idPagamento;

    std::cout << "Enter the reservation ID: ";
    std::cin >> idReserva;

    std::cout << "Enter the payment amount: ";
    std::cin >> valor;

    std::cout << "Enter the payment date (YYYY-MM-DD): ";
    std::cin >> data;

    Pagamento newPayment(idPagamento, idReserva, valor, data);
    std::vector<Pagamento> payments;
    payments.push_back(newPayment);
    dados.salvarPagamentos(payments);
}

void cadastrarAvaliacao(Dados& dados) {
    int idAvaliacao, idHospede, nota;
    std::string comentario;

    std::cout << "Enter the evaluation ID: ";
    std::cin >> idAvaliacao;

    std::cout << "Enter the guest ID: ";
    std::cin >> idHospede;

    std::cout << "Enter the rating (1-5): ";
    std::cin >> nota;

    std::cout << "Enter the comment: ";
    std::cin.ignore();
    std::getline(std::cin, comentario);

    Avaliacao newEvaluation(idAvaliacao, idHospede, nota, comentario);
    std::vector<Avaliacao> evaluations;
    evaluations.push_back(newEvaluation);
    dados.salvarAvaliacoes(evaluations);
}

void listarQuartos(Dados& dados) {
    std::vector<Quarto> quartos = dados.getQuartos();
    for (const auto& quarto : quartos) {
        std::cout << "Room ID: " << quarto.getIdQuarto() << std::endl;
        std::cout << "Hotel ID: " << quarto.getIdHotel() << std::endl;
        std::cout << "Price: " << quarto.getPreco() << std::endl;
        std::cout << "Availability: " << (quarto.isDisponivel() ? "Yes" : "No") << std::endl;
        std::cout << std::endl;
    }
}

void listarHospedes(Dados& dados) {
    std::vector<Hospede> hospedes = dados.getHospedes();
    for (const auto& hospede : hospedes) {
        std::cout << "Guest Name: " << hospede.getNome() << std::endl;
        std::cout << "Phone Number: " << hospede.getTelefone() << std::endl;
        std::cout << "Email: " << hospede.getEmail() << std::endl;
        std::cout << std::endl;
    }
}

void listarReservas(Dados& dados) {
    std::vector<Reserva> reservas = dados.getReservas();
    for (const auto& reserva : reservas) {
        std::cout << "Reservation ID: " << reserva.getIdReserva() << std::endl;
        std::cout << "Guest ID: " << reserva.getIdHospede() << std::endl;
        std::cout << "Room ID: " << reserva.getIdQuarto() << std::endl;
        std::cout << "Start Date: " << reserva.getDataInicio() << std::endl;
        std::cout << "End Date: " << reserva.getDataFim() << std::endl;
        std::cout << std::endl;
    }
}

void listarPagamentos(Dados& dados) {
    std::vector<Pagamento> pagamentos = dados.getPagamentos();
    for (const auto& pagamento : pagamentos) {
        std::cout << "Payment ID: " << pagamento.getIdPagamento() << std::endl;
        std::cout << "Reservation ID: " << pagamento.getIdReserva() << std::endl;
        std::cout << "Amount: " << pagamento.getValor() << std::endl;
        std::cout << "Date: " << pagamento.getData() << std::endl;
        std::cout << std::endl;
    }
}

void listarAvaliacoes(Dados& dados) {
    std::vector<Avaliacao> avaliacoes = dados.getAvaliacoes();
    for (const auto& avaliacao : avaliacoes) {
        std::cout << "Evaluation ID: " << avaliacao.getIdAvaliacao() << std::endl;
        std::cout << "Guest ID: " << avaliacao.getIdHospede() << std::endl;
        std::cout << "Rating: " << avaliacao.getNota() << std::endl;
        std::cout << "Comment: " << avaliacao.getComentario() << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    mensagem_inicial();


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
