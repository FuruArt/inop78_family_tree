//------------------------------------------------------------//----
//3MSJ Company
//Mariusz Stefa�ski, Mateusz Ryl, Mateusz Ceranka, Szymon Ratajczyk, Jan Doma�ski
//
//Opis pliku:
//Klasa do trzymania inforamcji o cz�onku rodziny - plik nag��wkowy
//
//Historia zmian:
//Wersja|Data      |Opis                     |Autor
//1.0   |15.04.2018|Utworzenie klasy                                   |MS
//2.0   |22.04.2018|Utworzenie struktury Pointer                       |MS
//4.0   |29.05.2018|Utworzenie metody toString()                       |MR
//5.0   |06.05.2018|Utworzenie getter�w i setter�w/atrybuty w protected|MC
//------------------------------------------------------------//----

#ifndef PERSON_H
#define PERSON_H

#include "Date.h"

using std::to_string;

//struktura przechowuj�ca wsp�rz�dne cz�onka rodziny w drzewie
typedef struct { int map; int vector; } Pointer;

class Person
{
protected:
	string _firstName;
	string _lastName;
	string _familyName;
	Date _birthDate;
	Date _deathDate;
	bool _gender;
	string _relationship;
	Pointer _mother;
	Pointer _father;
	Pointer _partner;
public:
    //konstruktor przyjmuj�cy imi�, nazwisko, nazwisko rodowe, dat� urodzenia, dat� �mierci, oraz p�e�(0=kobieta, 1=m�czyzna)
	Person(string, string, string, Date, Date, bool);

	//konstruktor przyjmuj�cy imi�, nazwisko, nazwisko rodowe, dat� urodzenia, dat� �mierci, oraz p�e�(0=kobieta, 1=m�czyzna), oraz nazw� relacji
	Person(string, string, string, Date, Date, bool, string);

	//konstruktor kopiuj�cy
	Person(const Person&);

	//przeci��enie operatora przypisania
	Person& operator=(const Person&);

	//metoda defiuniuj�ca w jakim formacie cz�onek rodziny ma by� wy�wietlany
	friend ostream & operator<<(ostream&, Person&);

    //metoda zwracaj�ca relacj�
	string getRelationship();

	//metoda zwracaj�ca p�e�(0=kobieta,1=m�czyzna)
	bool getGender();

	//metoda zwracaj�ca imi�
	string getFirstName();

	//metoda zwracaj�ca nazwisko
	string getLastName();

	//metoda zwracaj�cy pozycj� matki w drzewie (404=nie zdefiniowano)
	Pointer getMother();

	//metoda zwracaj�cy pozycj� ojca w drzewie (404=nie zdefiniowano)
	Pointer getFather();

	//metoda zwracaj�cy pozycj� partnera w drzewie (404=nie zdefiniowano)
	Pointer getPartner();

	//metoda usatiaj�ca pozycj� matki w drzewie
	void setMother(Pointer);

	//metoda usatiaj�ca pozycj� ojca w drzewie
	void setFather(Pointer);

	//metoda usatiaj�ca pozycj� partnera w drzewie
	void setPartner(Pointer);

	//metoda konwertuj�ca wszystkie dane nt. cz�onka rodziny do ci�gu znak�w
	string toString();
};

#endif
