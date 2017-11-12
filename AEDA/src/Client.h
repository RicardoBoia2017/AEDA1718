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
	//virtual Client & operator = (const Client & c) = 0;
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
	//RegisteredClient & operator = (const RegisteredClient & rc) ;
};

class OccasionalClient: public Client
{
private:
	int oc_id;
public:
	OccasionalClient(std::string n, int NIF);
	~OccasionalClient();
	int getId() const;
	std::string getInformation() const;
	//occasionalClient & operator = (const occasionalClient & oc);
};
#endif /* SRC_CLIENT_H_ */
