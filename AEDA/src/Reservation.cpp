/*
 * Reservation.cpp
 *
 *  Created on: 21/12/2017
 *      Author: ricar
 */

#include "Reservation.h"

using namespace std;

static unsigned int reservation_ID = 1;


Reservation::Reservation(Offer* o1, RegisteredClient *c1, Date d1)
{
	this->offer = o1->getId();
	this->client= c1;
	this->date = d1;
	id = reservation_ID;
	reservation_ID++;
}

Reservation::Reservation(Offer* o1, OccasionalClient *c1, Date d1)
{
	this->offer = o1->getId();
	this->client = c1;
	this->date = d1;
	id = reservation_ID;
	reservation_ID++;
}

Reservation::Reservation(string cName, unsigned int offerId, Date d1, unsigned int nT)
{
	this->offer = offerId;
	this->clientName = cName;
	this->date = d1;
	this->nTick = nT;
	id = reservation_ID;
	reservation_ID++;
}

Reservation::~Reservation()
{

}

void Reservation::setClient(Client * c)
{
	client=c;
}

void Reservation::setTickets(unsigned int newValue)
{
	this->nTick = newValue;
}

bool Reservation::operator<(const Reservation & r2) const {
	if (getClient()->getName() == r2.getClient()->getName())
		return this->getDate() <= r2.getDate();

	return this->getClient()->getName() < r2.getClient()->getName();
}


bool Reservation::operator ==(const Reservation &r2) const
{
	if (this->client == r2.getClient())
		if (this->date == r2.getDate())
			if (this->getOffer() == r2.getOffer())
				return true;
	return false;

}
Client * Reservation::getClient() const
{
	return this->client;
}

string Reservation::getClientName() const
{
	return this->clientName;
}

unsigned int Reservation::getOffer() const
{
	return this->offer;
}

Date Reservation::getDate() const
{
	return this->date;
}

unsigned int Reservation::getId() const
{
	return this->id;
}

unsigned int Reservation::getTickets() const
{
	return this->nTick;
}

ostream &operator<< (ostream &os, Reservation &r1)
{
	os << r1.getId() << ", " << r1.getDate().getDay() << "/" << r1.getDate().getMonth() << "/" << r1.getDate().getYear() << ", " << r1.getClientName()
			<< ", " << r1.getOffer() << ", " << r1.getTickets() << ";" ;
}

