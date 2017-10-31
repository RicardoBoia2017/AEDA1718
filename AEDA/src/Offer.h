/*
 * Offer.h
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#ifndef SRC_OFFER_H_
#define SRC_OFFER_H_

#include <string>

class Offer {
private:
	int value;
	std::string boatType;
	std::string destination;
public:
	Offer();
	virtual ~Offer();
	int getValue() const;
	std::string getBoatType () const;
	std::string getDestination() const;
};

#endif /* SRC_OFFER_H_ */
