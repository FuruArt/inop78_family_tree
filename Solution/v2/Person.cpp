#include "Person.h"

Person::Person()
	:
	_firstName(" "),
	_lastName(" "),
	_familyName(" "),
	_birthDate(Date("00-00-0000")),
	_deathDate(Date("00-00-0000")),
	_gender(0),
	_relationship(" ")
{
	_father.map = 404;
	_father.vector = 404;
	_mother.map = 404;
	_mother.vector = 404;
	_partner.map = 404;
	_partner.vector = 404;
}

Person::Person(string firstName, string lastName, string familyName, Date birthDate, Date deathDate, bool gender)
	:
	_firstName(firstName),
	_lastName(lastName),
	_familyName(familyName),
	_birthDate(Date(birthDate)),
	_deathDate(Date(deathDate)),
	_gender(gender),
	_relationship(" ")
{
	_father.map = 404;
	_father.vector = 404;
	_mother.map = 404;
	_mother.vector = 404;
	_partner.map = 404;
	_partner.vector = 404;
}

Person::Person(string firstName, string lastName, string familyName, Date birthDate, Date deathDate, bool gender, string rel)
	:
	_firstName(firstName),
	_lastName(lastName),
	_familyName(familyName),
	_birthDate(Date(birthDate)),
	_deathDate(Date(deathDate)),
	_gender(gender),
	_relationship(rel)
{
	_father.map = 404;
	_father.vector = 404;
	_mother.map = 404;
	_mother.vector = 404;
	_partner.map = 404;
	_partner.vector = 404;
}

Person::Person(const Person& copy)
	:
	_firstName(copy._firstName),
	_lastName(copy._lastName),
	_familyName(copy._familyName),
	_birthDate(copy._birthDate),
	_deathDate(copy._deathDate),
	_gender(copy._gender),
	_relationship(copy._relationship)
{
	_father.map = copy._father.map;
	_father.vector = copy._father.vector;
	_mother.map = copy._mother.map;
	_mother.vector = copy._mother.vector;
	_partner.map = copy._partner.map;
	_partner.vector = copy._partner.vector;
}

void Person::setMother(Pointer pointer) {
	this->_mother = pointer;
}

void Person::setFather(Pointer pointer) {
	this->_father = pointer;
}

void Person::setPartner(Pointer pointer) {
	this->_partner = pointer;
}

Person& Person::operator=(const Person& copy) {
	if (this == &copy)
		return *this;

	_firstName = copy._firstName;
	_lastName = copy._lastName;
	_familyName = copy._familyName;
	_birthDate = copy._birthDate;
	_deathDate = copy._deathDate;
	_gender = copy._gender;
	_relationship = copy._relationship;

	_father.map = copy._father.map;
	_father.vector = copy._father.vector;
	_mother.map = copy._mother.map;
	_mother.vector = copy._mother.vector;
	_partner.map = copy._partner.map;
	_partner.vector = copy._partner.vector;

	return *this;
}

std::ostream & operator<<(std::ostream & s, Person & p) {
	
	if (p._familyName != " ")
		s << p._firstName << " " << p._lastName << " (" << p._familyName << ") " << " ur. " << p._birthDate;
	else
		s << p._firstName << " " << p._lastName << " ur. " << p._birthDate;
	
	if (p._deathDate.isSet()) {
		s << " zm. " << p._deathDate;
	}
	return s;
}

string Person::getRelationship() {
	return this->_relationship;
}

bool Person::getGender() {
	return this->_gender;
}

string Person::getFirstName() {
	return this->_firstName;
}

string Person::getLastName() {
	return this->_lastName;
}

Pointer Person::getMother() {
	return this->_mother;
}

Pointer Person::getFather() {
	return this->_father;
}

Pointer Person::getPartner() {
	return this->_partner;
}

string Person::toString() {
	string person;
	person += this->_firstName + ' ';
	person += this->_lastName +  ' ';
	if (this->_familyName == " ")
		person += "n ";
	else
		person += this->_familyName += ' ';
	
	person += this->_birthDate.getDate() + ' ';
	person += this->_deathDate.getDate() + ' ';

	person+= to_string(this->_mother.map) + " " + to_string(this->_mother.vector)+" ";
	person += to_string(this->_father.map) + " " + to_string(this->_father.vector) + " ";
	person += to_string(this->_partner.map) + " " + to_string(this->_partner.vector);

	return person;
}