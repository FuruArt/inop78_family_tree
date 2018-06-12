#include "Tree.h"

 map<int, vector<Person>> Tree::getTree()
 {
     return this->_tree;
 }

 Person Tree::getPerson(Pointer pointer)
 {
     return this->_tree[pointer._map].at(pointer._vector);
 }

Pointer Tree::addUser(const Person& _person)
{
	_tree[0].push_back(_person);
	Pointer p;
	p._map = 0;
	p._vector = _tree[0].size() - 1;
	return p;
}

Pointer Tree::addGrandParent(const Person&person)
{
	_tree[-2].push_back(person);
	Pointer p;
	p._map = -2;
	p._vector = _tree[-2].size() - 1;
	return p;
}

Pointer Tree::addParent(const Person&person)
{
	_tree[-1].push_back(person);
	Pointer p;
	p._map = -1;
	p._vector = _tree[-1].size() - 1;
	return p;
}

Pointer Tree::addSibling(const Person& person)
{
	_tree[3].push_back(person);
	Pointer p;
	p._map = 3;
	p._vector = _tree[3].size() - 1;
	return p;
}

Pointer Tree::addPartner(const Person& person)
{
	_tree[1].push_back(person);
	Pointer p;
	p._map = 1;
	p._vector = _tree[1].size() - 1;
	return p;
}

Pointer Tree::addChild(const Person& person)
{
	_tree[2].push_back(person);
	Pointer p;
	p._map = 2;
	p._vector = _tree[2].size() - 1;
	return p;
}

Pointer Tree::addGrandChild(const Person& person)
{
	_tree[4].push_back(person);
	Pointer p;
	p._map = 4;
	p._vector = _tree[4].size() - 1;
	return p;
}

Pointer Tree::addPerson(const Person& person, int rel)
{
	_tree[rel].push_back(person);
	Pointer p;
	p._map = rel;
	p._vector = _tree[rel].size() - 1;
	return p;
}

void Tree::printTree(map<int, vector<Person>> tree)
{

	for (auto it = tree.begin(); it != tree.end(); it++) {
		for (Person person : tree[it->first]) {
			if (it->first == 0)
				cout << "-> " << person << endl;
			else if (it->first == 3) {
				if (person.getGender() == 0 && !person.getRelationship().empty())
					cout << "siostra " << person << endl;
				else if(person.getGender() == 1 && person.getRelationship() == " ")
					cout << "brat " << person << endl;
				else if (person.getRelationship() != " ")
					cout << person.getRelationship() << " " << person << endl;
			}
			else if (it->first == 1) {
				if (person.getGender() == 0)
					cout << "zona " << person << endl;
				else
					cout << "maz " << person << endl;
			}
			else if (it->first == 2) {
				if (person.getGender() == 0 && !person.getRelationship().empty())
					cout << "corka " << person << endl;
				else if(person.getGender() == 1 && person.getRelationship() == " ")
					cout << "syn " << person << endl;
				else if (person.getRelationship() != " ")
					cout << person.getRelationship() << " " << person << endl;
			}
			else if (it->first == -1) {
				if (person.getGender() == 0 && !person.getRelationship().empty())
					cout << "matka " << person << endl;
				else if(person.getGender() == 1 && person.getRelationship() == " ")
					cout << "ojciec " << person << endl;
				else if (person.getRelationship() != " ")
					cout << person.getRelationship() << " " << person << endl;
			}
			else if (it->first == -2) {
				if (person.getGender() == 0 && !person.getRelationship().empty())
					cout << "babcia " << person << endl;
				else if (person.getGender() == 1 && person.getRelationship() == " ")
					cout << "dziadek " << person << endl;
				else if (person.getRelationship() != " ")
					cout << person.getRelationship() << " " << person << endl;
			}
			else if (it->first == 4) {
				if (person.getGender() == 0)
					cout << "wnuczka " << person << endl;
				else
					cout << "wnuk " << person << endl;
			}
			else if (it->first > 4) {
				string s;
				for (int i = 0; i < (it->first - 4); i++) {
					s += "pra";
				}
				if (person.getGender() == 0)
					cout << s << "wnuczka " << person << endl;
				else
					cout << s << "wnuk " << person << endl;
			}
			else if (it->first < -2) {
				string s;
				int temp = -(it->first);
				for (int i = 0; i < temp - 2; i++) {
					s += "pra";
				}
				if (person.getGender() == 0)
					cout << s << "babcia " << person << endl;
				else
					cout << s << "dziadek " << person << endl;
			}
		}
	}
}

