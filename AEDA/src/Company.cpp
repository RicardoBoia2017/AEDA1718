/*
 * Company.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Company.h"

Company::Company(vector<RegisteredClient *> rClients, vector<OccasionalClient *> oClients, vector<Supplier *> suppliers, vector<Offer *> offers)
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

void Company::exportRegisteredClients(string file)
{
	ofstream out;
	out.open(file.c_str());

	for(unsigned int i=0; i<rClients.size(); i++){
		out << *rClients.at(i) << endl;
	}

	out.close();
}

void Company::exportOccasionaldClients(string file)
{
	ofstream out;
	out.open(file.c_str());

	for(unsigned int i=0; i<oClients.size(); i++){
		out << *oClients.at(i) << endl;
	}

	out.close();
}

void Company::exportSuppliers(string file)
{
	ofstream out;
	out.open(file.c_str());

	for(unsigned int i=0; i<suppliers.size(); i++){
		out << *suppliers.at(i) << endl;
	}

	out.close();
}

void Company::exportOffers(string file)
{
	ofstream out;
	out.open(file.c_str());

	for(unsigned int i=0; i<offers.size(); i++){
		out << *offers.at(i) << endl;
	}

	out.close();
}

int Company::RegisterClient(string name, int NIF)
{
	RegisteredClient * rc = new RegisteredClient(name,NIF,0);
	rClients.push_back(rc);

	return rc->getId();
}

void Company::AddSupplier(string n, int NIF, string address)
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


void Company::addOccasionalClient (string name, int NIF)
{
	OccasionalClient *oc = new OccasionalClient(name,NIF);
	oClients.push_back(oc);
}

void Company::removeOccasionalClient(int id)
{
	vector <OccasionalClient *>::iterator it = oClients.begin();

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

vector <RegisteredClient *> Company::getRegisteredClients () const
{
	return rClients;
}

vector <OccasionalClient *> Company::getOccasionalClients() const
{
	return oClients;
}

vector <Supplier *> Company::getSuppliers () const
{
	return suppliers;
}

vector <Offer *> Company::getOffers () const
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
		cout<< rClients[i]->getInformation() << endl;
	}

}

void Company::printRegisteredClientByPoints() const
{
	vector <RegisteredClient* > v_tmp = rClients;

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
		cout<< v_tmp[i]->getInformation() << endl;
	}

}

void Company::printOccasionalClients() const
{
	for (unsigned int i = 0; i < oClients.size(); i++)
	{
		cout<< oClients[i]->getInformation() << endl;
	}
}

void Company::printClientsByOffer(int idOffer) const
{
	Offer * o = offers[idOffer-1];

	if(o->getRegClients().size() != 0)
	{
		cout<< "Registered Clients:" << endl<< endl;

		map < RegisteredClient*, int>::const_iterator it_res = o->getRegClients().cbegin();

		for( unsigned int i = 0; i < o->getRegClients().size(); i++)
		{
			cout<< it_res->first->getInformation() <<  ", Tickets: " << it_res->second << endl;
			it_res++;
		}
	}

	if ( o->getOcClients().size() != 0)
	{
		cout<< endl<<  "Occasional Clients:" << endl<< endl;

		map < OccasionalClient*, int>::const_iterator it_oc = o->getOcClients().begin();

		for (unsigned int i = 0; i < o->getOcClients().size() ; i++)
		{
			cout<< it_oc->first->getInformation() <<  ", Tickets: " << it_oc->second << o->getOcClients().size()<< endl;
			it_oc ++;
		}
	}

}

void Company::printSuppliers() const
{
	for (unsigned int i = 0; i < suppliers.size(); i++)
	{
		cout<< suppliers[i]->getInformation() << endl;
	}
}

void Company::printOffers() const
{
	for (unsigned int i = 0; i < offers.size(); i++)
	{
		cout<< offers[i]->getInformation() << endl;
	}
}

void Company::printOfferbyDate(Date d1, Date d2) const
{
	for (unsigned int i = 0; i < offers.size(); i++)
	{
		if(d1 <= offers[i]->getDate())
			if (offers[i]->getDate() <= d2)
				cout<< offers[i]->getInformation() << endl;
	}
}

void Company::printOfferBySuppliers(string name) const
{
	for (unsigned int i = 0; i < offers.size(); i++)
	{
		if (offers[i]->getSupName() == name)
			cout<< offers[i]->getInformation() << endl;
	}
}

