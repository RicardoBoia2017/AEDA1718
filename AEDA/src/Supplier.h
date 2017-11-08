/*
 * Supplier.h
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#ifndef SRC_SUPPLIER_H_
#define SRC_SUPPLIER_H_

#include "Offer.h"
#include <string>
#include <vector>



class Supplier {
private:
	std::string name;
	int NIF;
	std::string address;
	int id;
	//std::vector<Offer*> offers;
public:
	Supplier(std::string n, int NIF, std::string address);
	virtual ~Supplier();
	std::string getName() const;
	int getNIF() const;
	std::string getAddress() const;
	int getId() const;
	//std::vector <Offer*> getOffers() const;
};

#endif /* SRC_SUPPLIER_H_ */
