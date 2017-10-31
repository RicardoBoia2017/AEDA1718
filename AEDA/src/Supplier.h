/*
 * Supplier.h
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#ifndef SRC_SUPPLIER_H_
#define SRC_SUPPLIER_H_

#include <string>
#include <vector>

#include "Offer.h"

class Supplier {
private:
	std::string name;
	int NIF;
	std::string address;
	std::vector<Offer *> offers;
public:
	Supplier();
	virtual ~Supplier();
	std::string getName() const;
	int getNIF() const;
	std::string getAddress() const;
};

#endif /* SRC_SUPPLIER_H_ */
