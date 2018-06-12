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
    Person::Person(firstName,lastName,familyName,birthDate,deathDate,gender)
{
	_relationship = rel;
}

std::ostream & operator<<(std::ostream & s, Person & p)
{

	if (p._familyName != "n")
		s << p._firstName << " " << p._lastName << " (" << p._familyName << ") " << " ur. " << p._birthDate.getDate();
	else
		s << p._firstName << " " << p._lastName << " ur. " << p._birthDate.getDate();

	if (p._deathDate.isSet()) {
		s << " zm. " << p._deathDate.getDate();
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
	if (this->_familyName == "n")
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
