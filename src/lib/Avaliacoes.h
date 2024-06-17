#ifndef AVALIACOES_H
#define AVALIACOES_H


#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

    class Avaliacoes
    {
    private:
        string comentario;
        int nota;

    public:
        Avaliacoes(string comentario, int nota);
        ~Avaliacoes();

        string getComentario();
        int getNota();
        void setComentario(string comentario);
        void setNota(int nota);


};

#endif // AVALIACOES_H
