/*
 * Supplier.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Supplier.h"

unsigned int static supplierID = 1;

Supplier::Supplier(string n, unsigned int NIF, string ad): name(n), address(ad)
{
	this->NIF = NIF;
	id = supplierID;
	supplierID++;
}

Supplier::~Supplier() {
	// TODO Auto-generated destructor stub
}

string Supplier::getName() const
{
	return name;
}

string Supplier::getAddress() const
{
	return address;
}

unsigned int Supplier::getNIF() const
{
	return NIF;
}

unsigned int Supplier::getId() const
{
	return id;
}

string Supplier::getInformation () const
{
	stringstream ss;

	ss << getId() << " " << getName() << ", " << getNIF() << endl << "Address: " << getAddress() << endl;

	return ss.str();
}

ostream &operator<< (ostream &os, Supplier &s1)
{
	os << s1.getId() << ", " << s1.getName() <<  ", " << s1.getNIF() << ", " << s1.getAddress() << ";";
	return os;
}

