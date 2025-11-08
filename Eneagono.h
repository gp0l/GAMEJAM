#pragma once
#include "Poligono.h"
class Eneagono :
    public Poligono
{
public:
    Eneagono(int x, int y, int ancho, int alto, bool movimientoAutomatico);
    void dibujar(Graphics^ graphics) override;
};

