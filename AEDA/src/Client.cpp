/*
 * Client.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Client.h"

Client::Client(std::string n, int NIF): name(n)
{
	this->NIF = NIF;
}

Client::~Client() {

}

std::string Client::getName() const
{
	return name;
}

int Client::getNIF() const
{
	return NIF;
}



//Registered Client


static int reg_clientID = 1;

RegisteredClient::RegisteredClient(std::string n, int NIF, int points): Client(n,NIF)
{
	this->points=points;
	reg_id = reg_clientID;
	reg_clientID ++;
}

RegisteredClient::~RegisteredClient() {

}

int RegisteredClient::getId() const
{
	return reg_id;
}

int RegisteredClient::getPoints() const
{
	return points;
}

void RegisteredClient::setPoints(unsigned int p)
{
	points = p;
}

std::string RegisteredClient::getInformation() const
{
	std::stringstream ss;

	ss << getId() << " " << getName() << ", " << getNIF() << ", Points: " << getPoints();

	return ss.str() ;
}

std::ostream &operator<< (std::ostream &os, RegisteredClient &rc1)
{
	os << rc1.getId() << ", " << rc1.getName() << ", " << rc1.getNIF() << ", " << rc1.getPoints() << ";" ;
	return os;
}



//Occasional Client

static int oc_clientID = 1;

OccasionalClient::OccasionalClient(std::string n, int NIF): Client(n,NIF)
{
	oc_id = oc_clientID;
	oc_clientID++;
}

OccasionalClient::~OccasionalClient()
{

}

int OccasionalClient::getId() const
{
	return oc_id;
}

void OccasionalClient::setId(int id)
{
	oc_id = id;
}

std::string OccasionalClient::getInformation() const
{
	std::stringstream ss;

	ss << getId() << " " << getName() << ", " << getNIF();

	return ss.str() ;
}

std::ostream &operator<< (std::ostream &os, OccasionalClient &oc1)
{
	os << oc1.getId() << ", " << oc1.getName() << ", " << oc1.getNIF() << ";" ;
	return os;
}
