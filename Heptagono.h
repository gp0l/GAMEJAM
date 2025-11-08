#pragma once
#include "Figura.h"
class Heptagono : public Figura
{
public:
	Heptagono(int x, int y, int ancho, int alto, bool movimientoAutomatico);
	void dibujar(Graphics^ graphics) override;
};

