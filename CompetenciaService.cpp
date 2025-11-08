#include "CompetenciaService.h"
#include <cstdlib>
#include <ctime>

// Constructor
CompetenciaService::CompetenciaService(int ancho, int alto) {
    srand(time(0));

    limiteAncho = ancho;
    limiteAlto = alto;
    lineaMeta = ancho - 100;
    partidaActual = 0;

    // Crear 3 figuras (Triangulo, Rectangulo, Rombo)
    int espacioVertical = alto / 4;

    // Triangulo (arriba)
    Triangulo* triangulo = new Triangulo(50, espacioVertical, 80, 80, 0, 255, 0, true);
    triangulo->setSeMueve(true);
    triangulo->setDirX(1);
    triangulo->setDirY(0);
    figuras.push_back(triangulo);
    puntajes.push_back(0);

    // Rectangulo (medio)
    Rectangulo* rectangulo = new Rectangulo(50, espacioVertical * 2, 80, 80, 255, 0, 0, true);
    rectangulo->setSeMueve(true);
    rectangulo->setDirX(1);
    rectangulo->setDirY(0);
    figuras.push_back(rectangulo);
    puntajes.push_back(0);

    // Rombo (abajo)
    Rombo* rombo = new Rombo(50, espacioVertical * 3, 80, 80, 255, 255, 0, true);
    rombo->setSeMueve(true);
    rombo->setDirX(1);
    rombo->setDirY(0);
    figuras.push_back(rombo);
    puntajes.push_back(0);
}

// Destructor
CompetenciaService::~CompetenciaService() {
    for each (Figura * fig in figuras) {
        delete fig;
    }
}

// Iniciar juego
void CompetenciaService::iniciarPartida() {
    partidaActual = 1;
    puntajes[0] = 0;
    puntajes[1] = 0;
    puntajes[2] = 0;
    reiniciarFiguras();
}

// Mover competidores
void CompetenciaService::moverFiguras() {
    if (partidaActual > 0 && !juegoTerminado()) {
        for (int i = 0; i < figuras.size(); i++) {
            figuras[i]->mover(limiteAncho, limiteAlto);
        }
    }
}

// Verificar ganador
void CompetenciaService::verificarMeta() {
    if (partidaActual > 0 && !juegoTerminado()) {
        for (int i = 0; i < figuras.size(); i++) {
            if (figuras[i]->getX() >= lineaMeta) {
                // Una figura cruzó la meta
                puntajes[i]++;
                partidaActual++;
                reiniciarFiguras();
                return;
            }
        }
    }
}

// Reiniciar posiciones
void CompetenciaService::reiniciarFiguras() {
    int espacioVertical = limiteAlto / 4;
    for (int i = 0; i < figuras.size(); i++) {
        figuras[i]->setX(50);
        figuras[i]->setY(espacioVertical * (i + 1));
        figuras[i]->setDirX(rand() % 5 + 1);
    }
}

// Renderizar escena
void CompetenciaService::dibujar(Graphics^ graphics) {
    // Dibujar línea de meta
    Pen^ penMeta = gcnew Pen(Color::Black, 3);
    graphics->DrawLine(penMeta, lineaMeta, 0, lineaMeta, limiteAlto);

    // Dibujar texto "META"
    Font^ font = gcnew Font("Arial", 16, FontStyle::Bold);
    graphics->DrawString("META", font, Brushes::Black, (float)lineaMeta - 40, 10);

    // Dibujar figuras
    for each (Figura * fig in figuras) {
        fig->dibujar(graphics);
    }

    // Dibujar puntajes
    Font^ fontPuntaje = gcnew Font("Arial", 12);
    int y = 20;
    graphics->DrawString("Triangulo: " + puntajes[0], fontPuntaje, Brushes::Green, 10.0f, (float)y);
    y += 30;
    graphics->DrawString("Rectangulo: " + puntajes[1], fontPuntaje, Brushes::Red, 10.0f, (float)y);
    y += 30;
    graphics->DrawString("Rombo: " + puntajes[2], fontPuntaje, Brushes::Bisque, 10.0f, (float)y);
    y += 30;
    int partidaMostrar = partidaActual <= 3 ? partidaActual : 3;
    graphics->DrawString("Partida: " + partidaMostrar + " / 3", fontPuntaje, Brushes::Black, 10.0f, (float)y);
}

// Obtener partida
int CompetenciaService::getPartidaActual() {
    return partidaActual;
}

// Obtener puntajes
vector<int> CompetenciaService::getPuntajes() {
    return puntajes;
}

// Obtener ganador
int CompetenciaService::getGanador() {
    if (!juegoTerminado()) {
        return -1;  // Juego no terminado
    }

    int maxPuntaje = puntajes[0];
    int ganador = 0;

    for (int i = 1; i < puntajes.size(); i++) {
        if (puntajes[i] > maxPuntaje) {
            maxPuntaje = puntajes[i];
            ganador = i;
        }
    }

    // Verificar si hay empate
    int cantidadConMaxPuntaje = 0;
    for (int i = 0; i < puntajes.size(); i++) {
        if (puntajes[i] == maxPuntaje) {
            cantidadConMaxPuntaje++;
        }
    }

    if (cantidadConMaxPuntaje > 1) {
        return -2;  // Empate (mas de uno con el máximo puntaje)
    }

    return ganador;
}

// Verificar fin
bool CompetenciaService::juegoTerminado() {
    return partidaActual > 3;
}