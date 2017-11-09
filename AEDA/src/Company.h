/*
 * Company.h
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#ifndef SRC_COMPANY_H_
#define SRC_COMPANY_H_

#include <vector>
#include <iostream>

#include "Client.h"
#include "Supplier.h"
#include "Offer.h"

class Company {
private:
	std::vector <Client *> clients;
	std::vector <Supplier *> suppliers;
	std::vector <Offer *> offers;
public:
	Company(std::vector<Client *> clients, std::vector<Supplier *> suppliers, std::vector<Offer *> offers);
	virtual ~Company();
	std::vector <Client *> getClients () const;
	std::vector <Supplier *> getSuppliers () const;
	std::vector <Offer *> getOffers () const;
	void printClients() const;
	void printSuppliers() const;
};

#endif /* SRC_COMPANY_H_ */
