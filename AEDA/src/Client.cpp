/*
 * Client.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Client.h"

/**
 * The constructor.
 * @param n client's name.
 * @param NIF client's NIF.
 */
Client::Client(string n, unsigned int NIF): name(n)
{
	this->NIF = NIF;
}

/**
 * The destructor.
 *
 */
Client::~Client() {

}

/**
 * @return name.
 */
string Client::getName() const
{
	return name;
}


/**
 *  @return NIF.
 */
unsigned int Client::getNIF() const
{
	return NIF;
}



//Registered Client


static unsigned int reg_clientID = 1;

/**
 * The constructor.
 * @param n name.
 * @param NIF NIF.
 * @param points points won by the client.
 */
RegisteredClient::RegisteredClient(string n, unsigned int NIF, unsigned int points): Client(n,NIF)
{
	this->points=points;
	reg_id = reg_clientID;
	reg_clientID ++;
}

/**
 * The destructor.
 */

RegisteredClient::~RegisteredClient() {

}

/**
 * @return reg_id
 */

unsigned int RegisteredClient::getId() const
{
	return reg_id;
}

/**
 * @return points
 */
unsigned int RegisteredClient::getPoints() const
{
	return points;
}

/*
 * Sets points equal to p.
 * @param new value of points.
 */
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

/** Writes to ofstream the client's information in the format used in text files.
 * @param os ofstream where is stored the information.
 * @param rc1 registered client whose information is gonna be read.
 */
ostream &operator<< (ostream &os, RegisteredClient &rc1)
{
	os << rc1.getId() << ", " << rc1.getName() << ", " << rc1.getNIF() << ", " << rc1.getPoints() << ";" ;
	return os;
}



//Occasional Client

static unsigned int oc_clientID = 1;

/**
 * The constructor.
 * @param n name.
 * @param NIF NIF.
 */
OccasionalClient::OccasionalClient(string n, unsigned int NIF): Client(n,NIF)
{
	oc_id = oc_clientID;
	oc_clientID++;
}
/**
 * The destructor
 */
OccasionalClient::~OccasionalClient()
{

}

unsigned int OccasionalClient::getId() const
{
	return oc_id;
}

/**
 * Sets oc_id equal to id
 * @param id new value for oc_id
 */
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

/** Writes to ofstream the client's information in the format used in text files.
 * @param os ofstream where is stored the information.
 * @param oc1 occasional client whose information is going to be read.
 */
ostream &operator<< (ostream &os, OccasionalClient &oc1)
{
	os << oc1.getId() << ", " << oc1.getName() << ", " << oc1.getNIF() << ";" ;
	return os;
}
