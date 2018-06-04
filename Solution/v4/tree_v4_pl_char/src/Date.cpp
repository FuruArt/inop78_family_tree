#include "Date.h"

using std::stoi;

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
