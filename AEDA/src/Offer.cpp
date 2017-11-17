/*
 * Offer.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Offer.h"

static unsigned int offerID = 1;

Offer::Offer(int pri, int dist, int capacity, std::string bT, std::string dest, std::string sName, unsigned int points, double percentage, Date d):
		price(pri), distance(dist), boatType (bT), destination(dest), supName(sName), date(d)
{
	this->points=points;
	this->capacity = capacity;
	this->percentage = percentage/100;
	vacancies = capacity;
	id = offerID;
	offerID++;
}

Offer::~Offer() {

}

void Offer::addRegisteredClient(RegisteredClient * rc, int nTick)
{
	bool Found = false;
	for(std::map<RegisteredClient *, int>::iterator it = reg_clients.begin(); it != reg_clients.end(); it++)
	{
		if(it->first->getId() == rc->getId())
		{
			it->second += nTick;
			Found = true;
		}
	}

	if(Found == false)
			reg_clients.insert(std::pair <RegisteredClient* , int> (rc, nTick));

   vacancies -= nTick;

   unsigned int pointsWon = rc->getPoints() + nTick * getPoints();
   rc->setPoints(pointsWon);
}

void Offer::elimRegisteredClient(RegisteredClient * rc, int nTick)
{

	bool Found = false;
	for(std::map<RegisteredClient *, int>::iterator it = reg_clients.begin(); it != reg_clients.end(); it++)
		{
			if(it->first->getId() == rc->getId())
			{
				if (it->second == nTick)
				{
					reg_clients.erase(it);
				}
				else
				{
					it->second -= nTick;
				}
				vacancies += nTick;

				unsigned int pointsWon = rc->getPoints() - nTick * getPoints();
				rc->setPoints(pointsWon);
				Found = true;
				std::cout << "Your cancelation was successful!" << std::endl;
			}
		}
	if (Found == false)
	{
		std::cout << "You don't have any reservation for this offer. Try again" << std::endl;
	}


}

void Offer::addOccasionalClient(OccasionalClient* oc, int nTick)

{
	bool Found = false;
	for(std::map<OccasionalClient *, int>::iterator it = oc_clients.begin(); it != oc_clients.end(); it++)
	{
		if(it->first->getId() == oc->getId())
		{
			it->second += nTick;
			Found = true;
		}
	}

	if(Found == false)
			oc_clients.insert(std::pair <OccasionalClient* , int> (oc, nTick));

	vacancies -= nTick;

}

void Offer::elimOccasionalClient(OccasionalClient * oc, int nTick)
{

	bool Found = false;
	for(std::map<OccasionalClient *, int>::iterator it = oc_clients.begin(); it != oc_clients.end(); it++)
		{
			if(it->first->getId() == oc->getId())
			{
				if (it->second == nTick)
				{
					oc_clients.erase(it);
				}
				else
				{
					it->second -= nTick;
				}
				vacancies += nTick;
				Found = true;
				std::cout << "Your cancelation was successful!" << std::endl;
			}
		}
	if (Found == false)
		{
			std::cout << "You don't have any reservation for this offer. Try again" << std::endl;
		}

}

unsigned int Offer::getPrice() const
{
	return price;
}

unsigned int Offer::getId() const
{
	return id;
}

unsigned int Offer::getDistance() const
{
	return distance;
}

unsigned int Offer::getCapacity() const
{
	return capacity;
}

unsigned int Offer::getVacancies() const
{
	return vacancies;
}

unsigned int Offer::getPoints() const
{
	return points;
}

Date Offer::getDate() const
{
	return date;
}


double Offer::getPercentage() const
{
	return percentage;
}

std::string Offer::getBoatType() const
{
	return boatType;
}

std::string Offer::getDestination() const
{
	return destination;
}

std::string Offer::getInformation() const
{
	std::stringstream ss;
	Date d1 = getDate();

	ss << getId() << " " << d1.getDay() << "/" << d1.getMonth() << "/" << d1.getYear() << ", " <<  getSupName() << ", " << getDestination() << ", " << getDistance() << "km, " <<  getBoatType() << ", " << getPrice() << "€ "
			<< "//  seats available: " << getVacancies() << std::endl << "Points / ticket : " << getPoints() << " (only available for registered clients)" << std::endl;

	return ss.str();
}

std::string Offer::getSupName() const
{
	return supName;
}

Supplier * Offer::getSupplier() const
{
	return sup;
}

void Offer::setSupplier(Supplier * s)
{
	sup=s;
}

std::map <RegisteredClient*, int> Offer::getRegClients() const
{
	return reg_clients;
}

std::map <OccasionalClient *, int> Offer::getOcClients() const
{
	return oc_clients;
}

std::ostream &operator<< (std::ostream &os, Offer &o1)
{
	double perc = o1.getPercentage() * 100;
	Date d1 = o1.getDate();

	os << o1.getId()  << ", " << d1.getDay() << "/" << d1.getMonth() << "/" << d1.getYear() <<  ", " <<  o1.getSupName() << ", " << o1.getPrice() << ", " << o1.getDistance() << ", " << o1.getVacancies() << ", " <<
			o1.getBoatType() << ", " << o1.getDestination() << ", " << o1.getPoints() << ", " << perc << ";";

	return os;
}

