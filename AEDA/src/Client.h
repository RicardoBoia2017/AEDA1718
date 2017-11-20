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
	int NIF;
public:
	Client(string n, int NIF);
	virtual ~Client();
	string getName() const;
	int getNIF() const;
	virtual int getId() const = 0;
	virtual string getInformation() const = 0;
};

class RegisteredClient: public Client
{
private:
	int points;
	int reg_id;
public:
	RegisteredClient(string n, int NIF, int points);
	~RegisteredClient();
	int getId() const;
	int getPoints() const;
	void setPoints(unsigned int p);
	string getInformation() const;
	friend ostream &operator<< (ostream &os, RegisteredClient &c1);
};

class OccasionalClient: public Client
{
private:
	int oc_id;
public:
	OccasionalClient(string n, int NIF);
	~OccasionalClient();
	int getId() const;
	void setId(int id);
	string getInformation() const;
	friend ostream &operator<< (ostream &os, OccasionalClient &c1);
};
#endif /* SRC_CLIENT_H_ */
