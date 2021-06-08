#pragma once
#include "Shape.h"

/**
* Klasa czworok�ta reprezentuj�ca figur� obiekt w programie. Dziedziczy po Shape.
*/
class Quadrangle : public Shape
{
public:
	/**
	* Konstruktor. Tworzy czworok�t.
	* @param x1 wsp�rz�dna x pierwszego wierzcho�ka.
	* @param x2 wsp�rz�dna x drugiego wierzcho�ka.
	* @param x3 wsp�rz�dna x trzeciego wierzcho�ka.
	* @param x4 wsp�rz�dna x czwartego wierzcho�ka.
	* @param y1 wsp�rz�dna y pierwszego wierzcho�ka.
	* @param y2 wsp�rz�dna y drugiego wierzcho�ka.
	* @param y3 wsp�rz�dna y trzeciego wierzcho�ka.
	* @param y4 wsp�rz�dna y czwartego wierzcho�ka.
	* @param c kolor figury.
	* @param t typ figury czy tr�jk�t b�d� czworok�t.
	*/
	Quadrangle(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, wxColour c, Type t);
	/**
	* Rysuje figure na ekran.
	* @param panel miejsce gdzie wyrysowywana jest figura.
	*/
	void Draw(wxAutoBufferedPaintDC& panel) override;
	/**
	* Obraca figure o zadany k�t wzgl�dem jej �rodka.
	* @param radian k�t w radianach o jaki obracana jest figura.
	*/
	void Rotate(double radian) override;
	/**
	* Przesuwa figur� o dane wsp�rz�dne.
	* @param x przesuni�cie x pikesli w lewo b�d� w prawo.
	* @param y przesuni�cie y pikesli w g�r� b�d� w d�.
	*/
	void Move(int dx, int dy) override;
	/**
	* Zwraca punkty w kt�rych zawart� s� wierzcho�ki figury.
	*/
	wxPoint* GetPoints() const override { return pos; }
	/**
	* Ustawia aktualne po�o�enie figury na po�o�enie pocz�tkowe.
	*/
	void Reset() const override;
	/**
	* Destruktor.
	*/
	~Quadrangle();
};