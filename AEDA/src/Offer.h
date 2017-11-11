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
#include "Supplier.h"
#include "Client.h"

class Offer {
private:
	unsigned int id;
	unsigned int price;
	unsigned int distance;
	unsigned int capacity;
	unsigned int vacancies;
	unsigned int points;
	std::string boatType;
	std::string destination;
	std::string supName;
	std::vector<Client *> clients;
	std::vector<int> nTickets;
	Supplier * sup;
public:
	Offer (int pri, int dist,int capacity, std::string bT, std::string dest, std::string sName, unsigned int points);
	virtual ~Offer();
	void addRegisteredClient(RegisteredClient * rc, int nTick);
	void addOcasionalClient(OcasionalClient * oc, int nTick);
	unsigned int getId() const;
	unsigned int getPrice() const;
	unsigned int getDistance() const;
	unsigned int getCapacity() const;
	unsigned int getVacancies() const;
	unsigned int getPoints() const;
	std::string getBoatType () const;
	std::string getDestination() const;
	std::string getInformation() const;
	std::string getSupName() const;
	std::vector<Client *> getClients() const;
	Supplier * getSupplier() const;
	void setSupplier(Supplier *  s);
};

#endif /* SRC_OFFER_H_ */
