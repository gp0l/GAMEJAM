#pragma once
#include "Figura.h"
class Octagono :
    public Figura
{
public:
    Octagono(int x, int y, int ancho, int alto, bool movimientoAutomatico);
    void dibujar(Graphics^ graphics) override;
};

