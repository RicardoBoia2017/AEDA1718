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

using namespace std;

class Supplier {
private:
	string name;
	int NIF;
	string address;
	int id;
public:
	Supplier(string n, int NIF, string address);
	virtual ~Supplier();
	string getName() const;
	int getNIF() const;
	string getAddress() const;
	int getId() const;
	string getInformation() const;
	friend ostream &operator<< (ostream &os, Supplier &s1);
};

#endif /* SRC_SUPPLIER_H_ */
