#include "Triangulo.h"


Triangulo::Triangulo(int x, int y, int ancho, int alto, bool movimeintoAutomatico)
    : Figura(x, y, ancho, alto, 3, movimeintoAutomatico) {
}

void Triangulo::dibujar(Graphics^ graphics) {
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

    array<Point>^ puntos = gcnew array<Point>(3);
    puntos[0] = Point(x + ancho / 2, y);           // Punto superior (centro)
    puntos[1] = Point(x, y + alto);                // Punto inferior izquierdo
    puntos[2] = Point(x + ancho, y + alto);        // Punto inferior derecha

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