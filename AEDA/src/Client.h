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
	int id;
public:
	Client(std::string n, int NIF);
	virtual ~Client();
	std::string getName() const;
	int getNIF() const;
	int getID() const;
	virtual std::string getInformation() const = 0;
	//virtual Client & operator = (const Client & c) = 0;
};

class RegisteredClient: public Client
{
private:
	int points;
public:
	RegisteredClient(std::string n, int NIF, int points);
	~RegisteredClient();
	int getPoints() const;
	void setPoints(unsigned int p);
	std::string getInformation() const;
	//RegisteredClient & operator = (const RegisteredClient & rc) ;
};

class OcasionalClient: public Client
{
public:
	OcasionalClient(std::string n, int NIF);
	~OcasionalClient();
	std::string getInformation() const;
	//OcasionalClient & operator = (const OcasionalClient & oc);
};
#endif /* SRC_CLIENT_H_ */
