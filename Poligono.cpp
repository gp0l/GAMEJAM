#include "Poligono.h"
#include <cstdlib>
#include <ctime>
Poligono::Poligono(int x, int y, int ancho, int alto, int lados, bool movimientoAutonomo) {
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

Poligono::Poligono(int x, int y, int ancho, int alto, int lados, bool movimientoAutonomo, int numero) {
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
Poligono::~Poligono() {
	
}

int Poligono::getSumaDeLados() {
	return sumaDeAngulos;
}
int Poligono::getX() {
	return x;
}
int Poligono::getY() {
	return y;
}
int Poligono::getAncho() {
	return ancho;
}
int Poligono::getAlto() {
	return alto;
}
int Poligono::getColor()
{
	return color;
}
bool Poligono::getMovimientoAutonomo() { return movimientoAutonomo; }
int Poligono::getDirX() { return dirX; }
int Poligono::getDirY() { return dirY; }
int Poligono::getNumero() { return numero; }

void Poligono::setX(int x) { this->x = x; }
void Poligono::setY(int y) { this->y = y; }
void Poligono::setDirX(int dirX) { this->dirX = dirX; }
void Poligono::setDirY(int dirY) { this->dirY = dirY; }
void Poligono::setNumero(int numero) { this->numero = numero; }
void Poligono::setSeMueve(bool seMueve) { this->movimientoAutonomo = seMueve; }

void Poligono::mover(int limiteAncho, int limiteAlto) {
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
Rectangle Poligono::getRectangulo() { return Rectangle(x,y,ancho,alto); }
