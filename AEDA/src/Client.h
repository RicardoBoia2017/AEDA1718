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
	string name;
	unsigned int NIF;
public:
	Client(string n, unsigned int NIF);
	virtual ~Client();
	string getName() const;
	unsigned int getNIF() const;
	virtual unsigned int getId() const = 0;
	virtual string getInformation() const = 0;
};

class RegisteredClient: public Client
{
private:
	unsigned int points;
	unsigned int reg_id;
public:
	RegisteredClient(string n, unsigned int NIF, unsigned int points);
	~RegisteredClient();
	unsigned int getId() const;
	unsigned int getPoints() const;
	void setPoints(unsigned int p);
	string getInformation() const;
	friend ostream &operator<< (ostream &os, RegisteredClient &c1);
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
	string getInformation() const;
	friend ostream &operator<< (ostream &os, OccasionalClient &c1);
};
#endif /* SRC_CLIENT_H_ */
