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
	cout << "4 Check bank"		   << endl;
	cout << "5 Exit"               << endl;
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
			Check_Bank(c);
		}

		case 5:
		{
			return;
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

	cout << "What type of client are you?" << endl;
	cout << " 1 Registered Client" << endl;
	cout << " 2 Occasional Client" << endl;
	cout << " 3 First time user" << endl;
	cout << " 4 Back" << endl;
	cout << "Insert the desired option: ";
	cin >> option;

	switch (option)
	{
		case 1:
		{
			MakeReservation_Registered(c);
			break;
		}

		case 2:
		{
			unsigned int option2;
			cout << endl << "Would you like to register? " << endl;
			cout << " 1 Yes" << endl;
			cout << " 2 No" << endl;
			cout << "Insert the desired option: ";
			cin >> option2;

			if( option2 == 2)
				MakeReservation_Occasional(c);
			else if (option2 == 1)
			{
				int idOc;
				cout << endl;
				c->printOccasionalClients();
				cout << endl << "Enter your id: ";
				cin >> idOc;
				if ( idOc > c->getRegisteredClients().size() || idOc <= 0)
				{
					cout << "Invalid client id" << endl;
					MakeReservation(c);
				}

				string name = c->getOccasionalClients()[idOc-1]->getName();
				int NIF = c->getOccasionalClients()[idOc-1]->getNIF();

				int idReg = c->RegisterClient(name, NIF);
				cout << "Your new id is: " << idReg << endl << endl;
				c->removeOccasionalClient(idOc);

				MakeReservation_Registered(c);
			}
			else
				throw InvalidOption(c);

		}

		case 3:
		{
			unsigned int option2;
			cout << endl << "Would you like to register? " << endl;
			cout << " 1 Yes" << endl;
			cout << " 2 No" << endl;
			cout << "Insert the desired option: ";
			cin >> option2;

			if(option2 < 0 || option > 2)
			{
				cout << "Invalid option" << endl;
				MakeReservation(c);
			}
			string name;
			int NIF;
			cout << "Please, enter your name: ";
			cin >> name;
			cout << "Please, enter your NIF: ";
			cin >> NIF;

			if( option2 == 2)
			{
				c->addOccasionalClient(name,NIF);
				MakeReservation_Occasional(c);
			}
			else if (option2 == 1)
			{
				int id = c->RegisterClient(name, NIF);
				cout << "Your new id is: " << id << endl << endl;
				MakeReservation_Registered(c);
			}
			else
				throw InvalidOption(c);
		}

		case 4:
		{
			CompanyMenu(c);
			break;
		}
		default:
			throw InvalidOption(c);
	}
	CompanyMenu(c);
}

void MakeReservation_Registered (Company *c)
{
	int idClient, idOffer, nTick;

	cout << "Insert your id: ";
	cin >> idClient;

	if (idClient > c->getRegisteredClients().size() || idClient <= 0)
	{
		cout << "Invalid client id" << endl <<endl;
		MakeReservation(c);
	}

	cout << c->getRegisteredClients()[idClient-1]->getInformation() << endl << endl;

	c->printOffers();

	cout << endl << "Insert the id of the corresponding offer: ";
	cin >> idOffer;

	if (idOffer > c->getOffers().size() || idOffer < 0)
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

	cout << "Total: " << offer->getPrice() * nTick << "€,  Points Won: " << offer->getPoints()*nTick <<  endl;
	cout << "Want to confirm your reservation?: " << endl << endl;
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
}

void MakeReservation_Occasional (Company *c)
{
	int idClient, idOffer, nTick;
	c->printOccasionalClients();

	cout << endl << endl << "Insert your id: ";
	cin >> idClient;

	if ((idClient > c->getOccasionalClients().size() ))
	{
		cout << "Invalid client id" << endl;
		MakeReservation(c);
	}

	cout << c->getOccasionalClients()[idClient-1]->getInformation() << endl << endl;

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
			offer->addOccasionalClient(c->getOccasionalClients()[idClient-1], nTick);
			MakeReservation(c);
		}
		else if (option2 == 0)
			MakeReservation(c);

		else
			throw InvalidOption(c);
}

void CancelReservation (Company *c)
{

}

void ViewFilesMenu (Company *c)
{
	int option;
	cout << "************************" << endl;
	cout << "|      View Files      |" << endl;
	cout << "************************" << endl << endl;

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
			int option2;
			 cout << "************************" << endl;
			 cout << "|        Clients       |" << endl;
			 cout << "************************" << endl << endl;

			cout << "1 View all clients" << endl;
			cout << "2 View clients by points" << endl;
			cout << "3 Back" << endl;
			cout << "Insert the desired option: " << endl;
			cin >> option2;

			switch (option2)
			{
				case 1:
				{

					cout << endl << "Registered Clients:" <<  endl << endl;
					c->printRegisteredClients();

					cout << endl << "Occasional Clients:" << endl << endl;
					c->printOccasionalClients();

					cout << endl ;
					ViewFilesMenu (c);
					break;
				}

				case 2:
				{
					cout << endl;
					c->printRegisteredClientByPoints();
					cout << endl;
					ViewFilesMenu (c);
					break;
				}
				case 3:
					ViewFilesMenu(c);
				default:
					throw InvalidOption(c);
			}

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
			int option2;
			cout << "************************" << endl;
			cout << "|        Offers        |" << endl;
			cout << "************************" << endl << endl;

			cout << "1 View all offers" << endl;
			cout << "2 View offers by suppliers" << endl;
			cout << "3 Back" << endl;
			cout << "Insert the desired option: " << endl;
			cin >> option2;

			switch (option2)
			{
				case 1:
				{
					int idOffer;
					c->printOffers();
//					cout << endl << "Enter the id of the offer to see who bought the tickets (enter 0 to exit): ";
//					cin >> idOffer;
//
//					if( idOffer == 0)
//						break;
//					else if (idOffer < 0 || idOffer > c->getOffers().size() )
//						throw InvalidOption(c);
//					else
//						c->printClientsByOffer(idOffer);
					ViewFilesMenu (c);
					break;
				}

				case 2:
				{
					int idSupplier;
					c->printSuppliers();
					cout << "Enter the id of the desired supplier: ";
					cin >> idSupplier;

					c->printOfferBySuppliers( c->getSuppliers()[idSupplier-1]->getName());
					ViewFilesMenu(c);
					break;
				}
				case 3:
					ViewFilesMenu(c);
			}

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


