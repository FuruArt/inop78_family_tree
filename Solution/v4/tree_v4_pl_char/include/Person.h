//------------------------------------------------------------//----
//3MSJ Company
//Mariusz Stefañski, Mateusz Ryl, Mateusz Ceranka, Szymon Ratajczyk, Jan Domañski
//
//Opis pliku:
//Klasa do trzymania inforamcji o cz³onku rodziny - plik nag³ówkowy
//
//Historia zmian:
//Wersja|Data      |Opis                     |Autor
//1.0   |15.04.2018|Utworzenie klasy                                   |MS
//2.0   |22.04.2018|Utworzenie struktury Pointer                       |MS
//4.0   |29.05.2018|Utworzenie metody toString()                       |MR
//5.0   |06.05.2018|Utworzenie getterów i setterów/atrybuty w protected|MC
//------------------------------------------------------------//----

#ifndef PERSON_H
#define PERSON_H

#include "Date.h"

using std::to_string;

//struktura przechowuj¹ca wspó³rzêdne cz³onka rodziny w drzewie
typedef struct { int _map; int _vector; } Pointer;

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
    //konstruktor przyjmuj¹cy imiê, nazwisko, nazwisko rodowe, datê urodzenia, datê œmierci, oraz p³eæ(0=kobieta, 1=mê¿czyzna)
	Person(string, string, string, Date, Date, bool);

	//konstruktor przyjmuj¹cy imiê, nazwisko, nazwisko rodowe, datê urodzenia, datê œmierci, oraz p³eæ(0=kobieta, 1=mê¿czyzna), oraz nazwê relacji
	Person(string, string, string, Date, Date, bool, string);

	//konstruktor kopiuj¹cy
	Person(const Person&);

	//przeci¹¿enie operatora przypisania
	Person& operator=(const Person&);

	//metoda defiuniuj¹ca w jakim formacie cz³onek rodziny ma byæ wyœwietlany
	friend ostream & operator<<(ostream&, Person&);

    //metoda zwracaj¹ca relacjê
	string getRelationship();

	//metoda zwracaj¹ca p³eæ(0=kobieta,1=mê¿czyzna)
	bool getGender();

	//metoda zwracaj¹ca imiê
	string getFirstName();

	//metoda zwracaj¹ca nazwisko
	string getLastName();

	//metoda zwracaj¹cy pozycjê matki w drzewie (404=nie zdefiniowano)
	Pointer getMother();

	//metoda zwracaj¹cy pozycjê ojca w drzewie (404=nie zdefiniowano)
	Pointer getFather();

	//metoda zwracaj¹cy pozycjê partnera w drzewie (404=nie zdefiniowano)
	Pointer getPartner();

	//metoda usatiaj¹ca pozycjê matki w drzewie
	void setMother(Pointer);

	//metoda usatiaj¹ca pozycjê ojca w drzewie
	void setFather(Pointer);

	//metoda usatiaj¹ca pozycjê partnera w drzewie
	void setPartner(Pointer);

	//metoda konwertuj¹ca wszystkie dane nt. cz³onka rodziny do ci¹gu znaków
	string toString();
};

#endif
