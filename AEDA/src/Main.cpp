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

#define clientsFile "CLIENTS.txt"
#define suppliersFile "suppliers.txt"
#define offersFile "offers.txt"

int main()
{
	std::vector <Client *> clients = FileReader::readClients(clientsFile);
	std::vector <Supplier *> suppliers;
	std::vector <Offer *> offers;

	Client* c1 = new Client("joao",0);
	clients.push_back(c1);

	Company c(clients,suppliers,offers);

	//c.printClients();

	for (unsigned int i = 0; i < clients.size(); i++)
		{
			std::cout << clients[i]->getID() << " " <<
					     clients[i]->getName() << " " <<
						 clients[i]->getNIF() << " " <<
						 clients[i]->getPoints( )<< std::endl;
		}

	//CompanyMenu (&c);

	return 0;
}
