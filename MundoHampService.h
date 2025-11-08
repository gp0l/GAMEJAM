#pragma once
#include "Mario.h"
#include "Hamp.h"
#include "Pikachu.h"
#include <vector>

using namespace System;
using namespace System::Drawing;
using namespace std;

class MundoHampService {
private:
    Mario* mario;
    Hamp* hamp;
    vector<Pikachu*> pikachus;
    int anchoPanel;
    int altoPanel;

public:
    MundoHampService(int ancho, int alto);
    ~MundoHampService();

    void cargarSpriteMario(char* ruta, int filas, int columnas);
    void cargarSpriteHamp(char* ruta, int filas, int columnas);
    void agregarPikachu(int x, int y, char* ruta, int filas, int columnas, int tipoMovimiento);

    void moverMario(Direccion tecla);
    void moverHamp(Direccion tecla);
    void moverPikachus();

    void dibujarTodo(Graphics^ canvas);

    Mario* getMario() { return mario; }
    Hamp* getHamp() { return hamp; }
    vector<Pikachu*>& getPikachus() { return pikachus; }
};
