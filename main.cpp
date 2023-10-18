#include <iostream>
#include "sculptor.h"
#include <fstream>

int main()
{
    int nl, nc, np;
    int t1, t2, t3;
    //int r, g, b, a = 1.1;
    t1 = 12, t2 = 12, t3 = 18;

    std::cout << "Iniciado.";

    std::cout << std::endl << "Quantidade de linhas: ";
    //std::cin >> nl;
    nl = 50;
    std::cout << std::endl << "Quantidade de colunas: ";
    //std::cin >> nc;
    nc = 50;
    std::cout << std::endl << "Quantidade de planos: ";
    //std::cin >> np;
    np = 50;

    Sculptor *s = new Sculptor(nl, nc, np);

    // Construtor Sculptor está funcionando
    // Destrutor Sculptor está funcionando
    // WriteOFF está funcionando
    // PUTBOX ESTÁ FUNCIONANDO
    // CUTBOX ESTÁ FUNCIONANDO
    // PUTSPHERE ESTÁ FUNCIONANDO
    // CUTSPHERE ESTÁ FUNCIONANDO
    // PUTVOXEL ESTÁ FUNCINANDO
    // CUTVOXEL ESTÁ FUNCIONANDO
    // SETCOLOR ESTÁFUNCIONANDO
  
  
    // CANECA

    // Montando o corpo da caneca.
    s->putBox(0, t1, 0, t2, 0, t3);
    s->cutBox(1, t1-1, 1, t2-1, 1, t3);

    // Montando a asa da caneca.
    s->putBox(t1, t1+4, t2-7, t2-5, t3-4, t3-3);

    s->putVoxel(t1+4, t2-6, t3-5);
    s->putVoxel(t1+4, t2-7, t3-5);
    s->putVoxel(t1+5, t2-6, t3-6);
    s->putVoxel(t1+5, t2-7, t3-6);

    s->putBox(t1+5, t1+6, t2-7, t2-5, t3-14, t3-6);

    s->putVoxel(t1+4, t2-6, t3-15);
    s->putVoxel(t1+4, t2-7, t3-15);

    s->putBox(t1, t1+4, t2-7, t2-5, t3-16, t3-15);

    // Retirando as bordas da caneca.
    s->cutBox(t1-1, t1, t2-1, t2, 0, t3);
    s->cutBox(0, 1, t2-1, t2, 0, t3);
    s->cutBox(0, 1, 0, 1, 0, t3);
    s->cutBox(t1-1, t1, 0, 1, 0, t3);

    // Retirando as bordas do fundo da caneca
    s->cutBox(0, t1, t2-1, t2, 0, 1);
    s->cutBox(0, 1, 0, t2, 0, 1);
    s->cutBox(t1-1, t1, 0, t2, 0, 1);
    s->cutBox(0, t1, 0, 1, 0, 1);

    // Cor da caneca
    s->setColor(1.0, 1, 1, 1);

    // Parte interna da caneca.
    s->putBox(1, t1-1, 1, t2-1, 1, t3-5);
    s->setColor(0.4, 0.2, 0.1, 1); // Cor do cafézinho


    // Fumaça usando esferas.
    s->putSphere(23, 20, 35, 2);
    s->putSphere(20, 10, 35, 2);
    s->putSphere(13, 10, 32, 2);
    s->putSphere(17, 15, 30, 2);
    s->putSphere(11, 10, 25, 2);
    s->putSphere(8, 05, 23, 2);

    // Cor das esferas de fumaça
    s->setColor(0.5, 0.5, 0.5, 0.1);

    // Fluxo de escrita para o arquivo OFF.
    // Arquivo txt para visualização do que foi escrito.
    s->writeOFF("caneca.txt");
    s->writeOFF("caneca.off");

    // Destrutor.
    s->~Sculptor();

    return 0;
}
