/*
 * Offer.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Offer.h"

static unsigned int offerID = 1;

Offer::Offer(int pri, int dist, int capacity, std::string bT, std::string dest, std::string sName):
		price(pri), distance(dist), boatType (bT), destination(dest), supplier(sName)
{
	this->capacity = capacity;
	vacancies = capacity;
	id = offerID;
	offerID++;
}

Offer::~Offer() {

}

int Offer::getPrice() const
{
	return price;
}

int Offer::getId() const
{
	return id;
}

int Offer::getDistance() const
{
	return distance;
}

int Offer::getCapacity() const
{
	return capacity;
}

int Offer::getVacancies() const
{
	return vacancies;
}

std::string Offer::getBoatType() const
{
	return boatType;
}

std::string Offer::getDestination() const
{
	return destination;
}

std::string Offer::getInformation() const
{
	std::stringstream ss;

	ss << getId() << " " << getDestination() << " " << getDistance() << "km " <<  getBoatType() << " " << getPrice() << " € " << "//seats available: " << getVacancies();

	return ss.str();
}



Supplier * Offer::getSupplier() const
{
	return sup;
}

Client * Offer::getClient() const
{

}
