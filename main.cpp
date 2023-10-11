#include <iostream>
#include "Sculptor.h"
#include <fstream>

int main()
{
    int nl, nc, np;
    int t1, t2, t3;
    //int r, g, b, a = 1.1;
    t1 = 1, t2 = 1, t3 = 1;

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


    s->putBox(0, t1, 0, t2, 0, t3);
    s->setColor(0.0, 0, 1, 1);
    s->putBox(t1, t1*2, t2, t2*2, t3, 2*t3);
    s->setColor(0.0, 1, 0, 1);



    s->writeOFF("outputbox.txt");
    s->writeOFF("outputbox.off");


    return 0;
}
