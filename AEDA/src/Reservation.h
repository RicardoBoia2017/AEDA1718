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
	Offer *offer;
	Date date;
public:
	Reservation(){};
	Reservation(Offer *o1, RegisteredClient* c1, Date d1);
	Reservation(Offer *o1, OccasionalClient* c1, Date d1);
	virtual ~Reservation();
	Client* getClient () const;
	Offer* getOffer() const;
	Date getDate () const;

	bool operator< (const Reservation & r2) const;
	bool operator== (const Reservation & r2) const;
};


#endif /* AEDA_SRC_RESERVATION_H_ */
