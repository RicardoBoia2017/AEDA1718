/*
 * Company.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Company.h"

Company::Company(std::vector<Client *> clients, std::vector<Supplier *> suppliers, std::vector<Offer *> offers)
{

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
