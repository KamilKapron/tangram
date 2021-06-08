#pragma once

#include <stdio.h>
#include <iostream>

/**
* Klasa Vector reprezentuj�ca wektor o trzech sk�adowych.
*/
class Vector
{
public:
    double dane[3];/**< Tablica przechowuj�ca informacje o sk�adowych wektora. */

    /**
    * Konsturktor. Tworzy wektor [0.0, 0.0, 1.0]
    */
    Vector();
};

/**
* Klasa Matrix reprezentuj�ca macierz o wymiarze 3x3.
*/
class Matrix
{
public:
    double dane[3][3]; /**< Tablica przechowuj�ca informacje o elementach macierzy. */

    /**
    * Konstruktor. Tworzy macierz { [0.0, 0.0, 0.0], [0.0, 0.0, 0.0], [0.0, 0.0, 1.0]}
    */
    Matrix();

    /**
    * Przeci��ony operator * pozwalaj�cy na wykonanie operacji mno�enia Matrix*Vector
    * @param macierz macierz, przez kt�r� mno�ymy wektor
    * @param wektor wektor, kt�ry mno�ymy przez macierz
    * @return wektor b�d�cy wynikiem naszego mno�enia
    */
    friend Vector operator*(const Matrix&, const Vector&);

    /**
    * Przeci��ony operator * pozwalaj�cy na wykonanie operacji mno�enia Matrix*Matrix
    * @param macierz macierz, przez kt�ry mno�ymy macierz
    * @return wynik mno�enia
    */
    Matrix operator*(const Matrix& macierz);
};

