#pragma once
#include "Poligono.h"
#include <cmath>
class Pentagono :
    public Poligono
{
public:
    Pentagono(int x, int y, int ancho, int alto, bool movimientoAutomatico);
    void dibujar(Graphics^ graphics) override;
};

