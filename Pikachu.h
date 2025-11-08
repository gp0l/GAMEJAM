#pragma once
#include "Sprite.h"

class Pikachu : public Sprite {
public:
    int energia;
    int ataque;
    int tipoMovimiento;

    Pikachu();
    Pikachu(int x, int y);
    Pikachu(int x, int y, int tipoMovimiento);
    ~Pikachu();

    void mover(Direccion tecla, int limiteAncho, int limiteAlto) override;
    void dibujar(Graphics^ canvas) override;
};
