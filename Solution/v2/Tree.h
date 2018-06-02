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
public:

	map<int, vector<Person>> _tree;

	Pointer addUser(const Person&);
	Pointer addGrandParent(const Person&);
	Pointer addParent(const Person&);
	Pointer addSibling(const Person&);
	Pointer addPartner(const Person&);
	Pointer addChild(const Person&);
	Pointer addGrandChild(const Person&);
	Pointer addPerson(const Person&, int);
	void printTree(map<int, vector<Person>>);
	void memberTree(Pointer);
	Pointer Find(string, string);
	void setRel(Pointer, Pointer, int);
	void Delete(Pointer);
	void Edit(Pointer, const Person&);
	bool Import(string);
	void Export(string);
};

#endif // !TREE_H