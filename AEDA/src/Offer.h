/*
 * Offer.h
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#ifndef SRC_OFFER_H_
#define SRC_OFFER_H_

#include <string>

#include "Supplier.h"

class Offer {
private:
	int id;
	int value;
	int distance;
	int capacity;
	std::string boatType;
	std::string destination;
	//Supplier sup;
public:
	Offer (int val, int dist,int capacity, std::string bT, std::string dest);
	virtual ~Offer();
	int getId() const;
	int getValue() const;
	int getDistance() const;
	int getCapacity() const;
	std::string getBoatType () const;
	std::string getDestination() const;
	//Supplier getSupplier() const;
};

#endif /* SRC_OFFER_H_ */
