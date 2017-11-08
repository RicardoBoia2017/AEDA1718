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
#include "FileReader.h"

using namespace std;

#define clientsFile "C:\\Users\\ricar\\git\\AEDA17-18\\AEDA\\Debug\\clients.txt"
#define suppliersFile "suppliers.txt"
#define offersFile "offers.txt"

int main()
{
	std::vector <Client *> clients = FileReader::readClients(clientsFile);
	std::vector <Supplier *> suppliers;
	std::vector <Offer *> offers;

	RegisteredClient* c1 = new RegisteredClient("joao",0);
	clients.push_back(c1);

	Company c(clients,suppliers,offers);

	//c.printClients();

	for (unsigned int i = 0; i < clients.size(); i++)
		{
			std::cout << clients[i]->getID() << " " <<
					     clients[i]->getName() << " " <<
						 clients[i]->getNIF() << " " << std::endl;
		}

	//CompanyMenu (&c);

	return 0;
}
