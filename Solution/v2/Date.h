#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Date{
private:
	short _day;
	short _month;
	short _year;
	string _date;
public:
	Date();
	Date(const Date&);
	Date(string);
	Date& operator=(const Date&);
	bool isSet();
	string getDate();
	friend std::ostream & operator<<(std::ostream &, const Date & );
};
#endif