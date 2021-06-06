#pragma once

#include "Shape.h"

/**
* Statyczna klasa Zawieraj�ca funkcje sprawdzaj�ce czy punkt le�y wewn�trz wielok�ta i czy dwa wielok�ty na siebie nachodz�.
*/
class ShapeCollision
{
public:
	/**
	* Funkcja sprawdzaj�ca czy punkt le�y wewn�trz wielok�ta.
	* @param shape obiekt klasy Shape reprezentuj�cy wielok�t
	* @param mouse obiekt klasy wxPoint reprezentuj�cy punkt na ekranie
	* @param on_display flaga informuj�ca czy punkt mouse znajduje si� w zasobniku(false) czy w obszarze roboczym(true)
	* @return true je�eli punkt mouse le�y wewn�trz wielok�ta shape, w przeciwnym razie false
	*/
	static bool isInside(const Shape& shape, wxPoint& mouse, bool on_display);


	static bool ShapeOverlap(Shape& polygon1, Shape& polygon2);
private:
	/**
	* Funkcja pomocnicza wywo�ywana przez isInside. Zwraca true je�eli odcinki [p1, q1] i [p2, q2] si� przecinaj�.
	* @param p1 obiekt wxPoint reprezentuj�cy punkt pocz�tkowy pierwszego odcinka
	* @param q1 obiekt wxPoint reprezentuj�cy punkt ko�cowy pierwszego odcinka
	* @param p2 obiekt wxPoint reprezentuj�cy punkt pocz�tkowy drugiego odcinka
	* @param q2 obiekt wxPoint reprezentuj�cy punkt ko�cowy drugiego odcinka
	* @return true je�eli odcinki si� przecinaj�, w przeciwnym razie false
	* @see isInside()
	*/
	static bool Intersect(const wxPoint& p1, const wxPoint& q1, const wxPoint& p2, const wxPoint& q2);

	/**
	* Funkcja pomocnicza wywo�ywana przez isInside. Zwraca orientacje ci�gu 3 punkt�w p, q, r
	* @param p pierwszy punkt ci�gu
	* @param q drugi punkt ci�gu
	* @param r trzeci punkt ci�gu
	* @see isInside()
	* @return 0 - punkty p, q, r s� wsp�liniowe, 1 - punkty p, q, r s� ustawione zgodnie z ruchem wskaz�wek zegara, 2 - przeciwnie do ruchu wskaz�wek zegara
	*/
	static int Orientation(const wxPoint& p, const wxPoint& q, const wxPoint& r);

	/**
	* Funkcja pomocnicza wywo�ywana przez isInside. Sprawdza czy punkt q le�y na odcinku [p, r]
	* @param p punkt pocz�tkowy odcinka
	* @param q sprawdzany punkt
	* @param r punkt ko�cowy odcinka
	* @see isInside()
	* @return true je�eli punkt q le�y na odcinku [p, r], w przeciwnym razie false
	*/
	static bool Segment(const wxPoint& p, const wxPoint& q, const wxPoint& r);
};

