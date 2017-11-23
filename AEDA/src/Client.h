/*
 * Client.h
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#ifndef SRC_CLIENT_H_
#define SRC_CLIENT_H_

#include <string>
#include <sstream>

using namespace std;

class Client {
private:
	/**
	 * @brief Client's name.
	 */
	string name;
	/**
	 * Client's NIF.
	 */
	unsigned int NIF;
public:
	Client(string n, unsigned int NIF);
	virtual ~Client();
	string getName() const;
	unsigned int getNIF() const;
	/**
	 * A pure virtual member.
	 *@return client's id.
	 */
	virtual unsigned int getId() const = 0;
	/**
	 * @return string with the client's information.
	 */
	virtual string getInformation() const = 0;
};

class RegisteredClient: public Client
{
private:
	/**
	 * number of points won by the client.
	 */
	unsigned int points;
	/**
	 * id in the list of registered clients.
	 */
	unsigned int reg_id;
public:
	RegisteredClient(string n, unsigned int NIF, unsigned int points);
	~RegisteredClient();
	unsigned int getId() const;
	unsigned int getPoints() const;
	void setPoints(unsigned int p);
	string getInformation() const;
	friend ostream &operator<< (ostream &os, RegisteredClient &rc1);
};

class OccasionalClient: public Client
{
private:
	unsigned int oc_id;
public:
	OccasionalClient(string n, unsigned int NIF);
	~OccasionalClient();
	unsigned int getId() const;
	void setId(unsigned int id);
	void adjustId();
	string getInformation() const;
	friend ostream &operator<< (ostream &os, OccasionalClient &oc1);
};
#endif /* SRC_CLIENT_H_ */
