#pragma once
#include "Circulo.h"
#include "Triangulo.h"
#include "Rectangulo.h"
#include "Rombo.h"
#include <vector>
using namespace System;
using namespace std;
using namespace System::Drawing;

class JuegoService {
private:
    Circulo* circulo;
    vector<Figura*> figurasFijas;
    vector<Figura*> figurasLanzadas;
    int limiteAncho, limiteAlto;

public:
    // Inicialización
    JuegoService(int ancho, int alto);
    ~JuegoService();

    // Mover jugador
    void moverCirculo(int dy);

    // Lanzar figuras
    void lanzarFigura();

    // Actualizar figuras
    void moverFiguras();

    // Verificar impactos
    void verificarColisiones();

	// Dibujar escena (figuras)
    void dibujar(Graphics^ graphics);
};