#include "Circulo.h"


Circulo::Circulo(int x, int y, int Diametro, bool movimeintoAutomatico)
    : Figura(x, y, Diametro, Diametro, 0, movimeintoAutomatico) {
}

void Circulo::dibujar(Graphics^ graphics) {
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

   // Dibujar relleno
   SolidBrush^ brush = gcnew SolidBrush(colorDelCuerpo);
   graphics->FillEllipse(brush, x, y, ancho, alto);
   delete brush;

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

