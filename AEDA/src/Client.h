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
	int points;
	int id;
public:
	Client(std::string n, int NIF);
	virtual ~Client();
	std::string getName() const;
	int getNIF() const;
	int getPoints() const;
	int getID() const;
};

#endif /* SRC_CLIENT_H_ */
