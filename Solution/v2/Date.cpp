#include "Date.h"

Date::Date() 
	:
	_day(0),
	_month(0),
	_year(0),
	_date("00-00-0000")
{
}

Date::Date(const Date& copy)
	:
	_day(copy._day),
	_month(copy._month),
	_year(copy._year),
	_date(copy._date)
{
}

Date::Date(string date)
	:
	_date(date)
{
	string sday, smonth, syear;
	short day, month, year;

	for (int i = 0; i < 10; i++) {
		if (i < 2)
			sday += date[i];
		else if (i > 2 && i < 5)
			smonth += date[i];
		else if (i > 5)
			syear += date[i];
	}
	day = (short)std::stoi(sday);
	month = (short)std::stoi(smonth);
	year = (short)std::stoi(syear);

	_day = day;
	_month = month;
	_year = year;
}

Date& Date::operator=(const Date& copy)
{
	if (this == &copy)
		return *this;

	_day = copy._day;
	_month = copy._month;
	_year = copy._year;
	_date = copy._date;
	return *this;
}

bool Date::isSet() {
	if (this->_day == 0)
		return false;
	else
		return true;
}

string Date::getDate() {
	return this->_date;
}

std::ostream & operator<<(std::ostream & s, const Date & d){
	if (d._day>9 && d._month>9)
		return s << d._day << "-" << d._month << "-" << d._year;
	else if (d._day<10 && d._month>9)
		return s << "0" << d._day << "-" << d._month << "-" << d._year;
	else if (d._day>9 && d._month<10)
		return s << d._day << "-" << "0" << d._month << "-" << d._year;
	else 
		return s << "0" << d._day << "-" << "0" << d._month << "-" << d._year;
}