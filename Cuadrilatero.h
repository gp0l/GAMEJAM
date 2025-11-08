#pragma once
#include "Figura.h"
class Cuadrilatero :
    public Figura
{
    Cuadrilatero(int x, int y, int ancho, int alto, bool movimientoAutomatico);
    void dibujar(Graphics^ graphics) override;
};

