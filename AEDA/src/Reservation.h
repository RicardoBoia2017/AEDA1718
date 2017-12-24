/*
 * Reservation.h
 *
 *  Created on: 21/12/2017
 *      Author: ricar
 */

#ifndef _RESERVATION_H_
#define _RESERVATION_H_

using namespace std;

#include "Offer.h"
#include "Client.h"

class Reservation {
private:
	Client *client;
//	Offer *offer;
	Date date;
	unsigned int id;
	string clientName;
	unsigned int offer;
	unsigned int nTick;
public:
	Reservation(){};
	Reservation(Offer *o1, RegisteredClient* c1, Date d1);
	Reservation(Offer *o1, OccasionalClient* c1, Date d1);
	Reservation(string cName, unsigned int OfferID, Date d1, unsigned int nT);
	virtual ~Reservation();
	void setClient (Client *c);
	void setTickets (unsigned int newValue);
	Client * getClient () const;
	string getClientName () const;
	unsigned int getOffer() const;
	Date getDate () const;
	unsigned int getId() const;
	unsigned int getTickets() const;

	friend ostream &operator<< (ostream &os, Reservation &o1);
	bool operator< (const Reservation & r2) const;
	bool operator== (const Reservation & r2) const;
};


#endif /* AEDA_SRC_RESERVATION_H_ */
