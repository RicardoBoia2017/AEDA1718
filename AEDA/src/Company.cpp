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
	bank = 0;
}

Company::~Company()
{

}

void Company::exportRegisteredClients(std::string file)
{
	std::ofstream out;
	out.open(file.c_str());

	for(unsigned int i=0; i<rClients.size(); i++){
		out << *rClients.at(i) << std::endl;
	}

	out.close();
}

void Company::exportOccasionaldClients(std::string file)
{
	std::ofstream out;
	out.open(file.c_str());

	for(unsigned int i=0; i<oClients.size(); i++){
		out << *oClients.at(i) << std::endl;
	}

	out.close();
}

void Company::exportSuppliers(std::string file)
{
	std::ofstream out;
	out.open(file.c_str());

	for(unsigned int i=0; i<suppliers.size(); i++){
		out << *suppliers.at(i) << std::endl;
	}

	out.close();
}

void Company::exportOffers(std::string file)
{
	std::ofstream out;
	out.open(file.c_str());

	for(unsigned int i=0; i<offers.size(); i++){
		out << *offers.at(i) << std::endl;
	}

	out.close();
}

int Company::RegisterClient(std::string name, int NIF)
{
	RegisteredClient * rc = new RegisteredClient(name,NIF,0);
	rClients.push_back(rc);

	return rc->getId();
}

void Company::AddSupplier(std::string n, int NIF, std::string address)
{
	Supplier * sup = new Supplier(n, NIF, address);
	suppliers.push_back(sup);

}


void Company::addOffer(unsigned int price, unsigned int dist, unsigned int cap, unsigned int points, double perc, string bT, string dest, string supName, Date d)
{
	Offer * o = new Offer(price, dist, cap, bT, dest, supName, points, perc, d);

	offers.push_back(o);

	for(unsigned int i = 0; i < this->suppliers.size(); i++)
	{
		if (suppliers[i]->getName() == supName)
			o->setSupplier( suppliers [i]);
		break;
	}
}


void Company::addOccasionalClient (std::string name, int NIF)
{
	OccasionalClient *oc = new OccasionalClient(name,NIF);
	oClients.push_back(oc);
}

void Company::removeOccasionalClient(int id)
{
	std::vector <OccasionalClient *>::iterator it = oClients.begin();

	for(it; it != oClients.end(); it++)
	{
		if( (*it)->getId() == id)
			oClients.erase(it);
	}

	for(unsigned int i = id-1; i < oClients.size(); i++ )
	{
		int new_id = oClients[i]->getId() - 1;
		oClients[i]->setId(new_id);
	}
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

int Company::getBank() const
{
	return bank;
}

void Company::setBank(int b)
{
	bank += b;
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

void Company::printClientsByOffer(int idOffer) const
{
	Offer * o = offers[idOffer-1];

	if(o->getRegClients().size() != 0)
	{
		std::cout << "Registered Clients:" << std::endl << std::endl;

		std::map < RegisteredClient*, int>::const_iterator it_res = o->getRegClients().cbegin();

		for( unsigned int i = 0; i < o->getRegClients().size(); i++)
		{
			std::cout << it_res->first->getInformation() <<  ", Tickets: " << it_res->second << std::endl;
			it_res++;
		}
	}

	if ( o->getOcClients().size() != 0)
	{
		std::cout << std::endl <<  "Occasional Clients:" << std::endl << std::endl;

		std::map < OccasionalClient*, int>::const_iterator it_oc = o->getOcClients().begin();

		for (unsigned int i = 0; i < o->getOcClients().size() ; i++)
		{
			std::cout << it_oc->first->getInformation() <<  ", Tickets: " << it_oc->second << o->getOcClients().size()<< std::endl;
			it_oc ++;
		}
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

void Company::printOfferbyDate(Date d1, Date d2) const
{
	for (unsigned int i = 0; i < offers.size(); i++)
	{
		if(d1 <= offers[i]->getDate())
			if (offers[i]->getDate() <= d2)
				std::cout << offers[i]->getInformation() << std::endl;
	}
}

void Company::printOfferBySuppliers(std::string name) const
{
	for (unsigned int i = 0; i < offers.size(); i++)
	{
		if (offers[i]->getSupName() == name)
			std::cout << offers[i]->getInformation() << std::endl;
	}
}

