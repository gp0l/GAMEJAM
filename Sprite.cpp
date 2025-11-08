#include "Sprite.h"
#include <cstring>

Sprite::Sprite() {
    x = 0;
    y = 0;
    dx = 0;
    dy = 0;
    indiceX = 0;
    indiceY = 0;
    ancho = 0;
    alto = 0;
    filas = 0;
    columnas = 0;
    image = new char[100];
}

Sprite::Sprite(int x, int y) {
    this->x = x;
    this->y = y;
    dx = 0;
    dy = 0;
    indiceX = 0;
    indiceY = 0;
    ancho = 0;
    alto = 0;
    filas = 0;
    columnas = 0;
    image = new char[100];
}

Sprite::~Sprite() {
    if (image != nullptr) {
        delete[] image;
    }
}

void Sprite::cargarImagen(char* ruta, int filas, int columnas) {
    strcpy_s(image, 100, ruta);
    this->filas = filas;
    this->columnas = columnas;

    Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(image));
    ancho = bitmap->Width / columnas;
    alto = bitmap->Height / filas;
    delete bitmap;
}

int Sprite::getX() { return x; }
int Sprite::getY() { return y; }
int Sprite::getAncho() { return ancho; }
int Sprite::getAlto() { return alto; }
int Sprite::getFilas() { return filas; }
int Sprite::getColumnas() { return columnas; }
void Sprite::setX(int x) { this->x = x; }
void Sprite::setY(int y) { this->y = y; }