void Tree::memberTree(Pointer member)
{
	map<int, vector<Person>> memberTree;

	Pointer mother, father, partner;

	mother = _tree[member._map].at(member._vector).getMother();
	father = _tree[member._map].at(member._vector).getFather();
	partner = _tree[member._map].at(member._vector).getPartner();

	memberTree[0].push_back(_tree[member._map].at(member._vector));


    if (mother._map != 404) {
        memberTree[-1].push_back(_tree[mother._map].at(mother._vector));
    }

    if (father._map != 404) {
        memberTree[-1].push_back(_tree[father._map].at(father._vector));
    }

	if (partner._map != 404) {
		memberTree[1].push_back(_tree[partner._map].at(partner._vector));
	}

	Pointer child;
	for (auto it = _tree.begin(); it != _tree.end(); it++) {
		int vec = 0;
		for (Person person : _tree[it->first]) {
			if ((person.getFather()._map == member._map && person.getFather()._vector == member._vector)
				|| (person.getMother()._map == member._map && person.getMother()._vector == member._vector)) {
				child._map = it->first;
				child._vector = vec;
				memberTree[2].push_back(_tree[child._map].at(child._vector));
			}
			++vec;
		}
	}

	Pointer sibling;
	for (auto it = _tree.begin(); it != _tree.end(); it++) {
		int vec = 0;
		for (Person person : _tree[it->first]) {
			if ((person.getFather()._map == father._map && person.getFather()._vector == father._vector && person.getFather()._map != 404)
				|| (person.getMother()._map == mother._map && person.getMother()._vector == mother._vector && person.getMother()._map != 404)) {
				sibling._map = it->first;
				sibling._vector = vec;
				if (sibling._map != member._map || sibling._vector != member._vector) {
					memberTree[3].push_back(_tree[sibling._map].at(sibling._vector));
				}
			}
			++vec;
		}
	}

    printTree(memberTree);
}

Pointer Tree::findMember(string firstname, string lastname)
{
	Pointer wsk;
	for (auto it = _tree.begin(); it != _tree.end(); it++) {
		int vec = 0;
		for (Person person : _tree[it->first]) {
			if (person.getFirstName() == firstname && person.getLastName() == lastname) {
				wsk._map = it->first;
				wsk._vector = vec;
				return wsk;
			}
			++vec;
		}
	}
	wsk._map = 404;
	wsk._vector = 404;
	return wsk;
}

void Tree::setRelative(Pointer pointer1, Pointer pointer2, int rel)
{
	if (rel == 1) {
		_tree[pointer1._map].at(pointer1._vector).setPartner(pointer2);
	}
	else if (rel == 2) {
		_tree[pointer1._map].at(pointer1._vector).setMother(pointer2);
	}
	else if (rel == 3) {
		_tree[pointer1._map].at(pointer1._vector).setFather(pointer2);
	}
}

void Tree::deleteReative(Pointer pointer)
{
	auto it = _tree[pointer._map].begin()+pointer._vector;
	_tree[pointer._map].erase(it);
}

void Tree::editRelative(Pointer pointer, const Person& person)
{

	_tree[pointer._map].at(pointer._vector) = person;

}

