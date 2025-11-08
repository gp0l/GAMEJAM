#pragma once
#include "Figura.h"
using namespace System;
using namespace System::Drawing;


class Triangulo : public Figura {
public:
    Triangulo(int x, int y, int ancho, int alto, bool movimientoAutomatico);
    void dibujar(Graphics^ graphics) override;
};
