/*
 * Main.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include <iostream>
#include <vector>

#include "Company.h"
#include "Menu.h"
#include "FileReader.h"

using namespace std;

#define rClientsFile "RegisteredClients.txt"
#define oClientsFile "OccasionalClients.txt"
#define suppliersFile "suppliers.txt"
#define offersFile "offers.txt"

int main()
{
	std::vector <RegisteredClient *> rClients = FileReader::readRegisteredClients(rClientsFile);
	std::vector <OccasionalClient *> oClients = FileReader::readOccasionalClients(oClientsFile);
	std::vector <Supplier *> suppliers = FileReader::readSuppliers(suppliersFile);
	std::vector <Offer *> offers = FileReader::readOffers(offersFile);

	Company c(rClients,oClients, suppliers, offers);

	CompanyMenu (&c);

//	c.exportRegisteredClients (rClientsFile);
//	c.exportOccasionaldClients (oClientsFile);
//	c.exportSuppliers (suppliersFile);
//	c.exportOffers (offersFile);

	return 0;
}
