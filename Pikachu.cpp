#include "Pikachu.h"

Pikachu::Pikachu() : Sprite() {
    energia = 100;
    ataque = 50;
    tipoMovimiento = 0;
}

Pikachu::Pikachu(int x, int y) : Sprite(x, y) {
    energia = 100;
    ataque = 50;
    tipoMovimiento = 0;
}

Pikachu::Pikachu(int x, int y, int tipoMovimiento) : Sprite(x, y) {
    energia = 100;
    ataque = 50;
    this->tipoMovimiento = tipoMovimiento;
    if (tipoMovimiento == 0) {
        dx = 1;
        dy = 0;
        indiceY = 2;
    } else {
        dx = 0;
        dy = 1;
        indiceY = 0;
    }
}

Pikachu::~Pikachu() {
}

void Pikachu::mover(Direccion tecla, int limiteAncho, int limiteAlto) {
   

    indiceX++;
    if (indiceX >= columnas) indiceX = 0;

    x += dx * 7;
    y += dy * 7;

    if (tipoMovimiento == 0) {
        if (x <= 0) {
            x = 0;
            dx = 1;
            indiceY = 2;
        }
        if (x >= limiteAncho - ancho) {
            x = limiteAncho - ancho;
            dx = -1;
            indiceY = 1;
        }
    } else {
        if (y <= 0) {
            y = 0;
            dy = 1;
            indiceY = 0;
        }
        if (y >= limiteAlto - alto) {
            y = limiteAlto - alto;
            dy = -1;
            indiceY = 3;
        }
    }
}

void Pikachu::dibujar(Graphics^ canvas) {
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
        ancho * 1,
        alto * 1
    );

    canvas->DrawImage(bitmap, cuadroDestino, cuadroOrigen, GraphicsUnit::Pixel);
    delete bitmap;
}
