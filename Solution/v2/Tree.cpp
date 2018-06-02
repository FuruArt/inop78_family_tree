#include "Tree.h"

Pointer Tree::addUser(const Person& _person) {
	_tree[0].push_back(_person);
	Pointer p;
	p.map = 0;
	p.vector = _tree[0].size() - 1;
	return p;
}

Pointer Tree::addGrandParent(const Person&person) {
	_tree[-2].push_back(person);
	Pointer p;
	p.map = -2;
	p.vector = _tree[-2].size() - 1;
	return p;
}

Pointer Tree::addParent(const Person&person) {
	_tree[-1].push_back(person);
	Pointer p;
	p.map = -1;
	p.vector = _tree[-1].size() - 1;
	return p;
}

Pointer Tree::addSibling(const Person& person) {
	_tree[3].push_back(person);
	Pointer p;
	p.map = 3;
	p.vector = _tree[3].size() - 1;
	return p;
}

Pointer Tree::addPartner(const Person& person) {
	_tree[1].push_back(person);
	Pointer p;
	p.map = 1;
	p.vector = _tree[1].size() - 1;
	return p;
}

Pointer Tree::addChild(const Person& person) {
	_tree[2].push_back(person);
	Pointer p;
	p.map = 2;
	p.vector = _tree[2].size() - 1;
	return p;
}

Pointer Tree::addGrandChild(const Person& person) {
	_tree[4].push_back(person);
	Pointer p;
	p.map = 4;
	p.vector = _tree[4].size() - 1;
	return p;
}

Pointer Tree::addPerson(const Person& person, int rel) {
	_tree[rel].push_back(person);
	Pointer p;
	p.map = rel;
	p.vector = _tree[rel].size() - 1;
	return p;
}

