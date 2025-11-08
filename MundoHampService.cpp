#include "MundoHampService.h"
#include <cstdlib>
#include <ctime>

MundoHampService::MundoHampService(int ancho, int alto) {
    anchoPanel = ancho;
    altoPanel = alto;
    mario = new Mario(100, 100);
    hamp = new Hamp(300, 100);
    srand(time(NULL));
}

MundoHampService::~MundoHampService() {
    delete mario;
    delete hamp;
    for (int i = 0; i < pikachus.size(); i++) {
        delete pikachus[i];
    }
    pikachus.clear();
}

void MundoHampService::cargarSpriteMario(char* ruta, int filas, int columnas) {
    mario->cargarImagen(ruta, filas, columnas);
}

void MundoHampService::cargarSpriteHamp(char* ruta, int filas, int columnas) {
    hamp->cargarImagen(ruta, filas, columnas);
}

void MundoHampService::agregarPikachu(int x, int y, char* ruta, int filas, int columnas, int tipoMovimiento) {
    Pikachu* pikachu = new Pikachu(x, y, tipoMovimiento);
    pikachu->cargarImagen(ruta, filas, columnas);
    pikachus.push_back(pikachu);
}

void MundoHampService::moverMario(Direccion tecla) {
    mario->mover(tecla, anchoPanel, altoPanel);
}

void MundoHampService::moverHamp(Direccion tecla) {
    hamp->mover(tecla, anchoPanel, altoPanel);
}

void MundoHampService::moverPikachus() {
    for (int i = 0; i < pikachus.size(); i++) {
        pikachus[i]->mover(Direccion::Ninguno, anchoPanel, altoPanel);
    }
}

void MundoHampService::dibujarTodo(Graphics^ canvas) {
    //mario->dibujar(canvas);
    hamp->dibujar(canvas);
    for (int i = 0; i < pikachus.size(); i++) {
        pikachus[i]->dibujar(canvas);
    }
}
