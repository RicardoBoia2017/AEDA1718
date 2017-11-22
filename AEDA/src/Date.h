/*
 * Date.h
 *
 *  Created on: 14/11/2017
 *      Author: ricar
 */

#ifndef AEDA_SRC_DATE_H_
#define AEDA_SRC_DATE_H_

#include <string>
#include <vector>
#include <fstream>

using namespace std;


class ExceptionInvalidDate
{
private:
	string component;
	int value;

public:
	ExceptionInvalidDate(string comp, int v):
		component (comp), value (v)
	{}
};

class Date {
private:
	unsigned int day;
	unsigned int month;
	unsigned int year;
public:
	Date (unsigned int d, unsigned int m, unsigned int y);
	Date (string date);
	virtual ~Date();
	unsigned int getDay() const;
	unsigned int getMonth() const;
	unsigned int getYear() const;
	unsigned int convertToDays();
	unsigned int daysBetween (Date d1);
	bool operator<= (const Date& right) const;
	bool operator==(const Date& right) const;
	bool validateDate();
};


#endif /* AEDA_SRC_DATE_H_ */
