/*
 * Offer.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Offer.h"

static unsigned int offerID = 1;

Offer::Offer(int pri, int dist, int capacity, std::string bT, std::string dest, std::string sName):
		price(pri), distance(dist), boatType (bT), destination(dest), supName(sName)
{
	this->capacity = capacity;
	vacancies = capacity;
	id = offerID;
	offerID++;
}

Offer::~Offer() {

}

void Offer::PrepareReservation(Client * c, int nTick)
{

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
	//std::string supName = sup->getName();
	ss << getId() << " " << getSupName() << ", " << getDestination() << ", " << getDistance() << "km " <<  getBoatType() << ", " << getPrice() << " € " << "//  seats available: " << getVacancies();

	return ss.str();
}

std::string Offer::getSupName() const
{
	return supName;
}

Supplier * Offer::getSupplier() const
{
	return sup;
}

void Offer::setSupplier(Supplier * s)
{
	sup=s;
}

std::vector <Client*> Offer::getClients() const
{

}
