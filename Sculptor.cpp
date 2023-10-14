#include "Sculptor.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using std::fixed;
using std::setprecision;

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
          v[xi][yi][zi].show = false;
          v[xi][yi][zi].r = 0.0;
          v[xi][yi][zi].b = 0.0;
          v[xi][yi][zi].g = 0.0;
          v[xi][yi][zi].a = 1.0;
          //std::cout << v[xi][yi][zi].show << " ";
        }
        //std::cout << std::endl;
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
    std::cout.precision(2);
    std::cout.setf(std::ios::fixed);
    // file << setprecision(1) << fixed;
    // file << std::fixed << std::setprecision(1);


    if (!(file.is_open()))
    {
        std::cerr << "Erro ao gerar o arquivo: "<< filename << std::endl;
        return;
    }

    std::cerr << "Arquivo gerado: "<< filename << std::endl;

    file << "OFF" << std::endl;

    int n_v = 0; /* número de vértices */
    int n_f = 0; /* número de faces */
    int ni = 0; /* iteração atual */
    float r, g, b, a; /* tom RGB e transparência */

    for (int xi = 0; xi < nx; xi++) {
        for (int yi = 0; yi < ny; yi++) {
          for (int zi = 0; zi < nz; zi++) {
            if (v[xi][yi][zi].show)
            {
              n_v += 8;
              n_f += 6;
            }
          }
        }
    }

    file << n_v << " " << n_f << " " << 0 << std::endl;

    for (int xi = 0; xi < nx; xi++) {
        for (int yi = 0; yi < ny; yi++) {
            for (int zi = 0; zi < nz; zi++) {
                if (v[xi][yi][zi].show)
                {
                  file << xi - 0.5 << " " << yi + 0.5 << " " << zi - 0.5 << std::endl;
                  file << xi - 0.5 << " " << yi - 0.5 << " " << zi - 0.5 << std::endl;
                  file << xi + 0.5 << " " << yi - 0.5 << " " << zi - 0.5 << std::endl;
                  file << xi + 0.5 << " " << yi + 0.5 << " " << zi - 0.5 << std::endl;
                  file << xi - 0.5 << " " << yi + 0.5 << " " << zi + 0.5 << std::endl;
                  file << xi - 0.5 << " " << yi - 0.5 << " " << zi + 0.5 << std::endl;
                  file << xi + 0.5 << " " << yi - 0.5 << " " << zi + 0.5 << std::endl;
                  file << xi + 0.5 << " " << yi + 0.5 << " " << zi + 0.5 << std::endl;
                }
            }
        }
    }

    for (int xi = 0; xi < nx; xi++) {
        for (int yi = 0; yi < ny; yi++) {
            for (int zi = 0; zi < nz; zi++) {
                if (v[xi][yi][zi].show)
                {
                  r = v[xi][yi][zi].r;
                  g = v[xi][yi][zi].g;
                  b = v[xi][yi][zi].b;
                  a = v[xi][yi][zi].a;


                  file << 4 << " " << 0 + ni << " " << 3 + ni << " " << 2 + ni << " " << 1 + ni << " " << setprecision(1) << fixed << r << " " << setprecision(1) << fixed << g << " " << setprecision(1) << fixed << b << " " << setprecision(1) << fixed << a << std::endl;
                  file << 4 << " " << 4 + ni << " " << 5 + ni << " " << 6 + ni << " " << 7 + ni << " " << setprecision(1) << fixed << r << " " << setprecision(1) << fixed << g << " " << setprecision(1) << fixed << b << " " << setprecision(1) << fixed << a << std::endl;
                  file << 4 << " " << 0 + ni << " " << 1 + ni << " " << 5 + ni << " " << 4 + ni << " " << setprecision(1) << fixed << r << " " << setprecision(1) << fixed << g << " " << setprecision(1) << fixed << b << " " << setprecision(1) << fixed << a << std::endl;
                  file << 4 << " " << 0 + ni << " " << 4 + ni << " " << 7 + ni << " " << 3 + ni << " " << setprecision(1) << fixed << r << " " << setprecision(1) << fixed << g << " " << setprecision(1) << fixed << b << " " << setprecision(1) << fixed << a << std::endl;
                  file << 4 << " " << 3 + ni << " " << 7 + ni << " " << 6 + ni << " " << 2 + ni << " " << setprecision(1) << fixed << r << " " << setprecision(1) << fixed << g << " " << setprecision(1) << fixed << b << " " << setprecision(1) << fixed << a << std::endl;
                  file << 4 << " " << 1 + ni << " " << 2 + ni << " " << 6 + ni << " " << 5 + ni << " " << setprecision(1) << fixed << r << " " << setprecision(1) << fixed << g << " " << setprecision(1) << fixed << b << " " << setprecision(1) << fixed << a << std::endl;

                  ni += 8;
            }
          }
        }
      }

      std::cout << "Projeto gerado com sucesso!" << std::endl;

    file.close();
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){

    for(int i = x0; i < x1; i++){
        for(int j = y0; j < y1; j++){
            for(int k = z0; k < z1; k++){
                //std::cout << "x1: " << i << " y1: " << j << " z1: " << k << std::endl;
                v[i][j][k].show = true;
                /*v[i][j][k].r = (float)Sculptor::r;
                v[i][j][k].b = (float)Sculptor::b;
                v[i][j][k].g = (float)Sculptor::g;
                v[i][j][k].a = (float)Sculptor::a;*/

            }
        }
    }

   /* for (int xi = 0; xi < nx; xi++) {
      for (int yi = 0; yi < ny; yi++) {
        for (int zi = 0; zi < nz; zi++) {
          std::cout << v[xi][yi][zi].show << " ";
        }
        std::cout << std::endl;
      }
    }*/

}

