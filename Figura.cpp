#include "Figura.h"
#include <cstdlib>
#include <ctime>
Figura::Figura(int x, int y, int ancho, int alto, int lados, bool movimientoAutonomo) {
	ctime((NULL));
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	this->alto = alto;
	this->movimientoAutonomo = movimientoAutonomo;
	this->dirX = 0;
	this->dirY = 0;
	this->numero = rand() % 10 + 1; // Asignar un número aleatorio entre 1 y 9
	this->sumaDeAngulos = (lados - 2) * 180.0f;
	this->color = rand() % 3 + 1; // 1 rojo, 2 amarillo, 3 azul
}

Figura::Figura(int x, int y, int ancho, int alto, int lados, bool movimientoAutonomo, int numero) {
	ctime((NULL));
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	this->alto = alto;
	this->movimientoAutonomo = movimientoAutonomo;
	this->dirX = 0;
	this->dirY = 0;
	this->numero = numero;
	this->sumaDeAngulos = (lados - 2) * 180.0f;
	this->color = rand() % 3 + 1; // 1 rojo, 2 amarillo, 3 azul
}
Figura::~Figura() {
	
}

int Figura::getSumaDeLados() {
	return sumaDeAngulos;
}
int Figura::getX() {
	return x;
}
int Figura::getY() {
	return y;
}
int Figura::getAncho() {
	return ancho;
}
int Figura::getAlto() {
	return alto;
}
int Figura::getColor()
{
	return color;
}
bool Figura::getMovimientoAutonomo() { return movimientoAutonomo; }
int Figura::getDirX() { return dirX; }
int Figura::getDirY() { return dirY; }
int Figura::getNumero() { return numero; }

void Figura::setX(int x) { this->x = x; }
void Figura::setY(int y) { this->y = y; }
void Figura::setDirX(int dirX) { this->dirX = dirX; }
void Figura::setDirY(int dirY) { this->dirY = dirY; }
void Figura::setNumero(int numero) { this->numero = numero; }
void Figura::setSeMueve(bool seMueve) { this->movimientoAutonomo = seMueve; }

void Figura::mover(int limiteAncho, int limiteAlto) {
	if (!movimientoAutonomo) {
		if(Direccion::IZQUIERDA == dirX && x > 0) {
			x -= 5;
		}
		else if(Direccion::DERECHA == dirX && x < limiteAncho - ancho) {
			x += 5;
		}
		else if(Direccion::ARRIBA == dirY && y > 0) {
			y -= 5;
		}
		else if(Direccion::ABAJO == dirY && y < limiteAlto - alto) {
			y += 5;
		
		}
	}
	else {
		x += dirX * 5;
		y += dirY * 5;
		// Mantener dentro de los límites
		if (x < 0) x = 0;
		if (y < 0) y = 0;
		if (x > limiteAncho - ancho) x = limiteAncho - ancho;
		if (y > limiteAlto - alto) y = limiteAlto - alto;
	}
}
Rectangle Figura::getRectangulo() { return Rectangle(x,y,ancho,alto); }
