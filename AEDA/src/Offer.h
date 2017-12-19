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
#include <map>
#include <iostream>

using namespace std;

#include "Supplier.h"
#include "Client.h"
#include "Date.h"

class Offer {
private:
	/**
	 * @brief offer's id.
	 */
	unsigned int id;
	/**
	 * @brief offer's price.
	 */
	unsigned int price;
	/**
	 * @brief offer's distance.
	 */
	unsigned int distance;
	/**
	 * @brief offer's boat's capacity.
	 */
	unsigned int capacity;
	/**
	 * @brief offer's vacancies.
	 */
	unsigned int vacancies;
	/**
	 * @brief offer's points per ticket bought.
	 */
	unsigned int points;
	/**
	 * @brief percentage of each reservation that goes to 'Porto Rivers'.
	 */
	double percentage;
	/**
	 * @brief offer's boat type.
	 */
	string boatType;
	/**
	 * @brief offer's destination.
	 */
	string destination;
	/**
	 * @brief offer's supplier's name.
	 */
	string supName;
	/**
	 * @brief map of registered clients and the number of ticket bought by each.
	 */
	map <RegisteredClient *, int> reg_clients;
	/**
	 * @brief map of occasional clients and the number of ticket bought by each.
	 */
	map <OccasionalClient *, int> oc_clients;
	/**
	 * @brief offer's supplier.
	 */
	Supplier * sup;
	/**
	 * @brief offer's date.
	 */
	Date date;
public:
	Offer (int pri, int dist,int capacity, string bT, string dest, string sName, unsigned int points, double percentage, Date d);
	virtual ~Offer();
	void addRegisteredClient(RegisteredClient * rc, int nTick);
	bool elimRegisteredClient(RegisteredClient * rc, int nTick);
	void addOccasionalClient(OccasionalClient * oc, int nTick);
	bool elimOccasionalClient(OccasionalClient * rc, int nTick);
	unsigned int getId() const;
	unsigned int getPrice() const;
	unsigned int getDistance() const;
	unsigned int getCapacity() const;
	unsigned int getVacancies() const;
	unsigned int getPoints() const;
	Date getDate() const;
	double getPercentage() const;
	string getBoatType () const;
	string getDestination() const;
	string getInformation() const;
	string getSupName() const;
	map <RegisteredClient *, int> getRegClients() const;
	map <OccasionalClient *, int> getOcClients() const;
	Supplier * getSupplier() const;
	void setSupplier(Supplier *  s);
	friend ostream &operator<< (ostream &os, Offer &o1);
	bool operator< ( Offer &o2);

};

#endif
