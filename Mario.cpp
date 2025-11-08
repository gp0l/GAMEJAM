#include "Mario.h"

Mario::Mario() : Sprite() {
    vidas = 3;
    puntos = 0;
}

Mario::Mario(int x, int y) : Sprite(x, y) {
    vidas = 3;
    puntos = 0;
}

Mario::~Mario() {
}

void Mario::mover(Direccion tecla, int limiteAncho, int limiteAlto) {
    if (tecla == Direccion::Ninguno) return;

    if (tecla == Direccion::Arriba)    { dx = 0;  dy = -1; indiceY = 3; }
    if (tecla == Direccion::Abajo)     { dx = 0;  dy = 1;  indiceY = 0; }
    if (tecla == Direccion::Izquierda) { dx = -1; dy = 0;  indiceY = 1; }
    if (tecla == Direccion::Derecha)   { dx = 1;  dy = 0;  indiceY = 2; }

    indiceX++;
    if (indiceX >= columnas) indiceX = 0;

    x += dx * 5;
    y += dy * 5;

    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x > limiteAncho - ancho * 2) x = limiteAncho - ancho * 2;
    if (y > limiteAlto - alto * 2) y = limiteAlto - alto * 2;
}

void Mario::dibujar(Graphics^ canvas) {
    if (ancho == 0 || alto == 0) return;

    Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(image));

    Rectangle cuadroOrigen = Rectangle(
        indiceX * ancho,
        indiceY * alto,
        ancho,
        alto
    );

    Rectangle cuadroDestino = Rectangle(
        x,
        y,
        ancho * 2,
        alto * 2
    );

    canvas->DrawImage(bitmap, cuadroDestino, cuadroOrigen, GraphicsUnit::Pixel);
    delete bitmap;
}
