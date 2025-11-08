#pragma once
#include "Figura.h"
class Eneagono :
    public Figura
{
public:
    Eneagono(int x, int y, int ancho, int alto, bool movimientoAutomatico);
    void dibujar(Graphics^ graphics) override;
};

