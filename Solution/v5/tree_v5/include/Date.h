//------------------------------------------------------------//----
//3MSJ Company
//Mariusz Stefa�ski, Mateusz Ryl, Mateusz Ceranka, Szymon Ratajczyk, Jan Doma�ski
//
//Opis pliku:
//Klasa daty - plik nag��wkowy
//
//Historia zmian:
//Wersja|Data      |Opis                                       |Autor
//1.0   |15.04.2018|Utworzenia klasy                           |JD
//2.0   |22.04.2018|Dodanie stringa daty jako atrybut klasy    |JD
//3.0   |13.05.2018|Utworzenie getter�w/atrybuty jako protected|MC
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
	//konstruktor z parametrem w postaci ci�gu znak�w
	Date(string);

	//przeci��enie operatora por�wnania
    bool operator< (const Date&);

	//metoda zwracaj�ca prawd�, je�eli data zosta�a ustawiona
	bool isSet();

	//metoda zwracaj�ca dat� w postaci ci�gu znak�w
	string getDate();

	//metoda zwracaj�ca dzie�
    int getDay();

    //metoda zwracaj�ca miesi�c
    int getMonth();

    //metoda zwracaj�ca rok
    int getYear();
};

#endif
