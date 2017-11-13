/*
 * Supplier.h
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#ifndef SRC_SUPPLIER_H_
#define SRC_SUPPLIER_H_


#include <string>
#include <vector>
#include <sstream>



class Supplier {
private:
	std::string name;
	int NIF;
	std::string address;
	int id;
public:
	Supplier(std::string n, int NIF, std::string address);
	virtual ~Supplier();
	std::string getName() const;
	int getNIF() const;
	std::string getAddress() const;
	int getId() const;
	std::string getInformation() const;
	friend std::ostream &operator<< (std::ostream &os, Supplier &s1);
};

#endif /* SRC_SUPPLIER_H_ */
