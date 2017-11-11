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
	std::vector<Client* > c;
	std::vector <RegisteredClient *> rClients;
	std::vector <OcasionalClient *> oClients;
	std::vector <Supplier *> suppliers;
	std::vector <Offer *> offers;
public:
	Company(std::vector<RegisteredClient *> rClients, std::vector<OcasionalClient *> oClients, std::vector<Supplier *> suppliers, std::vector<Offer *> offers);
	virtual ~Company();
	std::vector <RegisteredClient *> getRegisteredClients () const;
	std::vector <OcasionalClient *> getOcasionalClients () const;
	std::vector <Supplier *> getSuppliers () const;
	std::vector <Offer *> getOffers () const;
	void setOfferSuppliers();
	void printRegisteredClients() const;
	void printOcasionalClients() const;
	void printSuppliers() const;
	void printOffers() const;
};

#endif /* SRC_COMPANY_H_ */
