#pragma once
#include "Casa.h"
#include <vector>

using namespace System::Drawing;
using namespace std;

class MovimientoCasaService
{
private:
	vector<Figura*> figuras;

public:
	
	MovimientoCasaService();
	~MovimientoCasaService();	
	void agregarCasa(int x, int y, int ancho, int alto, int r, int g, int b);	
	void dibujarFiguras(Graphics^ g);	
	void moverFigurasAutomatico(int anchoForm, int altoForm);
	int getCantidadFiguras();
};
