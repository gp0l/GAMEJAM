#include "Cuadrado.h"

Cuadrado::Cuadrado(int x, int y, int tamano, int r, int g, int b, bool relleno)
    : Figura(x, y, tamano, tamano, r, g, b, relleno) {
}

void Cuadrado::dibujar(Graphics^ graphics) {
    Color color = Color::FromArgb(r, g, b);

    if (relleno) {
        SolidBrush^ brush = gcnew SolidBrush(color);
        graphics->FillRectangle(brush, x, y, ancho, alto);        
    }
    else {
        Pen^ pen = gcnew Pen(color, 2);
        graphics->DrawRectangle(pen, x, y, ancho, alto);        
    }
}

