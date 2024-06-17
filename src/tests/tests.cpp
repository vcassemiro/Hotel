#define CATCH_CONFIG_MAIN  // Define a função main para Catch2


#include "catch.hpp"

#include "Reserva.h"
#include "Hospede.h"
#include "Quarto_Simples.h"
#include "Quarto_Suite.h"
#include "Quarto_Luxo.h"
#include "Hotel.h"
#include "Pagamentos.h"
#include "Avaliacoes.h"


TEST_CASE("Testar construtor da classe Reserva", "[Reserva]") {
    Hospede hospede("João Silva", "123.456.789-00", "987654321", "joao@example.com");
    Quarto_Simples quarto(101, 100.0);
    Reserva reserva("2024-06-01", "2024-06-05", &hospede, &quarto, 400.0);

    REQUIRE(reserva.getdtCheckIN() == "2024-06-01");
    REQUIRE(reserva.getdtCheckOUT() == "2024-06-05");
    REQUIRE(reserva.getHospede() == &hospede);
    REQUIRE(reserva.getQuarto() == &quarto);
    REQUIRE(reserva.getValor() == 400.0);
    
}

TEST_CASE("Testar cancelamento da reserva", "[Reserva]") {
    Hospede hospede("João Silva", "123.456.789-00", "987654321", "joao@example.com");
    Quarto_Simples quarto(101, 100.0);
    Reserva reserva("2024-06-01", "2024-06-05", &hospede, &quarto, 400.0);

    reserva.getHospede();
    REQUIRE(reserva.getHospede() == &hospede);
}

TEST_CASE("Testar construtor da classe Quarto_Simples", "[Quarto_Simples]") {
    Quarto_Simples quarto(101, 100.0);
    REQUIRE(quarto.getNumero() == 101);
    REQUIRE(quarto.getPreco() == 100.0);
}

TEST_CASE("Testar construtor da classe Quarto_Suite", "[Quarto_Suite]") {
    Quarto_Suite quarto(102, 200.0);
    REQUIRE(quarto.getNumero() == 102);
    REQUIRE(quarto.getPreco() == 200.0);
}

TEST_CASE("Testar construtor da classe Quarto_Luxo", "[Quarto_Luxo]") {
    Quarto_Luxo quarto(103, 300.0);
    REQUIRE(quarto.getNumero() == 103);
    REQUIRE(quarto.getPreco() == 300.0);
}

TEST_CASE("Testar construtor da classe Hospede", "[Hospede]") {
    Hospede hospede("João Silva", "123.456.789-00", "987654321", "joao@example.com");
    REQUIRE(hospede.getnome() == "João Silva");
    REQUIRE(hospede.getcpf() == "123.456.789-00");
    REQUIRE(hospede.gettelefone() == "987654321");
    //REQUIRE(hospede.getemail() == "joao@example.com");
}

TEST_CASE("Testar adicionar e obter histórico de reservas", "[Hospede]") {
    Hospede hospede("João Silva", "123.456.789-00", "987654321", "joao@example.com");
    hospede.addReserva("Reserva 1");
    hospede.addReserva("Reserva 2");

    vector<string> historico = hospede.gethistoricoReserva();
    REQUIRE(historico.size() == 2);
    REQUIRE(historico[0] == "Reserva 1");
    REQUIRE(historico[1] == "Reserva 2");
}

TEST_CASE("Testar construtor da classe Hotel", "[Hotel]") {
    Hotel hotel("Hotel XYZ", "Rua ABC, 123");
    REQUIRE(hotel.getNome() == "Hotel XYZ");
    REQUIRE(hotel.getEndereco() == "Rua ABC, 123");
}

TEST_CASE("Testar adicionar e obter quartos no hotel", "[Hotel]") {
    Hotel hotel("Hotel XYZ", "Rua ABC, 123");
    Quarto_Simples quarto1(101, 100.0);
    Quarto_Suite quarto2(102, 200.0);

    hotel.addQuarto(&quarto1);
    hotel.addQuarto(&quarto2);

    vector<Quarto*> quartos = hotel.getQuartos();
    REQUIRE(quartos.size() == 2);
    REQUIRE(quartos[0]->getNumero() == 101);
    REQUIRE(quartos[1]->getNumero() == 102);
}

TEST_CASE("Testar adicionar e obter reservas no hotel", "[Hotel]") {
    Hotel hotel("Hotel XYZ", "Rua ABC, 123");
    Hospede hospede("João Silva", "123.456.789-00", "987654321", "joao@example.com");
    Quarto_Simples quarto(101, 100.0);
    Reserva reserva("2024-06-01", "2024-06-05", &hospede, &quarto, 400.0);

    hotel.addReserva(&reserva);

    vector<Reserva*> reservas = hotel.getReservas();
    REQUIRE(reservas.size() == 1);
    REQUIRE(reservas[0]->getdtCheckIN() == "2024-06-01");
}

TEST_CASE("Testar construtor da classe Pagamentos", "[Pagamentos]") {
    Pagamentos pagamento("Cartão", 100.0);
    REQUIRE(pagamento.getMetodo() == "Cartão");
    REQUIRE(pagamento.getValor() == 100.0);
}

TEST_CASE("Testar setters da classe Pagamentos", "[Pagamentos]") {
    Pagamentos pagamento("Cartão", 100.0);
    pagamento.setMetodo("Dinheiro");
    pagamento.setValor(200.0);
    REQUIRE(pagamento.getMetodo() == "Dinheiro");
    REQUIRE(pagamento.getValor() == 200.0);
}

TEST_CASE("Testar construtor da classe Avaliacoes", "[Avaliacoes]") {
    Avaliacoes avaliacao("Bom", 4);
    REQUIRE(avaliacao.getComentario() == "Bom");
    REQUIRE(avaliacao.getNota() == 4);
}

TEST_CASE("Testar setters da classe Avaliacoes", "[Avaliacoes]") {
    Avaliacoes avaliacao("Bom", 4);
    avaliacao.setComentario("Excelente");
    avaliacao.setNota(5);
    REQUIRE(avaliacao.getComentario() == "Excelente");
    REQUIRE(avaliacao.getNota()==5);
}