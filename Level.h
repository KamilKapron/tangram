#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <fstream>
#include <cmath>

#include "Shape.h"

#include <wx/wx.h>
#include <wx/wxprec.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>

/**
* Struktura reprezentuj�ca wielok�t.
*/
struct Poly
{
	std::vector<wxPoint> points; /**<Wektor zawieraj�cy punkty b�d�ce wierzcho�kami wielok�ta. */
	Type type; /**<Zmienna przechowuj�ca informacje jakiego typu jest wielok�t. */

	/**
	* Konstruktor tworz�cy wielok�t.
	* @param Points wektor punkt�w b�d�cych wierzcho�kami wielok�ta
	* @param T typ wielok�ta
	*/
	Poly(std::vector<wxPoint> Points, Type T) : points(Points), type(T) {}
};

/**
* Klasa reprezentuj�ca wybrany poziom gry.
*/
class Level
{
private:
	std::vector<wxPoint> polygon; /**<Wektor zawieraj�y punkty bie��ce wierzcho�kami kszta�tu do u�o�enia */
	std::vector<Poly> check; /**<Wektor punkt�w u�ywany przy sprawdzaniu kszta�tu u�o�onego */
	std::vector<Poly> check_copy; /**< Kopia wektora check */
public:
	/**
	* Metoda, kt�ra odpowiada za tworzenie poziomu.
	* @param filename1 �cie�ka do pliku zawieraj�cego wsp�rz�dne wierzcho�k�w wielok�ta do u�o�enia
	* @param filename2 �cie�ka do pliku zawieraj�cego wsp�rz�dne wierzcho�k�w wielok�ta u�ywane do sprawdzenie poprawno�ci u�o�enia kszta�tu.
	*/
	void SetLevel(std::string filename1, std::string filename2);

	/**
	* Metoda, wyrysowuj�ca kszta�t do u�o�enia na ekran.
	* @param panel obiekt u�ywany do rysowania
	*/
	void Draw(wxAutoBufferedPaintDC& panel);

	/**
	* Metoda sprawdzaj�ca czy kszta�t jest u�o�ony poprawnie.
	* @param shapes wektor obiekt�w Shape uk�adanych przez u�ytkownika
	* @return true je�eli u�o�enie jest poprawne, w przeciwnym razie false
	*/
	bool CheckLevel(const std::vector<std::unique_ptr<Shape>>& shapes);
};