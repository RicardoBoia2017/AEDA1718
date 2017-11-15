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
	std::string boatType;
	std::string destination;
	std::string supName;
	std::map <RegisteredClient *, int> reg_clients;
	std::map <OccasionalClient *, int> oc_clients;
	Supplier * sup;
	Date date;
public:
	Offer (int pri, int dist,int capacity, std::string bT, std::string dest, std::string sName, unsigned int points, double percentage, Date d);
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
	std::string getBoatType () const;
	std::string getDestination() const;
	std::string getInformation() const;
	std::string getSupName() const;
	std::map <RegisteredClient *, int> getRegClients() const;
	std::map <OccasionalClient *, int> getOcClients() const;
	Supplier * getSupplier() const;
	void setSupplier(Supplier *  s);
	friend std::ostream &operator<< (std::ostream &os, Offer &o1);
};

#endif
