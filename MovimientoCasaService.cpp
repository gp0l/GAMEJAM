#include "MovimientoCasaService.h"


MovimientoCasaService::MovimientoCasaService() {
	
}


MovimientoCasaService::~MovimientoCasaService() {
	// Liberar todas las figuras
	for (int i = 0; i < figuras.size(); i++) {
		delete figuras[i];
	}
	figuras.clear();
}


void MovimientoCasaService::agregarCasa(int x, int y, int ancho, int alto, int r, int g, int b) {
	Casa* nuevaCasa = new Casa(x, y, ancho, alto, r, g, b);
	figuras.push_back(nuevaCasa);
}


void MovimientoCasaService::dibujarFiguras(Graphics^ g) {
	for (int i = 0; i < figuras.size(); i++) {
		figuras[i]->dibujar(g);
	}
}

void MovimientoCasaService::moverFigurasAutomatico(int anchoForm, int altoForm) {
	for (int i = 0; i < figuras.size(); i++) {
		figuras[i]->mover(anchoForm, altoForm);

		// Verificar colisiones si es una Casa
		Casa* casa = dynamic_cast<Casa*>(figuras[i]);
		if (casa != nullptr) {
			casa->verificarColisiones(anchoForm, altoForm);
		}
	}
}


int MovimientoCasaService::getCantidadFiguras() {
	return figuras.size();
}
