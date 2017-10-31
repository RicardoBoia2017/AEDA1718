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
	points = 0;
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

int Client::getPoints() const
{
	return points;
}

int Client::getID() const
{
	return id;
}

