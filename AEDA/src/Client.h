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

class Client {
private:
	std::string name;
	int NIF;
public:
	Client(std::string n, int NIF);
	virtual ~Client();
	std::string getName() const;
	int getNIF() const;
	virtual int getId() const = 0;
	virtual std::string getInformation() const = 0;
};

class RegisteredClient: public Client
{
private:
	int points;
	int reg_id;
public:
	RegisteredClient(std::string n, int NIF, int points);
	~RegisteredClient();
	int getId() const;
	int getPoints() const;
	void setPoints(unsigned int p);
	std::string getInformation() const;
	friend std::ostream &operator<< (std::ostream &os, RegisteredClient &c1);
};

class OccasionalClient: public Client
{
private:
	int oc_id;
public:
	OccasionalClient(std::string n, int NIF);
	~OccasionalClient();
	int getId() const;
	void setId(int id);
	std::string getInformation() const;
	friend std::ostream &operator<< (std::ostream &os, OccasionalClient &c1);
};
#endif /* SRC_CLIENT_H_ */
