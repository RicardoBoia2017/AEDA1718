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
#include <fstream>

using namespace std;


#include "Client.h"
#include "Supplier.h"
#include "Offer.h"
#include "Date.h"

class Company {
private:
	std::vector <RegisteredClient *> rClients;
	std::vector <OccasionalClient *> oClients;
	std::vector <Supplier *> suppliers;
	std::vector <Offer *> offers;
	int bank;
public:
	Company(std::vector<RegisteredClient *> rClients, std::vector<OccasionalClient *> oClients, std::vector<Supplier *> suppliers, std::vector<Offer *> offers);
	virtual ~Company();
	void exportRegisteredClients(std::string file);
	void exportOccasionaldClients(std::string file);
	void exportSuppliers (std::string file);
	void exportOffers (std::string file);
	int RegisterClient(std::string name, int NIF);
	void AddSupplier(std::string n, int NIF, std::string address);
	void addOccasionalClient (std::string name, int NIF);
	void addOffer(unsigned int price, unsigned int dist, unsigned int cap, unsigned int points, double perc, string bT, string dest, string supName, Date d);
	void removeOccasionalClient(int id);
	std::vector <RegisteredClient *> getRegisteredClients () const;
	std::vector <OccasionalClient *> getOccasionalClients () const;
	std::vector <Supplier *> getSuppliers () const;
	std::vector <Offer *> getOffers () const;
	int getBank() const;
	void setBank (int b);
	void setOfferSuppliers();
	void printRegisteredClients() const;
	void printRegisteredClientByPoints() const;
	void printOccasionalClients() const;
	void printClientsByOffer (int idOffer) const;
	void printSuppliers() const;
	void printOffers() const;
	void printOfferbyDate (Date d1, Date d2) const;
	void printOfferBySuppliers(std::string name) const;

};

#endif /* SRC_COMPANY_H_ */