bool Tree::importTree(string filename)
{
	fstream file;
	file.open(filename, std::ios::in);
	if (file.good()) {
		int lastAdded = 0;
		while (file) {
			string firstName, lastName;
			string familyName;
			string relationship = " ";
			string birthDate, deathDate;
			string tempDate;
			Pointer mother, father, partner;

			file >> relationship;
			if (relationship == " ")
				break;

			file >> firstName >> lastName >> familyName >> birthDate >> deathDate;
			file >> mother._map >> mother._vector;
			file >> father._map >> father._vector;
			file >> partner._map >> partner._vector;

			if (relationship == "->") {
				bool gender;
				file >> gender;
				Pointer p1 = addUser(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), gender));
				setRelative(p1, partner, 1);
				setRelative(p1, mother, 2);
				setRelative(p1, father, 3);
				lastAdded = 0;
			}
			else if (relationship == "siostra") {
				Pointer p1 = addSibling(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 0));
				setRelative(p1, partner, 1);
				setRelative(p1, mother, 2);
				setRelative(p1, father, 3);
				lastAdded = 1;
			}
			else if (relationship == "brat") {
				Pointer p1 = addSibling(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 1));
				setRelative(p1, partner, 1);
				setRelative(p1, mother, 2);
				setRelative(p1, father, 3);
				lastAdded = 1;
			}
			else if (relationship == "zona") {
				Pointer p1 = addPartner(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 0));
				setRelative(p1, partner, 1);
				setRelative(p1, mother, 2);
				setRelative(p1, father, 3);
				lastAdded = 2;
			}
			else if (relationship == "maz") {
				Pointer p1 = addPartner(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 1));
				setRelative(p1, partner, 1);
				setRelative(p1, mother, 2);
				setRelative(p1, father, 3);
				lastAdded = 2;
			}
			else if (relationship == "corka") {
				Pointer p1 = addChild(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate),  0));
				setRelative(p1, partner, 1);
				setRelative(p1, mother, 2);
				setRelative(p1, father, 3);
				lastAdded = 3;
			}
			else if (relationship == "syn") {
				Pointer p1 = addChild(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 1));
				setRelative(p1, partner, 1);
				setRelative(p1, mother, 2);
				setRelative(p1, father, 3);
				lastAdded = 3;
			}
			else if (relationship == "matka") {
				Pointer p1 = addParent(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 0));
				setRelative(p1, partner, 1);
				setRelative(p1, mother, 2);
				setRelative(p1, father, 3);
				lastAdded = -1;
			}
			else if (relationship == "ojciec")	{
				Pointer p1 = addParent(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 1));
				setRelative(p1, partner, 1);
				setRelative(p1, mother, 2);
				setRelative(p1, father, 3);
				lastAdded = -1;
			}
			else if (relationship == "babcia") {
				Pointer p1 = addGrandParent(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 0));
				setRelative(p1, partner, 1);
				setRelative(p1, mother, 2);
				setRelative(p1, father, 3);
				lastAdded = -2;
			}
			else if (relationship == "dziadek") {
				Pointer p1 = addGrandParent(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 1));
				setRelative(p1, partner, 1);
				setRelative(p1, mother, 2);
				setRelative(p1, father, 3);
				lastAdded = -2;
			}
			else if (relationship == "wnuczka") {
				Pointer p1 = addGrandChild(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 0));
				setRelative(p1, partner, 1);
				setRelative(p1, mother, 2);
				setRelative(p1, father, 3);
				lastAdded = 4;
			}
			else if (relationship == "wnuk") {
				Pointer p1 = addGrandChild(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 1));
				setRelative(p1, partner, 1);
				setRelative(p1, mother, 2);
				setRelative(p1, father, 3);
				lastAdded = 4;
			}
			else if (relationship[0] == 'p' && relationship[1] == 'r' &&  relationship[2] == 'a' ) {
				int counter = 1;
				string rest;
				for (size_t i = 3; i < relationship.length(); i = i + 3) {
					if (relationship[i] == 'p')
						counter++;
					else break;
				}
				for (size_t i = (counter*3); i < relationship.length(); i++) {
					rest += relationship[i];
				}

				if (rest == "babcia") {
					int rel = -(counter);
					Pointer p1 = addPerson(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 0), rel-2);
					setRelative(p1, partner, 1);
					setRelative(p1, mother, 2);
					setRelative(p1, father, 3);
					lastAdded = rel-2;
				}
				else if (rest == "dziadek") {
					int rel = -(counter);
					Pointer p1 = addPerson(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 1), rel - 2);
					setRelative(p1, partner, 1);
					setRelative(p1, mother, 2);
					setRelative(p1, father, 3);
					lastAdded = rel - 2;
				}
				else if (rest == "wnuczka") {
					Pointer p1 = addPerson(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 0), 4 + counter);
					setRelative(p1, partner, 1);
					setRelative(p1, mother, 2);
					setRelative(p1, father, 3);
					lastAdded = 4+counter;
				}
				else if (rest == "wnuk") {
					Pointer p1 = addPerson(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 1), 4 + counter);
					setRelative(p1, partner, 1);
					setRelative(p1, mother, 2);
					setRelative(p1, father, 3);
					lastAdded = 4 + counter;
				}

			}
			else {
				bool gender;
				if (relationship[relationship.length()-1] == 'a')
					gender = 0;
				else gender = 1;
				Pointer p1 = addPerson(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), gender, relationship), lastAdded);
				setRelative(p1, partner, 1);
				setRelative(p1, mother, 2);
				setRelative(p1, father, 3);
			}
		}


			file.close();
			return true;
		}

	else {
		file.close();
		return false;
	}
}

