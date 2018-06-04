#include "Date.h"

using std::stoi;

Date::Date()
	:
	_day(0),
	_month(0),
	_year(0),
	_date("00-00-0000")
{
}

Date::Date(string date)
	:
	_date(date)
{
	string sDay, sMonth, sYear;
	short day, month, year;

	for (int i = 0; i < 10; i++) {
		if (i < 2)
			sDay += date[i];
		else if (i > 2 && i < 5)
			sMonth += date[i];
		else if (i > 5)
			sYear += date[i];
	}
	day = stoi(sDay);
	month = stoi(sMonth);
	year = stoi(sYear);

	this->_day = day;
	this->_month = month;
	this->_year = year;
}

Date::Date(const Date& copy)
	:
	_day(copy._day),
	_month(copy._month),
	_year(copy._year),
	_date(copy._date)
{
}

Date& Date::operator=(const Date& copy)
{
	if (this == &copy)
    {
        return *this;
	}
	this->_day = copy._day;
	this->_month = copy._month;
	this->_year = copy._year;
	this->_date = copy._date;
	return *this;
}


bool Date::operator< (const Date& right)
{
    if(this->_year < right._year )
    {
        return false;
    }
    else if (this->_year == right._year && this->_month < right._month)
    {
        return false;
    }
    else if (this->_year == right._year && this->_month == right._month && this->_day < right._day)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Date::isSet()
{
	if (this->_day == 0)
    {
		return false;
    }
	else
    {
		return true;
    }
}

string Date::getDate()
{
	return this->_date;
}

int Date::getDay()
{
    return this->_day;
}

int Date::getMonth()
{
    return this->_month;
}

int Date::getYear()
{
    return this->_year;
}

ostream& operator<<(ostream& s, const Date& d)
{
	if (d._day>9 && d._month>9)
		return s << d._day << "-" << d._month << "-" << d._year;
	else if (d._day<10 && d._month>9)
		return s << "0" << d._day << "-" << d._month << "-" << d._year;
	else if (d._day>9 && d._month<10)
		return s << d._day << "-" << "0" << d._month << "-" << d._year;
	else
		return s << "0" << d._day << "-" << "0" << d._month << "-" << d._year;
}
