/*
 * Reservation.cpp
 *
 *  Created on: 21/12/2017
 *      Author: ricar
 */

#include "Reservation.h"

using namespace std;



Reservation::Reservation(Offer* o1, RegisteredClient *c1, Date d1)
{
	this->offer = o1;
	this->client = c1;
	this->date = d1;
}

Reservation::Reservation(Offer* o1, OccasionalClient *c1, Date d1)
{
	this->offer = o1;
	this->client = c1;
	this->date = d1;
}

Reservation::~Reservation()
{

}


bool Reservation::operator<(const Reservation & r2) const {
	if (getClient() == r2.getClient())
		return this->getDate() <= r2.getDate();

	return this->getClient() < r2.getClient();
}


bool Reservation::operator ==(const Reservation &r2) const
{
	if (this->client == r2.getClient())
		if (this->date == r2.getDate())
			if (this->getOffer() == r2.getOffer())
				return true;
	return false;

}
Client *Reservation::getClient() const
{
	return this->client;
}

Offer* Reservation::getOffer() const
{
	return this->offer;
}

Date Reservation::getDate() const
{
	return this->date;
}

