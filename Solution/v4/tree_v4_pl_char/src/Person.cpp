#include "Person.h"

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
	_father._map = 404;
	_father._vector = 404;
	_mother._map = 404;
	_mother._vector = 404;
	_partner._map = 404;
	_partner._vector = 404;
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
	_father._map = 404;
	_father._vector = 404;
	_mother._map = 404;
	_mother._vector = 404;
	_partner._map = 404;
	_partner._vector = 404;
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
	_father._map = copy._father._map;
	_father._vector = copy._father._vector;
	_mother._map = copy._mother._map;
	_mother._vector = copy._mother._vector;
	_partner._map = copy._partner._map;
	_partner._vector = copy._partner._vector;
}

Person& Person::operator=(const Person& copy)
{
	if (this == &copy)
		return *this;

	_firstName = copy._firstName;
	_lastName = copy._lastName;
	_familyName = copy._familyName;
	_birthDate = copy._birthDate;
	_deathDate = copy._deathDate;
	_gender = copy._gender;
	_relationship = copy._relationship;

	_father._map = copy._father._map;
	_father._vector = copy._father._vector;
	_mother._map = copy._mother._map;
	_mother._vector = copy._mother._vector;
	_partner._map = copy._partner._map;
	_partner._vector = copy._partner._vector;

	return *this;
}

std::ostream & operator<<(std::ostream & s, Person & p)
{

	if (p._familyName != " ")
		s << p._firstName << " " << p._lastName << " (" << p._familyName << ") " << " ur. " << p._birthDate;
	else
		s << p._firstName << " " << p._lastName << " ur. " << p._birthDate;

	if (p._deathDate.isSet()) {
		s << " zm. " << p._deathDate;
	}
	return s;
}

void Person::setMother(Pointer pointer)
{
	this->_mother = pointer;
}

void Person::setFather(Pointer pointer)
{
	this->_father = pointer;
}

void Person::setPartner(Pointer pointer)
{
	this->_partner = pointer;
}

string Person::getRelationship()
{
	return this->_relationship;
}

bool Person::getGender()
{
	return this->_gender;
}

string Person::getFirstName()
{
	return this->_firstName;
}

string Person::getLastName()
{
   	return this->_lastName;
}

Pointer Person::getMother()
{
	return this->_mother;
}

Pointer Person::getFather()
{
	return this->_father;
}

Pointer Person::getPartner()
{
	return this->_partner;
}

string Person::toString()
{
	string person;
	person += this->_firstName + ' ';
	person += this->_lastName +  ' ';
	if (this->_familyName == " ")
    {
        person += "n ";
    }
	else
	{
	    person += this->_familyName += ' ';
	}

	person += this->_birthDate.getDate() + ' ';
	person += this->_deathDate.getDate() + ' ';

	person+= to_string(this->_mother._map) + " " + to_string(this->_mother._vector)+" ";
	person += to_string(this->_father._map) + " " + to_string(this->_father._vector) + " ";
	person += to_string(this->_partner._map) + " " + to_string(this->_partner._vector);

	return person;
}
