#pragma once
#include "Figura.h"
class Decagono :
    public Figura
{
public:
    Decagono(int x, int y, int ancho, int alto, bool movimientoAutomatico);
    void dibujar(Graphics^ graphics) override;
};

