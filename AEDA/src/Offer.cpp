/*
 * Offer.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Offer.h"

static unsigned int offerID = 1;

/**
 * The constructor.
 * @param pri price.
 * @param dist distance.
 * @param capacity capacity.
 * @param bT boat type.
 * @param dest destination.
 * @param sName supName.
 * @param points points.
 * @param percentage which is gonna be divided by 100, converting it to a decimal number.
 * @param d date.
 */
Offer::Offer(int pri, int dist, int capacity, string bT, string dest, string sName, unsigned int points, double percentage, Date d, Date lR):
		price(pri), distance(dist), boatType (bT), destination(dest), supName(sName), date(d), lastReservation (lR)
{
	this->points=points;
	this->capacity = capacity;
	this->percentage = percentage/100;
	vacancies = capacity;
	this->discount = 0;
	id = offerID;
	offerID++;
}

/**
 * The destructor.
 */
Offer::~Offer() {

}


/**
 * @return price.
 */
unsigned int Offer::getPrice() const
{
	return price;
}

/**
 * @return id.
 */
unsigned int Offer::getId() const
{
	return id;
}

void Offer::resetId()
{
	offerID = 1;
}

/**
 * @return distance.
 */
unsigned int Offer::getDistance() const
{
	return distance;
}

/**
 * @return capacity.
 */
unsigned int Offer::getCapacity() const
{
	return capacity;
}

/**
 * @return vacancies.
 */
unsigned int Offer::getVacancies() const
{
	return vacancies;
}

Date Offer::getLastReservation() const
{
	return lastReservation;
}

void Offer::setVacancies(unsigned int newValue)
{
	vacancies = newValue;
}

/**
 * @return points.
 */
unsigned int Offer::getPoints() const
{
	return points;
}

/**
 * @return date.
 */
Date Offer::getDate() const
{
	return date;
}


void Offer::setLastReservation(const Date &newDate)
{
	if (newDate <= lastReservation)
		this->lastReservation = newDate;

	discount = 0;
}
/**
 * @return percentage.
 */

double Offer::getPercentage() const
{
	return percentage;
}

double Offer::getDiscount() const
{
	return discount;
}

void Offer::setDiscount(double newValue)
{
	discount = newValue;
}
/**
 * @return boat type.
 */
string Offer::getBoatType() const
{
	return boatType;
}

/**
 * @return destination.
 */
string Offer::getDestination() const
{
	return destination;
}

/**
 * @return string with the offer's information.
 */
string Offer::getInformation() const
{
	stringstream ss;
	Date d1 = getDate();

	ss << getId() << " " << d1.getDay() << "/" << d1.getMonth() << "/" << d1.getYear() << ", " <<  getSupName() << ", " << getDestination() << ", " << getDistance() << "km, " <<  getBoatType() << ", " << getPrice() << "€ "
			<< "//  seats available: " << getVacancies() << endl << "Points / ticket : " << getPoints() << " (only available for registered clients)" << endl;

	return ss.str();
}

/**
 * @return supName.
 */
string Offer::getSupName() const
{
	return supName;
}

/**
 * @return sup.
 */
Supplier * Offer::getSupplier() const
{
	return sup;
}

/**
 * Sets supplier equal to s.
 *  @param s new supplier.
 */
void Offer::setSupplier(Supplier * s)
{
	sup=s;
}

/** Writes to ofstream the offer's information in the format used in text files.

 * @param os ofstream where is stored the information.
 * @param o1 offer which information is going to be read.
 */
ostream &operator<< (ostream &os, Offer &o1)
{
	double perc = o1.getPercentage() * 100;
	Date d1 = o1.getDate();

	os << o1.getId()  << ", " << d1.getDay() << "/" << d1.getMonth() << "/" << d1.getYear() <<  ", " <<  o1.getSupName() << ", " << o1.getPrice() << ", " << o1.getDistance() << ", " << o1.getVacancies() << ", " <<
			o1.getBoatType() << ", " << o1.getDestination() << ", " << o1.getPoints() << ", " << perc << ", "
			<< o1.getLastReservation().getDay() << "/" << o1.getLastReservation().getMonth() << "/" << o1.getLastReservation().getYear() << ";";

	return os;
}

bool Offer::operator< (const Offer &o2) const
{
	return o2.getLastReservation() <= this->lastReservation;
}

bool Offer::operator== (const Offer &o2) const
{
	return id == o2.getId();
}

