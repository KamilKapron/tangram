#pragma once

#include <wx/dcclient.h>
#include <wx/dcbuffer.h>

#include <algorithm>
#include <vector>
#include <iostream>

#include "GUI.h"
#include "Triangle.h"
#include "Quadrangle.h"
#include "Level.h"
#include "ShapeCollision.h"

/**
* Klasa reprezentuj�ca g��wne okno programu.
*/
class MainFrame : public Frame
{
public:
	/**
	* Konstruktor. Tworzy okno, inicjalizuje atrybuty shapes i level. Dodaje wxMenuBar oraz odpowiednie eventy.
	* @param parent wska�nik na obiekt wxWindow b�d�cy nadrz�dnym oknem
	*/
	MainFrame(wxWindow* parent);

	/**
	* Event uruchamiany po klikni�ciu lewego przycisku myszy. Sprawdza czy klikni�to na obiekt z wektora shapes,
	* je�eli tak, obiekt ten mo�e by� przenoszony po ekranie i upuszczony w innym miejscu.
	* @param event obiekt wxMouseEvent
	*/
	void OnClick( wxMouseEvent& event );

	/**
	* Event wxEVT_PAINT. Rysuje na ekranie.
	* @param event obiekt wxPaintEvent
	*/
	void Render( wxPaintEvent& event );

	/**
	* Event uruchamiany po puszczeniu lewego przycisku myszy. Je�eli obiekt z wektora shapes jest aktualnie przenoszony,
	* ten obiekt jest upuszczany na ekran(je�eli jest to mo�liwe), sprawdzane jest tak�e czy u�o�ony kszta�t jest poprawny.
	* @param event obiekt wxMouseEvent
	*/
	void OnClickUp(wxMouseEvent& event);

	/**
	* Event uruchamiany w momencie poruszania myszk�. Je�eli obiekt z wektora shapes jest aktualnie przenoszony, 
	* aktualizowane s� jego wsp�rz�dne.
	* @param event obiekt wxMouseEvent
	*/
	void Mouse_Move(wxMouseEvent& event);

	/**
	* Event uruchamiany po puszczeniu prawego przycisku myszy. Je�eli obiekt z wektora shapes jest aktualnie przenoszony,
	* zostaje on obr�cony o 90 stopni. 
	* @param event obiekt wxMouseEvent
	*/
	void OnRightUp(wxMouseEvent& event);

	/**
	* Event uruchamiany po klikni�ciu prawego przycisku myszy. Je�eli obiekt z wektora shapes jest aktualnie przenoszony,
	* flaga rotating zostaje ustawiona na true co zapobiega przesuwaniu obiektu.
	* @param event obiekt wxMouseEvent
	*/
	void OnRightDown(wxMouseEvent& event);

	/**
	* Event uruchamiany po puszczeniu �rodkowego przyciski myszy. Je�eli obiekt z wektora shapes jest aktualnie przenoszony,
	* obiekt ten wraca do zasobnika. Je�eli �aden obiekt nie by� aktualnie przenoszony, do zasobnika wraca obiekt nad kt�rym aktualnie
	* jest ustawiony kursor (je�eli taki obiekt istnieje).
	* @param event obiekt wxMouseEvent
	*/
	void OnMiddleUp(wxMouseEvent& event);

	/**
	* Destruktor. Zwalnia pami�� i od��cza eventy.
	*/
	~MainFrame();

protected:
	Level* level; /**< wska�nik na aktualny Level */
	std::vector<std::unique_ptr<Shape>> shapes; /**< wektor obiekt�w Shape b�d�cych uk�adanymi kszta�tami */
	Shape* moving = nullptr; /**< wska�nik na aktualnie przenoszony obiekt klasy Shape */
	wxPoint mouse_pos; /**< aktualna pozycja myszki */
	wxPoint mouse_prev; /**< poprzednia pozycja myszki */
	bool dragging = false; /**< flaga informuj�ca czy obiekt Shape jest aktualnie przenoszony */
	bool rotating = false; /**< flaga informuj�ca czy obiekt Shape jest aktualnie obracany */
};
