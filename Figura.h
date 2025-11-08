#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
enum Direccion { IZQUIERDA, DERECHA, ARRIBA, ABAJO, NINGUNO };

class Figura {
protected:
    int x, y;
    int ancho, alto;
    int color;
    int dirX, dirY;
    bool movimientoAutonomo;
    int numero;
    float sumaDeAngulos;

public:
    Figura(int x, int y, int ancho, int alto, int lados, bool movimientoAutonomo);
    Figura(int x, int y, int ancho, int alto, int lados, bool movimientoAutonomo, int numero);
    ~Figura();

    int getSumaDeLados();
    int getX();
    int getY();
    int getAncho();
    int getAlto();
	int getColor();
	bool getMovimientoAutonomo();
    int getDirX();
    int getDirY();
    int getNumero();

    void setX(int x);
    void setY(int y);
    void setDirX(int dirX);
    void setDirY(int dirY);
    void setSeMueve(bool seMueve);
    void setNumero(int numero);

    void mover(int limiteAncho, int limiteAlto);
    virtual void dibujar(Graphics^ graphics) = 0;
    Rectangle getRectangulo();
};