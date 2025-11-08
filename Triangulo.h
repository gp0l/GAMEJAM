#pragma once
#include "Poligono.h"
using namespace System;
using namespace System::Drawing;


class Triangulo : public Poligono {
public:
    Triangulo(int x, int y, int ancho, int alto, bool movimientoAutomatico);
    void dibujar(Graphics^ graphics) override;
};
