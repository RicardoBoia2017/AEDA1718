/*
 * Offer.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Offer.h"

static unsigned int offerID = 1;

Offer::Offer(int val, int dist, int capacity, std::string bT, std::string dest):
		value(val), distance(dist), boatType (bT), destination(dest) //sup(s)
{
	this->capacity = capacity;
	id = offerID;
	offerID++;
}

Offer::~Offer() {

}

int Offer::getValue() const
{
	return value;
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

std::string Offer::getBoatType() const
{
	return boatType;
}

std::string Offer::getDestination() const
{
	return destination;
}

//Supplier getSupplier() const
//{
//	return sup;
//}
