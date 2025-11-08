#pragma once
#include "Poligono.h"
class Decagono :
    public Poligono
{
public:
    Decagono(int x, int y, int ancho, int alto, bool movimientoAutomatico);
    void dibujar(Graphics^ graphics) override;
};

