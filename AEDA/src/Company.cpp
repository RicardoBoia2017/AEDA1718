/*
 * Company.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Company.h"

Company::Company(std::vector<RegisteredClient *> rClients, std::vector<OcasionalClient *> oClients, std::vector<Supplier *> suppliers, std::vector<Offer *> offers)
{
	this->rClients = rClients;
	this->oClients = oClients;
	this->suppliers = suppliers;
	this->offers = offers;
}

Company::~Company()
{

}

std::vector <RegisteredClient *> Company::getRegisteredClients () const
{
	return rClients;
}

std::vector <OcasionalClient *> Company::getOcasionalClients() const
{
	return oClients;
}

std::vector <Supplier *> Company::getSuppliers () const
{
	return suppliers;
}

std::vector <Offer *> Company::getOffers () const
{
	return offers;
}

void Company::setOfferSuppliers()
{
	for( unsigned int i = 0; i < offers.size(); i++)
	{
		for (unsigned int j = 0; j < suppliers.size(); j++)
		{
			if(offers[i]->getSupName() == suppliers[j]->getName() )
			{
				offers[i]->setSupplier(suppliers[j]);
				break;
			}
		}
	}

}

void Company::printRegisteredClients() const
{
	for (unsigned int i = 0; i < rClients.size(); i++)
	{
		std::cout << rClients[i]->getInformation() << std::endl;
	}

}

void Company::printOcasionalClients() const
{
	for (unsigned int i = 0; i < oClients.size(); i++)
	{
		std::cout << oClients[i]->getInformation() << std::endl;
	}
}

void Company::printSuppliers() const
{
	for (unsigned int i = 0; i < suppliers.size(); i++)
	{
		std::cout << suppliers[i]->getInformation() << std::endl;
	}
}

void Company::printOffers() const
{
	for (unsigned int i = 0; i < offers.size(); i++)
	{
		std::cout << offers[i]->getInformation() << std::endl;
	}
}
