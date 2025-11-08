#pragma once
#include "Sprite.h"

class Hamp : public Sprite {
public:
    int vida;
    int velocidad;

    Hamp();
    Hamp(int x, int y);
    ~Hamp();

    void mover(Direccion tecla, int limiteAncho, int limiteAlto) override;
    void dibujar(Graphics^ canvas) override;
};
