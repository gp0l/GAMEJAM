#pragma once
#include "Poligono.h"
class Octagono :
    public Poligono
{
public:
    Octagono(int x, int y, int ancho, int alto, bool movimientoAutomatico);
    void dibujar(Graphics^ graphics) override;
};

