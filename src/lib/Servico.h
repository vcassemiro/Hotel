#include <string>
using namespace std;


class Servico {
private:
    int idServico;
    string descricao;
    double preco;

public:
    Servico(int idServico, string descricao, double preco);
    ~Servico();

    // Getters
    int getIdServico() const {
        return idServico;
    }

    string getDescricao() const {
        return descricao;
    }

    double getPreco() const {
        return preco;
    }

    // Setters
    void setIdServico(int id) {
        idServico = id;
    }

    void setDescricao(const string& desc) {
        descricao = desc;
    }

    void setPreco(double p) {
        preco = p;
    }

    // Método para CSV
    string paraCSV();
    static Servico fromCSV(const std::string& csv);
};


