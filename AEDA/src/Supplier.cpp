/*
 * Supplier.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Supplier.h"

unsigned int static supplierID = 1;

Supplier::Supplier(std::string n, int NIF, std::string ad): name(n), address(ad)
{
	this->NIF = NIF;
	id = supplierID;
	supplierID++;
}

Supplier::~Supplier() {
	// TODO Auto-generated destructor stub
}

std::string Supplier::getName() const
{
	return name;
}

std::string Supplier::getAddress() const
{
	return address;
}

int Supplier::getNIF() const
{
	return NIF;
}

int Supplier::getId() const
{
	return id;
}

//std::vector <Offer*> Supplier::getOffers() const
//{
//	return offers;
//}

