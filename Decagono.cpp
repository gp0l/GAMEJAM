#include "Decagono.h"
#include <cmath>

Decagono::Decagono(int x, int y, int ancho, int alto, bool movimeintoAutomatico)
    : Poligono(x, y, ancho, alto, 10, movimeintoAutomatico) {
}

void Decagono::dibujar(Graphics^ graphics) {
    Color colorDelCuerpo;
    if (color == 1) {
        colorDelCuerpo = Color::Red;
    }
    else if (color == 2) {
        colorDelCuerpo = Color::Yellow;
    }
    else {
        colorDelCuerpo = Color::Blue;
    }

    array<Point>^ puntos = gcnew array<Point>(10);
    float cx = x + ancho / 2.0f;
    float cy = y + alto / 2.0f;
    float radio = Math::Min(ancho, alto) * 0.45f;
    float angIni = Math::PI / 10;

    for (int i = 0; i < 10; i++) {
        float ang = angIni + (2 * Math::PI * i / 10);
        int px = (int)(cx + radio * cos(ang));
        int py = (int)(cy + radio * sin(ang));
        puntos[i] = Point(px, py);
    }
    SolidBrush^ brush = gcnew SolidBrush(colorDelCuerpo);
    graphics->FillPolygon(brush, puntos);

    // Dibujar número en el centro
    if (numero > 0) {
        String^ texto = numero.ToString();
        Font^ font = gcnew Font("Arial", 14, FontStyle::Bold);
        SolidBrush^ brushTexto = gcnew SolidBrush(Color::Black);
        //MeasureString: mide el texto y devuelve sus dimensiones antes de dibujarl
        SizeF tamanioTexto = graphics->MeasureString(texto, font);
        //2.0f asegura division decimal precisa. La f evita conversiones innecesarias a double
        float centroX = x + ancho / 2.0f - tamanioTexto.Width / 2;
        float centroY = y + alto * 2 / 3.0f - tamanioTexto.Height / 2;
        graphics->DrawString(texto, font, brushTexto, centroX, centroY);
    }
}