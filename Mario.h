#pragma once
#include "Sprite.h"

class Mario : public Sprite {
public:
    int vidas;
    int puntos;

    Mario();
    Mario(int x, int y);
    ~Mario();

    void mover(Direccion tecla, int limiteAncho, int limiteAlto) override;
    void dibujar(Graphics^ canvas) override;
};
