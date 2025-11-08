#include "JuegoService.h"
#include <cstdlib>
#include <ctime>

// Constructor
JuegoService::JuegoService(int ancho, int alto) {
    srand((unsigned int)time(NULL));

    limiteAncho = ancho;
    limiteAlto = alto;

    // Circulo controlable (izquierda)
    circulo = new Circulo(50, alto / 2 - 30, 60, 0, 0, 255, true);
    circulo->setSeMueve(true);  // El círculo siempre puede moverse

    // 3 Figuras fijas en la parte derecha (colocadas uno debajo de otro)
    int xDerecha = ancho - 120;
    int espacio = 100;

    // Triángulo
    Triangulo* tri = new Triangulo(xDerecha, 50, 80, 80, 0, 255, 0, true);
    tri->setNumero(rand() % 10 + 1);
    //figurasFijas.push_back(tri);

    // Rectángulo (Cuadrado)
    Rectangulo* rect = new Rectangulo(xDerecha, 50 + espacio, 80, 80, 255, 0, 0, true);
    rect->setNumero(rand() % 10 + 1);
    figurasFijas.push_back(rect);

    // Rombo
    Rombo* rombo = new Rombo(xDerecha, 50 + espacio * 2, 80, 80, 255, 255, 0, true);
    rombo->setNumero(rand() % 10 + 1);
    figurasFijas.push_back(rombo);
}

// Destructor
JuegoService::~JuegoService() {
    if (circulo) delete circulo;
    for each (Figura * fig in figurasFijas) delete fig;
    for each (Figura * fig in figurasLanzadas) delete fig;
}

// Mover jugador
void JuegoService::moverCirculo(int dy) {
    // Configurar dirección y mover círculo
    circulo->setDirY(dy);
    circulo->mover(limiteAncho, limiteAlto);
    circulo->setDirY(0);
}

// Lanzar figuras
void JuegoService::lanzarFigura() {
    // Posición de lanzamiento (desde el círculo)
    int x = circulo->getX() + circulo->getAncho();
    int y = circulo->getY() + circulo->getAlto() / 2 - 40;

    // Tipo aleatorio: 0=Triángulo, 1=Rectángulo, 2=Rombo
    int tipo = rand() % 3;
    Figura* figura = nullptr;

    if (tipo == 0) {
       // figura = new Triangulo(x, y, 80, 80, 0, 255, 0, true);
    }
    else if (tipo == 1) {
        figura = new Rectangulo(x, y, 80, 80, 255, 0, 0, true);
    }
    else {
        figura = new Rombo(x, y, 80, 80, 255, 255, 0, true);
    }

    // Configurar movimiento horizontal
    figura->setNumero(rand() % 10 + 1);
    figura->setSeMueve(true);
    figura->setDirX(1);  // Mover a la derecha
    figura->setDirY(0);  // No mover verticalmente

    figurasLanzadas.push_back(figura);
}

// Actualizar figuras
void JuegoService::moverFiguras() {
    // Mover y filtrar figuras lanzadas
    for (int i = 0; i < figurasLanzadas.size(); i++) {
        figurasLanzadas[i]->mover(limiteAncho, limiteAlto);

        // Eliminar si salió de los límites
        if (figurasLanzadas[i]->getX() >= limiteAncho) {
            delete figurasLanzadas[i];
            figurasLanzadas.erase(figurasLanzadas.begin() + i);
            i--;  // Decrementar para compensar la eliminación
        }
    }
}

// Verificar impactos
void JuegoService::verificarColisiones() {
    for (int i = 0; i < figurasLanzadas.size(); i++) {
        Figura* figLanzada = figurasLanzadas[i];

        // Verificar colisión con figuras fijas
        for each (Figura * figFija in figurasFijas) {
            if (figLanzada->getRectangulo().IntersectsWith(figFija->getRectangulo())) {
                // Verificar si son del mismo tipo
                if ((dynamic_cast<Triangulo*>(figLanzada) && dynamic_cast<Triangulo*>(figFija)) ||
                    (dynamic_cast<Rectangulo*>(figLanzada) && dynamic_cast<Rectangulo*>(figFija)) ||
                    (dynamic_cast<Rombo*>(figLanzada) && dynamic_cast<Rombo*>(figFija))) {
                    // Mismo tipo: sumar números
                    figFija->setNumero(figFija->getNumero() + figLanzada->getNumero());
                }
                // En ambos casos (mismo tipo o diferente), eliminar figura lanzada
                delete figLanzada;
                figurasLanzadas.erase(figurasLanzadas.begin() + i);
                i--;  // Decrementar para compensar la eliminación
                break;
            }
        }
    }
}

// Renderizar escena
void JuegoService::dibujar(Graphics^ graphics) {
    // Solo dibuja, no modifica el estado del juego
    circulo->dibujar(graphics);

    for each (Figura * figura in figurasFijas) {
        figura->dibujar(graphics);
    }

    for each (Figura * figura in figurasLanzadas) {
        figura->dibujar(graphics);
    }
}