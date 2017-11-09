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

#define clientsFile "clients.txt"
#define suppliersFile "suppliers.txt"
#define offersFile "offers.txt"

int main()
{
	std::vector <Client *> clients = FileReader::readClients(clientsFile);
	std::vector <Supplier *> suppliers = FileReader::readSuppliers(suppliersFile);
	std::vector <Offer *> offers = FileReader::readOffers(offersFile);

	Company c(clients,suppliers,offers);

	CompanyMenu (&c);

	return 0;
}
