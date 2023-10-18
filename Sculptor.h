#ifndef SCULPTOR_H
#define SCULPTOR_H

/// A estrutura Voxel é um objeto que possui características de cor, transparência e visibilidade.
/// Todos os outros parâmetros, com exceção do <b>show<b> podem receber valores dentro do intervalo [0,1].
///< @param (float) r Define a intensidade de cor vermelha do voxel.
///< @param (float) g Define a intensidade de cor verde no voxel.
///< @param (float) b Define a intensidade de cor azul no Voxel.
///< @param (bool) a Define a transparencia de um Voxel.
///< @param show Define se o Voxel será visível ou não.
struct Voxel
{
    float r,g,b;
    float a;
    bool show;
};

/**
* @brief A classe Sculptor possui diversos métodos usados para criar as esculturas/objetos. Essas esculturas/objetos são baseados
* na estrutura Voxel. Esses Voxels são manipulados usandos os métodos que possibilitam criar estruturas geométricas a partir
* de objetos únicos ou blocos de Voxels, estes Voxels manipulados fazem parte de um espaço de três dimensões criado a partir de
* uma matriz 3D alocada dinâmicamente.
*/
class Sculptor
{

private:
    Voxel ***v; // 3D matrix
    int nx,ny,nz; // Dimensions
    float r,g,b,a; // Current drawing color
public:
/**
 * @fn Sculptor(int _nx, int _ny, int _nz)
 * @brief É o construtor o qual aloca o espaço de memória para uma matriz 3D que será usada para fazer a escultura. O tipo dos elementos da matriz alocada é Voxel.
 * @param _nx (int) - Dimensão x da matriz.
 * @param _ny (int) - Dimensão y da matriz.
 * @param _nz (int) - Dimensão z da matriz.
*/
    Sculptor(int _nx, int _ny, int _nz); //

/**
* É o método "destrutor" da memórica alocada para criação da matriz 3D que possibilita a criação da escultura.
*/
    ~Sculptor(); //

/**
*  @fn setColor(float r, float g, float b, float a);
*  @brief a função setColor irá definir as cores de uma estrutura criada, seja um Voxel único ou um conjunto. Deve ser usada após
*  os métodos de construção de uma estrutura. Todos os parâmetros dessa função devem receber valores dentro do intervalo [0,1].
*  @param (float) r Define a intensidade de cor vermelha do voxel.
*  @param (float) g Define a intensidade de cor verde no voxel.
*  @param (float) b Define a intensidade de cor azul no Voxel.
*  @param (bool) a Define a transparencia de um Voxel.
*/
    void setColor(float r, float g, float b, float a); //

/**
*@brief o método putVoxel irá criar um único Voxel em uma posição definida pelo usuário. Os parâmentros x, y e z são os índices
*da matriz referentes a posição no espaço de construção onde Voxel sera colocado. e.g. m[x][y][z] - Um Voxel será adicionado nesta
*posição.
*@param x (int) - Coordenada x da matriz alocada para construção.
*@param y (int) - Coordenada y da matriz alocada para construção.
*@param z (int) - Coordenada z da matriz alocada para construção.
*/
    void putVoxel(int x, int y, int z); //

/**
* @brief O métodos cutVoxel retira um único Voxel de uma posição definida pelo usuário. Os parâmentros x, y e z são os índices da
* matriz referentes a posição no espaço de construção de onde Voxel sera removido. e.g. m[x][y][z] - Voxel desta posição será
* removido.
*@param x (int) - Coordenada x da matriz alocada para construção.
*@param y (int) - Coordenada y da matriz alocada para construção.
*@param z (int) - Coordenada z da matriz alocada para construção.
*/
    void cutVoxel(int x, int y, int z); //

/**
* @brief O método putBox cria uma estrutura similar a uma "caixa" a partir dos parâmetro x, y e z que representam as coordenadas
* de ínicio da escultura e x0, y0 e z0, as coordenadas limite da escultura.
* A estrutura terá dimensões (x1-x0) x (y1-y0) x (z1-z0).
* @param x0 (int) - Indica a posição inicial no eixo X para construção.
* @param x1 (int) - Indica a posição final no eixo X para construção.
* @param y0 (int) - Indica a posição inicial no eixo Y para construção.
* @param y1 (int) - Indica a posição final no eixo Y para construção.
* @param z0 (int) - Indica a posição inicial no eixo Z para construção.
* @param z1 (int) - Indica a posição final no eixo Z para construção.
*/
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1); //

/**
* O método cutBox remove uma estrutura similar a uma "caixa" a partir dos parâmetro x, y e z que representam as coordenadas
* de ínicio da remoção e x0, y0 e z0, as coordenadas limite da remoção.
* A área removida terá dimensões (x1-x0) x (y1-y0) x (z1-z0).
* @param x0 (int) - Indica a posição inicial no eixo X para remoção.
* @param x1 (int) - Indica a posição final no eixo X para remoção.
* @param y0 (int) - Indica a posição inicial no eixo Y para remoção.
* @param y1 (int) - Indica a posição final no eixo Y para remoção.
* @param z0 (int) - Indica a posição inicial no eixo Z para remoção.
* @param z1 (int) - Indica a posição final no eixo Z para remoção.
*/
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1); //

/**
* @brief O método putShpere cria uma estrutura similiar a uma esfera usando Voxels.
*@param (int) xcenter - Indica a posição do centro da esfera no eixo X.
*@param (int) ycenter - Indica a posição do centro da esfera no eixo Y.
*@param (int) zcenter - Indica a posição do centro da esfera no eixo Z.
*@param (int) radius - Indica o tamanho do raio da esfera.
*/
    void putSphere(int xcenter, int ycenter, int zcenter, int radius); //

/**
*@brief O método cutShpere remove uma área esférica de objetos.
*@param (int) xcenter - Indica a posição do centro da esfera no eixo X.
*@param (int) ycenter - Indica a posição do centro da esfera no eixo Y.
*@param (int) zcenter - Indica a posição do centro da esfera no eixo Z.
*@param (int) radius - Indica o tamanho do raio do espaço esférico a ser removido.
*/
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius); //

    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

/**
* @brief O método writeOFF cria um arquivo do tipo .off que contém a escultura resultante dos métodos usados.
* @param (const char*) filename - É um ponteiro para const char que deve receber o nome e tipo do arquivo que será gerado.
* e. g. writeOFF("sculptureFile.off");
*/
    void writeOFF(const char* filename); //
};

#endif // SCULPTOR_H
