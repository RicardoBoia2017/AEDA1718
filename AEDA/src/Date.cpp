/*
 * Date.cpp
 *
 *  Created on: 14/11/2017
 *      Author: ricar
 */

#include "Date.h"



Date::Date(unsigned int d, unsigned int m, unsigned int y) {

	if(m < 0 || m > 12)
		throw ExceptionInvalidDate("month",m);
	if(d < 0 || d > 31)
		throw ExceptionInvalidDate("day",d);
	if((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
		if(m == 2 && y%4 == 0 && d > 29)
			throw ExceptionInvalidDate("day",d);
	if(m == 2 && y%4 != 0 && d > 28)
		throw ExceptionInvalidDate("day",d);

		day = d;
		month = m;
		year = y;
}

Date::Date(std::string date)
{
	std::string d = date.substr(0, date.find('-'));
	date = date.substr(date.find('-') + 1);
	std::string m = date.substr(0, date.find('-'));
	date = date.substr(date.find('-') + 1);

	day = (unsigned int) std::stoi(d.c_str());
	month = (unsigned int) std::stoi(m.c_str());;
	year = (unsigned int) std::stoi(date.c_str());;

}

Date::~Date() {
	// TODO Auto-generated destructor stub
}

unsigned int Date::getDay() const
{
	return this->day;
}

unsigned int Date::getMonth() const
{
	return this->month;
}

unsigned int Date::getYear() const
{
	return this->year;
}

bool Date::operator<= (const Date& right) const
{
	std::vector<int> l,r;

	l.push_back(this->year);
	l.push_back(this->month);
	l.push_back(this->day);
	r.push_back(right.year);
	r.push_back(right.month);
	r.push_back(right.day);

	if (l == r)
		return true;

	for(unsigned int i = 0; i < l.size(); i++)
	{
		if(l[i] < r[i])
			return true;
		else if(l[i] > r[i])
			return false;
	}

	return false;
}

bool Date::operator==(const Date& right) const
{
	if(this->day == right.day && this->month== right.month && this->year == right.year)
		return true;

	return false;
}





