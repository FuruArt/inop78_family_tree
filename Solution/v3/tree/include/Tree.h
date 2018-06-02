//------------------------------------------------------------//----
//3MSJ Company
//Mariusz Stefa�ski, Mateusz Ryl, Mateusz Ceranka, Szymon Ratajczyk, Jan Doma�ski
//
//Opis pliku:
//Klasa do przechowywania informacji o strukturze drzewa - plik nag��wkowy
//
//Historia zmian:
//Wersja|Data      |Opis                                               |Autor
//1.0   |15.04.2018|Utworzenie klasy                                   |SR
//2.0   |22.04.2018|Utworzenie metod dodaj�cych cz�onk�w rodziny       |SR
//4.0   |29.05.2018|Utworzenie metod exportTree() oraz importTree()    |MR
//5.0   |06.05.2018|Utworzenie metod editMember()                      |MC
//6.0   |13.05.2018|Utworzenie metod ustwai�j�cych wska�nik na krewnego|MS
//7.0   |20.05.2018|Utworzenie metody memberTree()                     |MS
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
    //metoda zwracaj�ca drzewo
    map<int, vector<Person>> getTree();

    //metoda dodaj�ca u�ytkownika do drzewa
	Pointer addUser(const Person&);

	//metoda dodaj�ca dziadk�w do drzewa
	Pointer addGrandParent(const Person&);

	//metoda dodaj�ca rodzic�w do drzewa
	Pointer addParent(const Person&);

	//metoda dodaj�ca rodze�stwo do drzewa
	Pointer addSibling(const Person&);

	//metoda dodaj�ca partnera do drzewa
	Pointer addPartner(const Person&);

	//metoda dodaj�ca dziecko do drzewa
	Pointer addChild(const Person&);

	//metoda dodaj�ca wnuka do drzewa
	Pointer addGrandChild(const Person&);

	//metoda dodaj�ca osob� do drzewa, na podstawie stopnia pokrewie�stwa
	Pointer addPerson(const Person&, int);

	//metoda wy�wietlaj�ca drzewo
	void printTree(map<int, vector<Person>>);

	//metoda wy�wietlaj�ca wybranego cz�onka rodziny, wraz z jego najbli�szymi krewnymi
	void memberTree(Pointer);

	//metoda przeszukuj�ca drzewo, zwraca pozycj� krewnego w drzewie, przyjmuje imi� oraz nazwisko
	Pointer findMember(string, string);

	//metoda ustawiaj�ca wska�nik na krewnego
	void setRelative(Pointer, Pointer, int);

    //metoda usuwaj�ca krewnego z drzewa
	void deleteReative(Pointer);

	//metoda edytuj�ca krewnego
	void editRelative(Pointer, const Person&);

	//metoda importuj�ca drzewo z pliku
	bool importTree(string);

	//metoda eksportuj�ca drzewo do pliku
	void exportTree(string);
};

#endif
