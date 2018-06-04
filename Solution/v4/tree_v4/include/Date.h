//------------------------------------------------------------//----
//3MSJ Company
//Mariusz Stefañski, Mateusz Ryl, Mateusz Ceranka, Szymon Ratajczyk, Jan Domañski
//
//Opis pliku:
//Klasa daty - plik nag³ówkowy
//
//Historia zmian:
//Wersja|Data      |Opis                                       |Autor
//1.0   |15.04.2018|Utworzenia klasy                           |JD
//2.0   |22.04.2018|Dodanie stringa daty jako atrybut klasy    |JD
//3.0   |13.05.2018|Utworzenie getterów/atrybuty jako protected|MC
//------------------------------------------------------------//----

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class Date
{
protected:
	int _day;
	int _month;
	int _year;
	string _date;
public:
	//konstruktor z parametrem w postaci ci¹gu znaków
	Date(string);

	//przeci¹¿enie operatora porównania
    bool operator< (const Date&);

	//metoda zwracaj¹ca prawdê, je¿eli data zosta³a ustawiona
	bool isSet();

	//metoda zwracaj¹ca datê w postaci ci¹gu znaków
	string getDate();

	//metoda zwracaj¹ca dzieñ
    int getDay();

    //metoda zwracaj¹ca miesi¹c
    int getMonth();

    //metoda zwracaj¹ca rok
    int getYear();
};

#endif
