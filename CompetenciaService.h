#pragma once
#include "Triangulo.h"
#include "Rectangulo.h"
#include "Rombo.h"
#include <vector>
using namespace System;
using namespace std;
using namespace System::Drawing;

class CompetenciaService {
private:
    vector<Figura*> figuras;
    vector<int> puntajes;
    int limiteAncho, limiteAlto;
    int lineaMeta;
    int partidaActual;

public:
    // Inicialización
    CompetenciaService(int ancho, int alto);
    ~CompetenciaService();

    // Iniciar juego
    void iniciarPartida();

    // Mover competidores
    void moverFiguras();

    // Verificar ganador
    void verificarMeta();

    // Reiniciar posiciones
    void reiniciarFiguras();

    // Renderizar escena
    void dibujar(Graphics^ graphics);

    // Obtener partida
    int getPartidaActual();

    // Obtener puntajes
    vector<int> getPuntajes();

    // Obtener ganador
    int getGanador();

    // Verificar fin
    bool juegoTerminado();
};