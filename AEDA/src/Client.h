/*
 * Client.h
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#ifndef SRC_CLIENT_H_
#define SRC_CLIENT_H_

#include <string>

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
};

class RegisteredClient: public Client
{
private:
	int points;
public:
	RegisteredClient(std::string n, int NIF);
	~RegisteredClient();
	int getPoints() const;
};

class OcasionalClient: public Client
{
public:
	OcasionalClient(std::string n, int NIF);
	~OcasionalClient();
};
#endif /* SRC_CLIENT_H_ */
