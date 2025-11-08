#pragma once
#include "Poligono.h"
class Hexagono :
    public Poligono
{
public:
    Hexagono(int x, int y, int ancho, int alto, bool movimientoAutomatico);
    void dibujar(Graphics^ graphics) override;
};

