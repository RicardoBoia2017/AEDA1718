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
	int id;
	int price;
	int distance;
	int capacity;
	int vacancies;
	std::string boatType;
	std::string destination;
	std::string supplier;
	Client * c;
	Supplier * sup;
public:
	Offer (int pri, int dist,int capacity, std::string bT, std::string dest, std::string sName);
	virtual ~Offer();
	int getId() const;
	int getPrice() const;
	int getDistance() const;
	int getCapacity() const;
	int getVacancies() const;
	std::string getBoatType () const;
	std::string getDestination() const;
	std::string getInformation() const;
	Client * getClient() const;
	Supplier * getSupplier() const;
};

#endif /* SRC_OFFER_H_ */
