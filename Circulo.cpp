#include "Circulo.h"


Circulo::Circulo(int x, int y, int diametro, int r, int g, int b, bool relleno)
    : Figura(x, y, diametro, diametro, r, g, b, relleno) {
}

void Circulo::dibujar(Graphics^ graphics) {
	Color color = Color::FromArgb(r, g, b);

    if (relleno) {
        // Dibujar relleno
        SolidBrush^ brush = gcnew SolidBrush(color);
        graphics->FillEllipse(brush, x, y, ancho, alto);
        delete brush;

        // Dibujar borde
        Pen^ pen = gcnew Pen(Color::Black, 2);
        graphics->DrawEllipse(pen, x, y, ancho, alto);
        delete pen;
    }
    else {
        Pen^ pen = gcnew Pen(color, 2);
        graphics->DrawEllipse(pen, x, y, ancho, alto);
        delete pen;
    }
}

