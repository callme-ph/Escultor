#include <iostream>
#include "Sculptor.h"
#include <fstream>

int main()
{
    int nl, nc, np;

    std::cout << "Iniciado.";

    std::cout << std::endl << "Quantidade de linhas: ";
    std::cin >> nl;
    std::cout << std::endl << "Quantidade de colunas: ";
    std::cin >> nc;
    std::cout << std::endl << "Quantidade de planos: ";
    std::cin >> np;

    Sculptor *s = new Sculptor(nl, nc, np);

    s->writeOFF("output.txt");

    delete s;

    return 0;
}
