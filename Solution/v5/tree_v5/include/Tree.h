//------------------------------------------------------------//----
//3MSJ Company
//Mariusz Stefañski, Mateusz Ryl, Mateusz Ceranka, Szymon Ratajczyk, Jan Domañski
//
//Opis pliku:
//Klasa do przechowywania informacji o strukturze drzewa - plik nag³ówkowy
//
//Historia zmian:
//Wersja|Data      |Opis                                               |Autor
//1.0   |15.04.2018|Utworzenie klasy                                   |SR
//2.0   |22.04.2018|Utworzenie metod dodaj¹cych cz³onków rodziny       |SR
//4.0   |29.05.2018|Utworzenie metod exportTree() oraz importTree()    |MR
//5.0   |06.05.2018|Utworzenie metod editMember()                      |MC
//6.0   |13.05.2018|Utworzenie metod ustwai¹j¹cych wska¿nik na krewnego|MS
//7.0   |20.05.2018|Utworzenie metody memberTree()                     |MS
//8.0   |08.06.2018|Utworzenie metody membersCount()                   |MS
//------------------------------------------------------------//----

#ifndef TREE_H
#define TREE_H

#include <map>
#include <vector>
#include <fstream>
#include "Person.h"

using std::vector;
using std::map;
using std::fstream;

class Tree
{
protected:
	map<int, vector<Person>> _tree;
public:
    //metoda zwracaj¹ca drzewo
    map<int, vector<Person>> getTree();

    //metoda zwracaj¹ca krewnego
    Person getPerson(Pointer);

    //metoda dodaj¹ca u¿ytkownika do drzewa
	Pointer addUser(const Person&);

	//metoda dodaj¹ca dziadków do drzewa
	Pointer addGrandParent(const Person&);

	//metoda dodaj¹ca rodziców do drzewa
	Pointer addParent(const Person&);

	//metoda dodaj¹ca rodzeñstwo do drzewa
	Pointer addSibling(const Person&);

	//metoda dodaj¹ca partnera do drzewa
	Pointer addPartner(const Person&);

	//metoda dodaj¹ca dziecko do drzewa
	Pointer addChild(const Person&);

	//metoda dodaj¹ca wnuka do drzewa
	Pointer addGrandChild(const Person&);

	//metoda dodaj¹ca osobê do drzewa, na podstawie stopnia pokrewieñstwa
	Pointer addPerson(const Person&, int);

	//metoda wyœwietlaj¹ca drzewo
	void printTree(map<int, vector<Person>>);

	//metoda wyœwietlaj¹ca wybranego cz³onka rodziny, wraz z jego najbli¿szymi krewnymi
	void memberTree(Pointer);

	//metoda przeszukuj¹ca drzewo, zwraca pozycjê krewnego w drzewie, przyjmuje imiê oraz nazwisko
	Pointer findMember(string, string);

	//metoda ustawiaj¹ca wskaŸnik na krewnego
	void setRelative(Pointer, Pointer, int);

    //metoda usuwaj¹ca krewnego z drzewa
	void deleteReative(Pointer);

	//metoda edytuj¹ca krewnego
	void editRelative(Pointer, const Person&);

	//metoda importuj¹ca drzewo z pliku
	bool importTree(string);

	//metoda eksportuj¹ca drzewo do pliku
	void exportTree(string);

	//metoda zwracajaca ilosc osob w drzewie
	int membersCount();
};

#endif