void Tree::exportTree(string filename)
{

	fstream file;
	file.open(filename, std::ios::out);

	for (auto it = _tree.begin(); it != _tree.end(); it++) {
		for (Person person : _tree[it->first]) {
			if (it->first == 0) {
				file << "-> " << person.toString() << " ";
				file << to_string(person.getGender());
			}
			else if (it->first == 3) {
				if (person.getGender() == 0 && person.getRelationship() == " ")
					file << "siostra " << person.toString();
				else if (person.getGender() == 1 && person.getRelationship() == " ")
					file << "brat " << person.toString();
				else if (person.getRelationship() != " ")
					file << person.getRelationship() << " " << person.toString();
			}
			else if (it->first == 1) {
				if (person.getGender() == 0)
					file << "zona " << person.toString();
				else
					file << "maz " << person.toString();
			}
			else if (it->first == 2) {
				if (person.getGender() == 0 && person.getRelationship() == " ")
					file << "corka " << person.toString();
				else if (person.getGender() == 1 && person.getRelationship() == " ")
					file << "syn " << person.toString();
				else if (person.getRelationship() != " ")
					file << person.getRelationship() << " " << person.toString();
			}
			else if (it->first == -1) {
				if (person.getGender() == 0 && person.getRelationship() == " ")
					file << "matka " << person.toString();
				else if (person.getGender() == 1 && person.getRelationship() == " ")
					file << "ojciec " << person.toString();
				else if (person.getRelationship() != " ")
					file << person.getRelationship() << " " << person.toString();
			}
			else if (it->first == -2) {
				if (person.getGender() == 0 && person.getRelationship() == " ")
					file << "babcia " << person.toString();
				else if (person.getGender() == 1 && person.getRelationship() == " ")
					file << "dziadek " << person.toString();
				else if (person.getRelationship() != " ")
					file << person.getRelationship() << " " << person.toString();
			}
			else if (it->first == 4) {
				if (person.getGender() == 0)
					file << "wnuczka " << person.toString();
				else
					file << "wnuk " << person.toString();
			}
			else if (it->first > 4) {
				string s;
				for (int i = 0; i < (it->first - 4); i++) {
					s += "pra";
				}
				if (person.getGender() == 0)
					file << s << "wnuczka " << person.toString();
				else
					file << s << "wnuk " << person.toString();
			}
			else if (it->first < -2) {
				string s;
				int temp = -(it->first);
				for (int i = 0; i < temp - 2; i++) {
					s += "pra";
				}
				if (person.getGender() == 0)
					file << s << "babcia " << person.toString();
				else
					file << s << "dziadek " << person.toString();
			}
            file << endl;
		}
	}
	file.close();
}

int Tree::membersCount()
{
    int ilosc = 0;
    for (auto it = _tree.begin(); it != _tree.end(); it++)
    {
        ilosc += _tree[it->first].size();
    }
    return ilosc;
}

