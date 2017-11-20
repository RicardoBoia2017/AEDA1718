/*
 * Client.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Client.h"

Client::Client(string n, unsigned int NIF): name(n)
{
	this->NIF = NIF;
}

Client::~Client() {

}

string Client::getName() const
{
	return name;
}

unsigned int Client::getNIF() const
{
	return NIF;
}



//Registered Client


static unsigned int reg_clientID = 1;

RegisteredClient::RegisteredClient(string n, unsigned int NIF, unsigned int points): Client(n,NIF)
{
	this->points=points;
	reg_id = reg_clientID;
	reg_clientID ++;
}

RegisteredClient::~RegisteredClient() {

}

unsigned int RegisteredClient::getId() const
{
	return reg_id;
}

unsigned int RegisteredClient::getPoints() const
{
	return points;
}

void RegisteredClient::setPoints(unsigned int p)
{
	points = p;
}

string RegisteredClient::getInformation() const
{
	stringstream ss;

	ss << getId() << " " << getName() << ", " << getNIF() << ", Points: " << getPoints();

	return ss.str() ;
}

ostream &operator<< (ostream &os, RegisteredClient &rc1)
{
	os << rc1.getId() << ", " << rc1.getName() << ", " << rc1.getNIF() << ", " << rc1.getPoints() << ";" ;
	return os;
}



//Occasional Client

static unsigned int oc_clientID = 1;

OccasionalClient::OccasionalClient(string n, unsigned int NIF): Client(n,NIF)
{
	oc_id = oc_clientID;
	oc_clientID++;
}

OccasionalClient::~OccasionalClient()
{

}

unsigned int OccasionalClient::getId() const
{
	return oc_id;
}

void OccasionalClient::setId(unsigned int id)
{
	oc_id = id;
}

string OccasionalClient::getInformation() const
{
	stringstream ss;

	ss << getId() << " " << getName() << ", " << getNIF();

	return ss.str() ;
}

ostream &operator<< (ostream &os, OccasionalClient &oc1)
{
	os << oc1.getId() << ", " << oc1.getName() << ", " << oc1.getNIF() << ";" ;
	return os;
}
