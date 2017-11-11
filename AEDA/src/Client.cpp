/*
 * Client.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Client.h"

static unsigned int clientID = 1;

Client::Client(std::string n, int NIF): name(n)
{
	this->NIF = NIF;
	id = clientID;
	clientID ++;
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


int Client::getID() const
{
	return id;
}

//Registered Client

RegisteredClient::RegisteredClient(std::string n, int NIF): Client(n,NIF)
{
	points=0;
}

RegisteredClient::~RegisteredClient() {

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

	ss << getID() << " " << getName() << ", " << getNIF() << ", Points:  " << getPoints();

	return ss.str() ;
}

//Ocasional Client

OcasionalClient::OcasionalClient(std::string n, int NIF): Client(n,NIF)
{

}

OcasionalClient::~OcasionalClient()
{

}

std::string OcasionalClient::getInformation() const
{
	std::stringstream ss;

	ss << getID() << " " << getName() << " " << getNIF();

	return ss.str() ;
}