void Sculptor::setColor(float r, float g, float b, float a){

    for (int xi = 0; xi < nx; xi++) {
      for (int yi = 0; yi < ny; yi++) {
        for (int zi = 0; zi < nz; zi++) {
            if( (v[xi][yi][zi].show) && ((v[xi][yi][zi].r == 0) && (v[xi][yi][zi].g == 0) && (v[xi][yi][zi].b == 0)) ){
                v[xi][yi][zi].r = r;
                v[xi][yi][zi].g = g;
                v[xi][yi][zi].b = b;
                v[xi][yi][zi].a = a;
            }
        }
      }
    }

    std::cout << "r, g, b, a: " << r << " " << g << " " << b << " " << a << std::endl;

}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){

    for(int i = x0; i < x1; i++){
        for(int j = y0; j < y1; j++){
            for(int k = z0; k < z1; k++){
                v[i][j][k].show = false;
            }
        }
    }

}

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].show = true;
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].show = false;
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){

    /* v[xcenter][ycenter][zcenter] = O ponto do centro da esfera.
        Pra saber os pontos que estão dentro do raio, temos que fazer
        sqrt((xi - xcenter)^2 + (yi - ycenter)^2 + (zi - zcenter)^2) = radius
    */

    // B
    for (int xi = 0; xi < nx; xi++) {
      for (int yi = 0; yi < ny; yi++) {
        for (int zi = 0; zi < nz; zi++) {
            if( sqrt(pow((xi - xcenter), 2) + pow((yi - ycenter), 2) + pow((zi - zcenter), 2)) <= radius ){
                v[xi][yi][zi].show = true;
            }
        }
      }
    }


}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){

    for (int xi = 0; xi < nx; xi++) {
      for (int yi = 0; yi < ny; yi++) {
        for (int zi = 0; zi < nz; zi++) {
            if( sqrt(pow((xi - xcenter), 2) + pow((yi - ycenter), 2) + pow((zi - zcenter), 2)) <= radius ){
                v[xi][yi][zi].show = false;
            }
        }
      }
    }


}
