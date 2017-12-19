/*
 * Offer.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Offer.h"

static unsigned int offerID = 1;

/**
 * The constructor.
 * @param pri price.
 * @param dist distance.
 * @param capacity capacity.
 * @param bT boat type.
 * @param dest destination.
 * @param sName supName.
 * @param points points.
 * @param percentage which is gonna be divided by 100, converting it to a decimal number.
 * @param d date.
 */
Offer::Offer(int pri, int dist, int capacity, string bT, string dest, string sName, unsigned int points, double percentage, Date d):
		price(pri), distance(dist), boatType (bT), destination(dest), supName(sName), date(d)
{
	this->points=points;
	this->capacity = capacity;
	this->percentage = percentage/100;
	vacancies = capacity;
	id = offerID;
	offerID++;
}

/**
 * The destructor.
 */
Offer::~Offer() {

}

/**
 * Adds registered client and the number of tickets he bought. In the case he is already part of the offer, then it just adds the number of tickets.
 * @param rc registered client to be added.
 * @param nTick number of tickets bought.
 */
void Offer::addRegisteredClient(RegisteredClient * rc, int nTick)
{
	bool Found = false;
	for(map<RegisteredClient *, int>::iterator it = reg_clients.begin(); it != reg_clients.end(); it++)
	{
		if(it->first->getId() == rc->getId())
		{
			it->second += nTick;
			Found = true;
		}
	}

	if(Found == false)
			reg_clients.insert(pair <RegisteredClient* , int> (rc, nTick));

   vacancies -= nTick;

   unsigned int pointsWon = rc->getPoints() + nTick * getPoints();
   rc->setPoints(pointsWon);
}

/**
 * Eliminates registered client or just removes a few tickets from his reservation.
 * @param rc registered client.
 * @param nTick number of tickets to be removed.
 */
bool Offer::elimRegisteredClient(RegisteredClient * rc, int nTick)
{

	bool Found = false;
	for(map<RegisteredClient *, int>::iterator it = reg_clients.begin(); it != reg_clients.end(); it++)
		{
			if(it->first->getId() == rc->getId())
			{
				if (it->second == nTick)
				{
					reg_clients.erase(it);
				}
				else if (it->second < nTick)
				{
					cout << "You didn't make that much reservations." << endl;
					return Found;
				}
				else
				{
					it->second -= nTick;
				}
				vacancies += nTick;

				unsigned int pointsWon = rc->getPoints() - nTick * getPoints();
				rc->setPoints(pointsWon);
				Found = true;
				cout << "Your cancelation was successful!" << endl;
			}
		}
	if (Found == false)
	{
		cout << "You don't have any reservation for this offer. Try again" << endl;
	}

	return Found;
}

/**
 * Adds occasional client and the number of tickets he bought. In the case he is already part of the offer, then it just adds the number of tickets.
 * @param oc occasional client to be added.
 * @param nTick number of tickets bought.
 */
void Offer::addOccasionalClient(OccasionalClient* oc, int nTick)

{
	bool Found = false;
	for(map<OccasionalClient *, int>::iterator it = oc_clients.begin(); it != oc_clients.end(); it++)
	{
		if(it->first->getId() == oc->getId())
		{
			it->second += nTick;
			Found = true;
		}
	}

	if(Found == false)
			oc_clients.insert(pair <OccasionalClient* , int> (oc, nTick));

	vacancies -= nTick;

}

/**
 * Eliminates occasional client or just removes a few tickets from his reservation.
 * @param oc occasional client.
 * @param nTick number of tickets to be removed.
 */

bool Offer::elimOccasionalClient(OccasionalClient * oc, int nTick)
{

	bool Found = false;
	for(map<OccasionalClient *, int>::iterator it = oc_clients.begin(); it != oc_clients.end(); it++)
		{
			if(it->first->getId() == oc->getId())
			{
				if (it->second == nTick)
				{
					oc_clients.erase(it);
				}
				else if (it->second < nTick)
				{
						cout << "You didn't make that much reservations." << endl;
						return Found;
				}
				else
				{
					it->second -= nTick;
				}
				vacancies += nTick;
				Found = true;
				cout << "Your cancelation was successful!" << endl;
			}
		}
	if (Found == false)
		{
			cout << "You don't have any reservation for this offer. Try again" << endl;
		}

	return Found;
}

/**
 * @return price.
 */
unsigned int Offer::getPrice() const
{
	return price;
}

/**
 * @return id.
 */
unsigned int Offer::getId() const
{
	return id;
}

/**
 * @return distance.
 */
unsigned int Offer::getDistance() const
{
	return distance;
}

/**
 * @return capacity.
 */
unsigned int Offer::getCapacity() const
{
	return capacity;
}

/**
 * @return vacancies.
 */
unsigned int Offer::getVacancies() const
{
	return vacancies;
}

/**
 * @return points.
 */
unsigned int Offer::getPoints() const
{
	return points;
}

/**
 * @return date.
 */
Date Offer::getDate() const
{
	return date;
}
/**
 * @return percentage.
 */

double Offer::getPercentage() const
{
	return percentage;
}

/**
 * @return boat type.
 */
string Offer::getBoatType() const
{
	return boatType;
}

/**
 * @return destination.
 */
string Offer::getDestination() const
{
	return destination;
}

/**
 * @return string with the offer's information.
 */
string Offer::getInformation() const
{
	stringstream ss;
	Date d1 = getDate();

	ss << getId() << " " << d1.getDay() << "/" << d1.getMonth() << "/" << d1.getYear() << ", " <<  getSupName() << ", " << getDestination() << ", " << getDistance() << "km, " <<  getBoatType() << ", " << getPrice() << "€ "
			<< "//  seats available: " << getVacancies() << endl << "Points / ticket : " << getPoints() << " (only available for registered clients)" << endl;

	return ss.str();
}

/**
 * @return supName.
 */
string Offer::getSupName() const
{
	return supName;
}

/**
 * @return sup.
 */
Supplier * Offer::getSupplier() const
{
	return sup;
}

/**
 * Sets supplier equal to s.
 *  @param s new supplier.
 */
void Offer::setSupplier(Supplier * s)
{
	sup=s;
}

/**
 * @return reg_clients.
 */
map <RegisteredClient*, int> Offer::getRegClients() const
{
	return reg_clients;
}

/**
 * @return oc_clients.
 */
map <OccasionalClient *, int> Offer::getOcClients() const
{
	return oc_clients;
}

/** Writes to ofstream the offer's information in the format used in text files.

 * @param os ofstream where is stored the information.
 * @param o1 offer which information is going to be read.
 */
ostream &operator<< (ostream &os, Offer &o1)
{
	double perc = o1.getPercentage() * 100;
	Date d1 = o1.getDate();

	os << o1.getId()  << ", " << d1.getDay() << "/" << d1.getMonth() << "/" << d1.getYear() <<  ", " <<  o1.getSupName() << ", " << o1.getPrice() << ", " << o1.getDistance() << ", " << o1.getVacancies() << ", " <<
			o1.getBoatType() << ", " << o1.getDestination() << ", " << o1.getPoints() << ", " << perc << ";";

	return os;
}

bool Offer::operator< (Offer &o2)
{

}