void Tree::printTree(map<int, vector<Person>> tree)
{
	
	for (auto it = tree.begin(); it != tree.end(); it++) {
		for (Person person : tree[it->first]) {
			if (it->first == 0)
				cout << "-> " << person << endl;
			else if (it->first == 3) {
				if (person.getGender() == 0 && person.getRelationship()==" ")
					cout << "siostra " << person << endl;
				else if(person.getGender() == 1 && person.getRelationship() == " ")
					cout << "brat " << person << endl;
				else if (person.getRelationship() != " ")
					cout << person.getRelationship() << " " << person << endl;
			}
			else if (it->first == 1) {
				if (person.getGender() == 0)
					cout << "¿ona " << person << endl;
				else
					cout << "m¹¿ " << person << endl;
			}
			else if (it->first == 2) {
				if (person.getGender() == 0 && person.getRelationship() == " ")
					cout << "córka " << person << endl;
				else if(person.getGender() == 1 && person.getRelationship() == " ")
					cout << "syn " << person << endl;
				else if (person.getRelationship() != " ")
					cout << person.getRelationship() << " " << person << endl;
			}
			else if (it->first == -1) {
				if (person.getGender() == 0 && person.getRelationship() == " ")
					cout << "matka " << person << endl;
				else if(person.getGender() == 1 && person.getRelationship() == " ")
					cout << "ojciec " << person << endl;
				else if (person.getRelationship() != " ")
					cout << person.getRelationship() << " " << person << endl;
			}
			else if (it->first == -2) {
				if (person.getGender() == 0 && person.getRelationship() == " ")
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

void Tree::memberTree(Pointer member) {
	map<int, vector<Person>> memberTree;

	Pointer mother, father, partner;
	
	mother = _tree[member.map].at(member.vector).getMother();
	father = _tree[member.map].at(member.vector).getFather();
	partner = _tree[member.map].at(member.vector).getPartner();

	memberTree[0].push_back(_tree[member.map].at(member.vector));


	if (mother.map != 404) {
		memberTree[-1].push_back(_tree[mother.map].at(mother.vector));
	}

	if (father.map != 404) {
		memberTree[-1].push_back(_tree[father.map].at(father.vector));
	}

	if (partner.map != 404) {
		memberTree[1].push_back(_tree[partner.map].at(partner.vector));
	}

	Pointer child;
	for (auto it = _tree.begin(); it != _tree.end(); it++) {
		int vector = 0;
		for (Person person : _tree[it->first]) {
			if ((person.getFather().map == member.map && person.getFather().vector == member.vector)
				|| (person.getMother().map == member.map && person.getMother().vector == member.vector)) {
				child.map = it->first;
				child.vector = vector;
				memberTree[2].push_back(_tree[child.map].at(child.vector));
			}
			++vector;
		}
	}

	Pointer sibling;
	for (auto it = _tree.begin(); it != _tree.end(); it++) {
		int vector = 0;
		for (Person person : _tree[it->first]) {
			if ((person.getFather().map == father.map && person.getFather().vector == father.vector)
				|| (person.getMother().map == mother.map && person.getMother().vector == mother.vector)) {
				sibling.map = it->first;
				sibling.vector = vector;
				if (sibling.map != member.map || sibling.vector != member.vector) {
					memberTree[3].push_back(_tree[sibling.map].at(sibling.vector));
				}
			}
			++vector;
		}
	}



	printTree(memberTree);
}

Pointer Tree::Find(string firstname, string lastname) {
	Pointer wsk;
	for (auto it = _tree.begin(); it != _tree.end(); it++) {
		int vector = 0;
		for (Person person : _tree[it->first]) {
			if (person.getFirstName() == firstname && person.getLastName() == lastname) {
				wsk.map = it->first;
				wsk.vector = vector;
				return wsk;
			}
			++vector;
		}
	}
	wsk.map = 404;
	wsk.vector = 404;
	return wsk;
}

void Tree::setRel(Pointer pointer1, Pointer pointer2, int rel) {
	if (rel == 1) {
		_tree[pointer1.map].at(pointer1.vector).setPartner(pointer2);
	}
	else if (rel == 2) {
		_tree[pointer1.map].at(pointer1.vector).setMother(pointer2);
	}
	else if (rel == 3) {
		_tree[pointer1.map].at(pointer1.vector).setFather(pointer2);
	}
}

void Tree::Delete(Pointer pointer) {
	auto it = _tree[pointer.map].begin()+pointer.vector;
	_tree[pointer.map].erase(it);
}

void Tree::Edit(Pointer pointer, const Person& person) {
	
	_tree[pointer.map].at(pointer.vector) = person;

}

bool Tree::Import(string filename) {
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
			file >> mother.map >> mother.vector;
			file >> father.map >> father.vector;
			file >> partner.map >> partner.vector;
		
			if (familyName == "n")
				familyName = " ";
			
			if (relationship == "->") {
				bool gender;
				file >> gender;
				Pointer p1 = addUser(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), gender));
				setRel(p1, partner, 1);
				setRel(p1, mother, 2);
				setRel(p1, father, 3);
				lastAdded = 0;
			}
			else if (relationship == "siostra") {
				Pointer p1 = addSibling(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 0));
				setRel(p1, partner, 1);
				setRel(p1, mother, 2);
				setRel(p1, father, 3);
				lastAdded = 1;
			}
			else if (relationship == "brat") {
				Pointer p1 = addSibling(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 1));
				setRel(p1, partner, 1);
				setRel(p1, mother, 2);
				setRel(p1, father, 3);
				lastAdded = 1;
			}
			else if (relationship == "¿ona") {
				Pointer p1 = addPartner(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 0));
				setRel(p1, partner, 1);
				setRel(p1, mother, 2);
				setRel(p1, father, 3);
				lastAdded = 2;
			}
			else if (relationship == "m¹¿") {
				Pointer p1 = addPartner(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 1));
				setRel(p1, partner, 1);
				setRel(p1, mother, 2);
				setRel(p1, father, 3);
				lastAdded = 2;
			}
			else if (relationship == "córka") {
				Pointer p1 = addChild(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate),  0));
				setRel(p1, partner, 1);
				setRel(p1, mother, 2);
				setRel(p1, father, 3);
				lastAdded = 3;
			}
			else if (relationship == "syn") {
				Pointer p1 = addChild(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 1));
				setRel(p1, partner, 1);
				setRel(p1, mother, 2);
				setRel(p1, father, 3);
				lastAdded = 3;
			}
			else if (relationship == "matka") {
				Pointer p1 = addParent(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 0));
				setRel(p1, partner, 1);
				setRel(p1, mother, 2);
				setRel(p1, father, 3);
				lastAdded = -1;
			}
			else if (relationship == "ojciec")	{
				Pointer p1 = addParent(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 1));
				setRel(p1, partner, 1);
				setRel(p1, mother, 2);
				setRel(p1, father, 3);
				lastAdded = -1;
			}
			else if (relationship == "babcia") {
				Pointer p1 = addGrandParent(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 0));
				setRel(p1, partner, 1);
				setRel(p1, mother, 2);
				setRel(p1, father, 3);
				lastAdded = -2;
			}
			else if (relationship == "dziadek") {
				Pointer p1 = addGrandParent(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 1));
				setRel(p1, partner, 1);
				setRel(p1, mother, 2);
				setRel(p1, father, 3);
				lastAdded = -2;
			}
			else if (relationship == "wnuczka") {
				Pointer p1 = addGrandChild(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 0));
				setRel(p1, partner, 1);
				setRel(p1, mother, 2);
				setRel(p1, father, 3);
				lastAdded = 4;
			}
			else if (relationship == "wnuk") {
				Pointer p1 = addGrandChild(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 1));
				setRel(p1, partner, 1);
				setRel(p1, mother, 2);
				setRel(p1, father, 3);
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
					setRel(p1, partner, 1);
					setRel(p1, mother, 2);
					setRel(p1, father, 3);
					lastAdded = rel-2;
				}
				else if (rest == "dziadek") {
					int rel = -(counter);
					Pointer p1 = addPerson(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 1), rel - 2);
					setRel(p1, partner, 1);
					setRel(p1, mother, 2);
					setRel(p1, father, 3);
					lastAdded = rel - 2;
				}
				else if (rest == "wnuczka") {
					Pointer p1 = addPerson(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 0), 4 + counter);
					setRel(p1, partner, 1);
					setRel(p1, mother, 2);
					setRel(p1, father, 3);
					lastAdded = 4+counter;
				}
				else if (rest == "wnuk") {
					Pointer p1 = addPerson(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), 1), 4 + counter);
					setRel(p1, partner, 1);
					setRel(p1, mother, 2);
					setRel(p1, father, 3);
					lastAdded = 4 + counter;
				}

			}
			else {
				bool gender;
				if (relationship[relationship.length()-1] == 'a')
					gender = 0;
				else gender = 1;
				Pointer p1 = addPerson(Person(firstName, lastName, familyName, Date(birthDate), Date(deathDate), gender, relationship), lastAdded);
				setRel(p1, partner, 1);
				setRel(p1, mother, 2);
				setRel(p1, father, 3);
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

void Tree::Export(string filename) {

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
					file << "¿ona " << person.toString();
				else
					file << "m¹¿ " << person.toString();
			}
			else if (it->first == 2) {
				if (person.getGender() == 0 && person.getRelationship() == " ")
					file << "córka " << person.toString();
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