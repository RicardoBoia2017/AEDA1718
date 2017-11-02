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
#include "Client.h"
#include "Supplier.h"
#include "Offer.h"

using namespace std;

#define clientsFile "clients.txt"
#define suppliersFile "suppliers.txt"
#define offersFile "offers.txt"

int main()
{
	std::vector <Client *> clients;
	std::vector <Supplier *> suppliers;
	std::vector <Offer *> offers;

	Company c(clients,suppliers,offers);

	CompanyMenu (&c);

	return 0;
}
