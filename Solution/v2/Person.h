#ifndef PERSON_H
#define PERSON_H

#include "Date.h"

using std::ostream;
using std::to_string;
typedef struct { int map; int vector; } Pointer;

class Person {
private:
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
	Person();
	Person(string, string, string, Date, Date, bool);
	Person(string, string, string, Date, Date, bool, string);
	Person(const Person&);
	Person& operator=(const Person&);
	friend ostream & operator<<(ostream&, Person&);
	
	string getRelationship();
	bool getGender();
	string getFirstName();
	string getLastName();
	Pointer getMother();
	Pointer getFather();
	Pointer getPartner();
	void setMother(Pointer);
	void setFather(Pointer);
	void setPartner(Pointer);
	string toString();
};

#endif