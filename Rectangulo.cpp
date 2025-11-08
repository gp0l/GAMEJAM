#include "Rectangulo.h"

Rectangulo::Rectangulo(int x, int y, int ancho, int alto, int r, int g, int b, bool relleno)
    : Figura(x, y, ancho, alto, r, g, b, relleno) {
}

void Rectangulo::dibujar(Graphics^ graphics) {
    Color color = Color::FromArgb(r, g, b);
    // Calcular los vértices del triángulo equilátero
    array<Point>^ puntos = gcnew array<Point>(4);

    // Radio del polígono (distancia del centro a los vértices)
    float radio = 30.0f;

    // Ángulo inicial (rotación opcional)
    float anguloInicial = -Math::PI / 4; // Apunta hacia arriba

    for (int i = 0; i < 4; i++) {
        float ang = anguloInicial + (2 * Math::PI * i / 4);
        int px = (int)(x + radio * Math::Cos(ang));
        int py = (int)(y + radio * Math::Sin(ang));
        puntos[i] = Point(px, py);
    }

    if (relleno) {
        SolidBrush^ brush = gcnew SolidBrush(color);
        graphics->FillPolygon(brush,puntos);

    }
    else {
        Pen^ pen = gcnew Pen(color, 2);
        graphics->DrawRectangle(pen, x, y, ancho, alto);

    }

    // Dibujar número en el centro
    if (numero > 0) {
        String^ texto = numero.ToString();
        Font^ font = gcnew Font("Arial", 14, FontStyle::Bold);
        SolidBrush^ brushTexto = gcnew SolidBrush(Color::Black);
        SizeF tamanioTexto = graphics->MeasureString(texto, font);
        float centroX = x + ancho / 2.0f - tamanioTexto.Width / 2;
        float centroY = y + alto / 2.0f - tamanioTexto.Height / 2;
        graphics->DrawString(texto, font, brushTexto, centroX, centroY);        
    }
}
