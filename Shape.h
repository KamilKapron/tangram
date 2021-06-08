#pragma once
#include <wx/wx.h>
#include <wx/wxprec.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>

#include "vecmat.h"
#include "type.h"

#include <cmath>
/**
* Klasa wirtualna reprezentuj�ca figur� obiekt w programie.
*/
class Shape
{
public:
	/**
	* Konstruktor. Tworzy figure, tr�jk�t lub czworok�t.
	* @param c kolor figury.
	* @param t typ figury czy tr�jk�t b�d� czworok�t.
	*/
	Shape(wxColour c, Type t) : color(c), type(t), start(nullptr), pos(nullptr) {}
	/**
	* Rysuje figure na ekran.
	* @param panel miejsce gdzie wyrysowywana jest figura.
	*/
	virtual void Draw(wxAutoBufferedPaintDC &panel) = 0;
	/**
	* Obraca figure o zadany k�t wzgl�dem jej �rodka.
	* @param radian k�t w radianach o jaki obracana jest figura.
	*/
	virtual void Rotate(double radian) = 0;
	/**
	* Przesuwa figur� o dane wsp�rz�dne.
	* @param x przesuni�cie x pikesli w lewo b�d� w prawo.
	* @param y przesuni�cie y pikesli w g�r� b�d� w d�.
	*/
	virtual void Move(int x, int y) = 0;
	/**
	* Zwraca punkty w kt�rych zawart� s� wierzcho�ki figury.
	*/
	virtual wxPoint* GetPoints() const = 0;
	/**
	* Ustawia aktualne po�o�enie figury na po�o�enie pocz�tkowe.
	*/
	virtual void Reset() const = 0;
	/**
	* Destruktor.
	*/
	virtual ~Shape() {}
protected:
	wxPoint* start; /**< wska�nik na tablice zawieraj�c� wsp�rz�dne pocz�tkowe wierzcho�k�w figury. */
	wxPoint* pos; /**< wska�nik na tablice zawieraj�c� aktualne wsp�rz�dne wierzcho�k�w figury. */
public:
	const Type type; /**< Zmienna przechowywuj�ca informacje jakiego typu jest figura (czy czworok�t, czy tr�jk�t). */
	bool in_container = true; /**< Zmienna okre�laj�ca czy figura znajduje si� w kontenerze na figury. */
	wxColour color; /**< Zmienna okre�laj�ca kolor figury. */
};
