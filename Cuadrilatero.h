#pragma once
#include "Poligono.h"
class Cuadrilatero :
    public Poligono
{
    Cuadrilatero(int x, int y, int ancho, int alto, bool movimientoAutomatico);
    void dibujar(Graphics^ graphics) override;
};

