#pragma once
#include "Figura.h"
#include <cmath>
class Pentagono :
    public Figura
{
public:
    Pentagono(int x, int y, int ancho, int alto, bool movimientoAutomatico);
    void dibujar(Graphics^ graphics) override;
};

