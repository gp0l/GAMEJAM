#pragma once
#include "Poligono.h"
class Heptagono : public Poligono
{
public:
	Heptagono(int x, int y, int ancho, int alto, bool movimientoAutomatico);
	void dibujar(Graphics^ graphics) override;
};

