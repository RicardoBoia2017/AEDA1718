/*
 * Offer.h
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#ifndef SRC_OFFER_H_
#define SRC_OFFER_H_

#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

#include "Supplier.h"
#include "Client.h"
#include "Date.h"

class Offer {
private:
	unsigned int id;
	unsigned int price;
	unsigned int distance;
	unsigned int capacity;
	unsigned int vacancies;
	unsigned int points;
	double percentage;
	string boatType;
	string destination;
	string supName;
	map <RegisteredClient *, int> reg_clients;
	map <OccasionalClient *, int> oc_clients;
	Supplier * sup;
	Date date;
public:
	Offer (int pri, int dist,int capacity, string bT, string dest, string sName, unsigned int points, double percentage, Date d);
	virtual ~Offer();
	void addRegisteredClient(RegisteredClient * rc, int nTick);
	void elimRegisteredClient(RegisteredClient * rc, int nTick);
	void addOccasionalClient(OccasionalClient * oc, int nTick);
	void elimOccasionalClient(OccasionalClient * rc, int nTick);
	unsigned int getId() const;
	unsigned int getPrice() const;
	unsigned int getDistance() const;
	unsigned int getCapacity() const;
	unsigned int getVacancies() const;
	unsigned int getPoints() const;
	Date getDate() const;
	double getPercentage() const;
	string getBoatType () const;
	string getDestination() const;
	string getInformation() const;
	string getSupName() const;
	map <RegisteredClient *, int> getRegClients() const;
	map <OccasionalClient *, int> getOcClients() const;
	Supplier * getSupplier() const;
	void setSupplier(Supplier *  s);
	friend ostream &operator<< (ostream &os, Offer &o1);
};

#endif
