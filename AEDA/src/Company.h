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
	/**
	 * @brief Vector with all registered clients.
	 */
	vector <RegisteredClient *> rClients;
	/**
	 * @brief Vector with all occasional clients.
	 */
	vector <OccasionalClient *> oClients;
	/**
	 * @brief Vector with all suppliers.
	 */
	vector <Supplier *> suppliers;
	/**
	 * @brief Vector with all offers.
	 */
	vector <Offer *> offers;
	/**
	 * @brief Money gained by 'Porto Rivers' with the reservations.
	 */
	unsigned int bank;
public:
	Company(vector<RegisteredClient *> rClients, vector<OccasionalClient *> oClients, vector<Supplier *> suppliers, vector<Offer *> offers);
	virtual ~Company();
	void exportRegisteredClients(string file);
	void exportOccasionaldClients(string file);
	void exportSuppliers (string file);
	void exportOffers (string file);
	unsigned int RegisterClient(string name, int NIF);
	void AddSupplier(string n, int NIF, string address);
	void addOccasionalClient (string name, int NIF);
	void addOffer(unsigned int price, unsigned int dist, unsigned int cap, unsigned int points, double perc, string bT, string dest, string supName, Date d);
	void removeOccasionalClient(int id);
	vector <RegisteredClient *> getRegisteredClients () const;
	vector <OccasionalClient *> getOccasionalClients () const;
	vector <Supplier *> getSuppliers () const;
	vector <Offer *> getOffers () const;
	unsigned int getBank() const;
	void setBank (int b);
	void setOfferSuppliers();
	void printRegisteredClients() const;
	void printRegisteredClientByPoints() const;
	void printOccasionalClients() const;
	void printClientsByOffer (int idOffer) const;
	void printSuppliers() const;
	void printOffers() const;
	void printOfferbyDate (Date d1, Date d2) const;
	void printOfferBySuppliers(string name) const;

};

#endif /* SRC_COMPANY_H_ */
