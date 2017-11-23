/*
 * Company.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Company.h"

/**
 * The constructor.
 * @param rClients rClients.
 * @param oClients oClients.
 * @param suppliers suppliers.
 * @param offers offers.
 */
Company::Company(vector<RegisteredClient *> rClients, vector<OccasionalClient *> oClients, vector<Supplier *> suppliers, vector<Offer *> offers)
{
	this->rClients = rClients;
	this->oClients = oClients;
	this->suppliers = suppliers;
	this->offers = offers;
	bank = 0;
}

/**
 * The destructor.
 */
Company::~Company()
{

}

/**
 * Exports registered clients to text file.
 * @param file that stores registered clients' information.
 */
void Company::exportRegisteredClients(string file)
{
	ofstream out;
	out.open(file.c_str());

	for(unsigned int i=0; i<rClients.size(); i++){
		out << *rClients.at(i) << endl;
	}

	out.close();
}

/**
 * Export	s occasional clients to text file.
 * @param file that stores occasional clients' information.
 */
void Company::exportOccasionaldClients(string file)
{
	ofstream out;
	out.open(file.c_str());

	for(unsigned int i=0; i<oClients.size(); i++){
		out << *oClients.at(i) << endl;
	}

	out.close();
}

/**
 * Exports suppliers to text file.
 * @param file that stores suppliers' information.
 */
void Company::exportSuppliers(string file)
{
	ofstream out;
	out.open(file.c_str());

	for(unsigned int i=0; i<suppliers.size(); i++){
		out << *suppliers.at(i) << endl;
	}

	out.close();
}

/**
 * Export	s offers' to text file.
 * @param file that stores offers' information.
 */
void Company::exportOffers(string file)
{
	ofstream out;
	out.open(file.c_str());

	for(unsigned int i=0; i<offers.size(); i++){
		out << *offers.at(i) << endl;
	}

	out.close();
}

/**
 * Adds client to registered client's vector.
 * @param name new client's name.
 * @param NIF new client's NIF.
 */
unsigned int Company::RegisterClient(string name, int NIF)
{
	RegisteredClient * rc = new RegisteredClient(name,NIF,0);
	rClients.push_back(rc);

	return rc->getId();
}

/**
 * Adds supplier to supplier's vector.
 * @param n new supplier's name.
 * @param NIF new supplier's NIF.
 * @param address new supplier's address.
 */
void Company::AddSupplier(string n, int NIF, string address)
{
	Supplier * sup = new Supplier(n, NIF, address);
	suppliers.push_back(sup);

}

/**
 * Adds offer to offer's vector.
 * @param price new offer's price.
 * @param dist new offer's distance.
 * @param cap new offer's capacity.
 * @param points new offer's points.
 * @param perc new offer's percentage.
 * @param bT new offer's boat type.
 * @param dest new offer's destination.
 * @param supName new offer's supplier's name.
 * @param d new offer's date.
 */
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

/**
 * Adds occasional client to occasional clients' vector.
 * @param name new occasional client's name.
 * @param NIF new occasional client's NIF.
 */
void Company::addOccasionalClient (string name, int NIF)
{
	OccasionalClient *oc = new OccasionalClient(name,NIF);
	oClients.push_back(oc);
}

/**
 * Removes occasional client from the respective vector.
 * @param id id of the occasional client to be removed.
 */
void Company::removeOccasionalClient(int id)
{
	vector <OccasionalClient *>::iterator it = oClients.begin();

	for(unsigned int i = 0; i < oClients.size();i++, it++)
	{
		if( (*it)->getId() == id)
		{
			(*it)->adjustId();
			oClients.erase(it);
		}
	}

	for(unsigned int i = id-1; i < oClients.size(); i++ )
	{
		int new_id = oClients[i]->getId() - 1;
		oClients[i]->setId(new_id);
	}


}

/**
 * @return registered clients' vector.
 */
vector <RegisteredClient *> Company::getRegisteredClients () const
{
	return rClients;
}

/**
 * @return occasional clients' vector.
 */
vector <OccasionalClient *> Company::getOccasionalClients() const
{
	return oClients;
}

/**
 * @return suppliers' vector.
 */
vector <Supplier *> Company::getSuppliers () const
{
	return suppliers;
}

/**
 * @return offers's vector.
 */
vector <Offer *> Company::getOffers () const
{
	return offers;
}

/**
 * @return bank.
 */
double Company::getBank() const
{
	return bank;
}

/**
 * Add b to bank.
 * @param b value to be added.
 */
void Company::setBank(double b)
{
	bank += b;
}

/**
 * Sets offer's corresponding supplier according to offer's supName.
 */
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

/**
 * Prints registered clients' information.
 */
void Company::printRegisteredClients() const
{
	for (unsigned int i = 0; i < rClients.size(); i++)
	{
		cout<< rClients[i]->getInformation() << endl;
	}

}

/**
 * Prints registered clients sorted by their points.
 */
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

/**
 * Prints occasional clients' information.
 */
void Company::printOccasionalClients() const
{
	for (unsigned int i = 0; i < oClients.size(); i++)
	{
		cout<< oClients[i]->getInformation() << endl;
	}
}

/**
 * Prints clients that made a reservation in a certain offer.
 * @param idOffer offer's id.
 */
void Company::printClientsByOffer(int idOffer) const
{
	Offer * o = offers[idOffer-1];

	if(o->getRegClients().size() != 0)
	{
		cout<< "Registered Clients:" << endl << endl;

		map < RegisteredClient*, int>::const_iterator it_res = o->getRegClients().cbegin();

		for( unsigned int i = 0; i < o->getRegClients().size(); i++, it_res++)
		{
			cout<< it_res->first->getInformation() <<  ", Tickets: " << it_res->second << endl;
		}
	}

	if ( o->getOcClients().size() != 0)
	{
		cout<< endl<<  "Occasional Clients:" << endl << endl;

		map < OccasionalClient*, int>::const_iterator it_oc = o->getOcClients().cbegin();

		for (unsigned int i = 0; i < o->getOcClients().size() ; i++, it_oc ++)
		{
			cout<< it_oc->first->getInformation() <<  ", Tickets: " << it_oc->second << endl;
		}
	}

}

/**
 * Prints suppliers' information.
 */
void Company::printSuppliers() const
{
	for (unsigned int i = 0; i < suppliers.size(); i++)
	{
		cout<< suppliers[i]->getInformation() << endl;
	}
}

/**
 * Prints offers' information
 */
void Company::printOffers() const
{
	for (unsigned int i = 0; i < offers.size(); i++)
	{
		cout<< offers[i]->getInformation() << endl;
	}
}

/**
 * Prints offers which date is inserted in the range provided.
 * @param d1 inital date.
 * @param d2 final date.
 */
void Company::printOfferbyDate(Date d1, Date d2) const
{
	unsigned int counter = 0;

	for (unsigned int i = 0; i < offers.size(); i++)
	{
		if(d1 <= offers[i]->getDate())
			if (offers[i]->getDate() <= d2)
				{
					cout<< offers[i]->getInformation() << endl;
					counter++;
				}
	}

	cout << "We found " << counter << " offers" << endl;
}

/**
 * Prints a certain supplier's offers.
 * @param name supplier's name.
 */
void Company::printOfferBySuppliers(string name) const
{
	for (unsigned int i = 0; i < offers.size(); i++)
	{
		if (offers[i]->getSupName() == name)
			cout<< offers[i]->getInformation() << endl;
	}
}

