#include "Sculptor.h"
#include <iostream>
#include <fstream>

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx; ny = _ny; nz = _nz;

    v = new Voxel** [nx];
    std::cout << "Primeira parte da alocacao completa." << std::endl;

    for(int i =0; i < nx; i++){
        v[i] = new Voxel* [ny];
        for(int j = 0; j < ny; j++){
            v[i][j] = new Voxel [nz];
        }
    }
    std::cout << "Segunda parte da alocacao completa." << std::endl;

    for (int xi = 0; xi < nx; xi++) {
      for (int yi = 0; yi < ny; yi++) {
        for (int zi = 0; zi < nz; zi++) {
          v[xi][yi][zi].show = true;
        }
      }
    }
    std::cout << "Definicao da caracteristica show dentro do contrutor completa." << std::endl;

}

Sculptor::~Sculptor()
{
  delete[] v[0][0];
  delete[] v[0];
  delete[] v;
}

void Sculptor::writeOFF(const char* filename)
{
    std::ofstream file(filename);

    if (!(file.is_open()))
    {
        std::cerr << "Erro ao gerar o arquivo: "<< filename << std::endl;
        return;
    }

    std::cerr << "Arquivo gerado: "<< filename << std::endl;

    file << "OFF" << std::endl;

    file.close();
}

