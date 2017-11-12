/*
 * Company.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Company.h"

Company::Company(std::vector<RegisteredClient *> rClients, std::vector<OccasionalClient *> oClients, std::vector<Supplier *> suppliers, std::vector<Offer *> offers)
{
	this->rClients = rClients;
	this->oClients = oClients;
	this->suppliers = suppliers;
	this->offers = offers;
}

Company::~Company()
{

}

int Company::RegisterClient(std::string name, int NIF)
{
	RegisteredClient * rc = new RegisteredClient(name,NIF,0);
	rClients.push_back(rc);

	return rc->getId();
}

void Company::addOccasionalClient (std::string name, int NIF)
{
	OccasionalClient *oc = new OccasionalClient(name,NIF);
	oClients.push_back(oc);
}

std::vector <RegisteredClient *> Company::getRegisteredClients () const
{
	return rClients;
}

std::vector <OccasionalClient *> Company::getOccasionalClients() const
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

void Company::printRegisteredClientByPoints() const
{
	std::vector <RegisteredClient* > v_tmp = rClients;

	int j;
	for (int gap = v_tmp.size()/2; gap > 0; gap /= 2)
	{
		for (unsigned int i = gap; i < v_tmp.size(); i++)
		{
			RegisteredClient* tmp = v_tmp[i];
			for (j = i; j >= gap && tmp->getPoints() > v_tmp[j-gap]->getPoints(); j -= gap)
				v_tmp[j] = v_tmp[j-gap];
			v_tmp[j] = tmp;
		}
	}

	for(unsigned int i = 0; i < v_tmp.size(); i++)
	{
		std::cout << v_tmp[i]->getInformation() << std::endl;
	}

}

void Company::printOccasionalClients() const
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
