/*
 * Company.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Company.h"

Company::Company(std::vector<Client *> clients, std::vector<Supplier *> suppliers, std::vector<Offer *> offers)
{
	this->clients = clients;
	this->suppliers = suppliers;
	this->offers = offers;
}

Company::~Company()
{

}

std::vector <Client *> Company::getClients () const
{
	return clients;
}

std::vector <Supplier *> Company::getSuppliers () const
{
	return suppliers;
}

std::vector <Offer *> Company::getOffers () const
{
	return offers;
}

void Company::printClients()
{
	for (unsigned int i = 0; i < clients.size(); i++)
	{
		std::cout << clients[i]->getID() << " " <<
				     clients[i]->getName() << " " <<
					 clients[i]->getNIF() << " " << std::endl;
	}

}
