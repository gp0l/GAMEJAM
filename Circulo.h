#pragma once
#include "Figura.h"

using namespace System;
using namespace System::Drawing;

class Circulo : public Figura {
public:
    Circulo(int x, int y, int diametro, bool relleno);
    void dibujar(Graphics^ graphics) override;
};