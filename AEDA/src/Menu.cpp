/*
 * Menu.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Menu.h"

using namespace std;


void CompanyMenu(Company *c)
{
	int option;
	cout << "***********************" << endl;
	cout << "|     Porto Rivers    |" << endl;
	cout << "***********************" << endl << endl;


	cout << "1 Make reservation"   << endl;
	cout << "2 Cancel reservation" << endl;
	cout << "3 View files"         << endl;
	cout << "4 Exit"               << endl;
	cout << "Insert the desired option: ";
	cin >> option;

	switch (option)
	{
		case 1:
		{
			MakeReservation (c);
			break;
		}

		case 2:
		{
			CancelReservation (c);
			break;
		}

		case 3:
		{
			ViewFilesMenu (c);
			break;
		}

		case 4:
		{
			break;
		}

		default:
			throw InvalidOption(c);
	}
}

void MakeReservation (Company *c)
{
	unsigned int option;
	cout << "***********************" << endl;
	cout << "|   Make Reservation   |" << endl;
	cout << "***********************" << endl << endl;

	cout << "Are you a registered client?" << endl;
	cout << " 1 Yes" << endl;
	cout << " 2 No" << endl;
	cout << "3 Back" << endl;
	cout << "Insert the desired option: ";
	cin >> option;

	switch (option)
	{
		case 1:
		{
			int idClient, idOffer;
			int nTick;

			cout << "Insert your id: ";
			cin >> idClient;

			if ((idClient > c->getRegisteredClients().size() ))
			{
				cout << "Invalid client id" << endl;
				MakeReservation(c);
			}

			cout << c->getRegisteredClients()[idClient-1]->getInformation() << endl << endl;
			//RegisteredClient * rc = c->getRegisteredClients[idClient-1];
			c->printOffers();

			cout << endl << "Insert the id of the corresponding offer: ";
			cin >> idOffer;

			if (idOffer > c->getOffers().size())
			{
				cout << "Invalid offer id" << endl;
				MakeReservation(c);
			}
			Offer * offer = c->getOffers()[idOffer-1];


			cout << "How many tickets do you desire: ";
			cin >> nTick;

			if(nTick > offer->getVacancies())
				throw NoSeatsAvailable(c);

			unsigned int option2;

			cout << "Total: " << offer->getPrice() * nTick << "€" << endl;
			cout << "Want to confirm your reservation?: " << endl;
			cout << "1 Yes" << endl;
			cout << "2 No" << endl;
			cout << "Insert the desired option: ";

			cin >> option2;
			if(option2 == 1)
			{
				offer->addRegisteredClient(c->getRegisteredClients()[idClient-1], nTick);
				MakeReservation(c);
			}
			else if (option2 == 0)
				MakeReservation(c);

			else
				throw InvalidOption(c);
			break;
		}

		case 2:
		{


		}

		case 3:
		{
			CompanyMenu(c);
			break;
		}
		default:
			throw InvalidOption(c);
	}
	CompanyMenu(c);
}

void CancelReservation (Company *c)
{

}

void ViewFilesMenu (Company *c)
{
	int option;
	cout << "***********************" << endl;
	cout << "|      View Files      |" << endl;
	cout << "***********************" << endl << endl;

	cout << "1 Clients" << endl;
	cout << "2 Suppliers" << endl;
	cout << "3 Offers" << endl;
	cout << "4 Back" << endl;
	cout << "Insert the desired option: ";
	cin >> option;

	switch(option)
	{
		case 1:
		{
			cout << "Registered Clients:" <<  endl;
			c->printRegisteredClients();
			cout << endl;
			ViewFilesMenu (c);
			break;
		}

		case 2:
		{
			cout <<endl;
			c->printSuppliers();
			cout << endl;
			ViewFilesMenu (c);
			break;
		}

		case 3:
		{
			cout <<endl;
			c->printOffers();
			cout << endl;
			ViewFilesMenu (c);
			break;
		}

		case 4:
		{
			CompanyMenu(c);
			break;
		}
		default:
			throw InvalidOption(c);

	}

}


