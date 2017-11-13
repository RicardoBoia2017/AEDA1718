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
	unsigned int optionCM = 0;

	cout << "***********************" << endl;
	cout << "|     Porto Rivers    |" << endl;
	cout << "***********************" << endl << endl;


	cout << "1 Make reservation"   << endl;
	cout << "2 Cancel reservation" << endl;
	cout << "3 View files"         << endl;
	cout << "4 Check bank"		   << endl;
	cout << "5 Exit"               << endl;
	cout << "Insert the desired option: ";

	cin >> optionCM;
	cin.clear();
	cin.ignore(10000, '\n');

	switch (optionCM)
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
			cout << "Total: " << c->getBank() << "€" << endl;
			CompanyMenu(c);
			break;
		}

		case 5:
		{
			break;
		}

		default:
			throw InvalidOption(c);
	}
}

void MakeReservation (Company *c)
{
	unsigned int optionMR = 0;
	cout << "***********************" << endl;
	cout << "|   Make Reservation   |" << endl;
	cout << "***********************" << endl << endl;

	cout << "What type of client are you?" << endl;
	cout << " 1 Registered Client" << endl;
	cout << " 2 Occasional Client" << endl;
	cout << " 3 First time user" << endl;
	cout << " 4 Back" << endl;
	cout << "Insert the desired option: ";

	cin >> optionMR;
	cin.clear();
	cin.ignore(10000, '\n');

	switch (optionMR)
	{
		case 1:
		{
			MakeReservation_Registered(c);
			break;
		}

		case 2:
		{
			unsigned int optionMR2 = 0;
			cout << endl << "Would you like to register? " << endl;
			cout << " 1 Yes" << endl;
			cout << " 2 No" << endl;
			cout << "Insert the desired option: ";
			cin >> optionMR2;
			cin.clear();
			cin.ignore(10000, '\n');

			if( optionMR2 == 2)
				MakeReservation_Occasional(c);
			else if (optionMR2 == 1)
			{
				int idOc;
				cout << endl;
				c->printOccasionalClients();
				cout << endl << "Enter your id: ";
				cin >> idOc;
				cin.clear();
				cin.ignore(10000, '\n');

				if (idOc < 0 || idOc > c->getOccasionalClients().size())
				{
					cout << "Invalid id" << endl;
					MakeReservation(c);
				}
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
			unsigned int optionMR3 = 0;
			cout << endl << "Would you like to register? " << endl;
			cout << " 1 Yes" << endl;
			cout << " 2 No" << endl;
			cout << "Insert the desired option: ";
			cin >> optionMR3;
			cin.clear();
			cin.ignore(10000, '\n');

			if(optionMR3 < 0 || optionMR3 > 2)
			{
				cout << "Invalid option" << endl;
				MakeReservation(c);
			}
			string name;
			int NIF;
			cout << "Please, enter your name: ";
			cin >> name;
			cin.clear();
			cin.ignore(10000, '\n');

			cout << "Please, enter your NIF: ";
			cin >> NIF;
			cin.clear();
			cin.ignore(10000, '\n');

			if( optionMR3 == 2)
			{
				c->addOccasionalClient(name,NIF);
				MakeReservation_Occasional(c);
			}
			else if (optionMR3 == 1)
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
	cin.clear();
	cin.ignore(10000, '\n');

	if (idClient > c->getRegisteredClients().size() || idClient <= 0)
	{
		cout << "Invalid client id" << endl <<endl;
		MakeReservation(c);
	}

	cout << c->getRegisteredClients()[idClient-1]->getInformation() << endl << endl;

	c->printOffers();

	cout << endl << "Insert the id of the corresponding offer: ";
	cin >> idOffer;
	cin.clear();
	cin.ignore(10000, '\n');

	if (idOffer > c->getOffers().size() || idOffer < 0)
	{
		cout << "Invalid offer id" << endl;
		MakeReservation(c);
	}
	Offer * offer = c->getOffers()[idOffer-1];

	cout << "How many tickets do you desire: ";
	cin >> nTick;
	cin.clear();
	cin.ignore(10000, '\n');

	if(nTick > offer->getVacancies())
		throw NoSeatsAvailable(c);

	unsigned int optionMR_R;

	cout << "Total: " << offer->getPrice() * nTick << "€,  Points Won: " << offer->getPoints()*nTick <<  endl;
	cout << "Want to confirm your reservation?: " << endl << endl;
	cout << "1 Yes" << endl;
	cout << "2 No" << endl;
	cout << "Insert the desired option: ";
	cin >> optionMR_R;
	cin.clear();
	cin.ignore(10000, '\n');

	if(optionMR_R == 1)
	{
		offer->addRegisteredClient(c->getRegisteredClients()[idClient-1], nTick);
		c->setBank (offer->getPercentage() * offer->getPrice() * nTick );
		MakeReservation(c);
	}
	else if (optionMR_R == 0)
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
	cin.clear();
	cin.ignore(10000, '\n');

	if ((idClient > c->getOccasionalClients().size() ))
	{
		cout << "Invalid client id" << endl;
		MakeReservation(c);
	}

	cout << c->getOccasionalClients()[idClient-1]->getInformation() << endl << endl;

	c->printOffers();

	cout << endl << "Insert the id of the corresponding offer: ";
	cin >> idOffer;
	cin.clear();
	cin.ignore(10000, '\n');

	if (idOffer > c->getOffers().size() || idOffer < 0)
	{
		cout << "Invalid offer id" << endl;
		MakeReservation(c);
	}
	Offer * offer = c->getOffers()[idOffer-1];

	cout << "How many tickets do you desire: ";
	cin >> nTick;
	cin.clear();
	cin.ignore(10000, '\n');

	if(nTick > offer->getVacancies())
		throw NoSeatsAvailable(c);

	unsigned int optionMR_O;

	cout << "Total: " << offer->getPrice() * nTick << "€" << endl;
	cout << "Want to confirm your reservation?: " << endl;
	cout << "1 Yes" << endl;
	cout << "2 No" << endl;
	cout << "Insert the desired option: ";
	cin >> optionMR_O;
	cin.clear();
	cin.ignore(10000, '\n');

	if(optionMR_O == 1)
		{
			offer->addOccasionalClient(c->getOccasionalClients()[idClient-1], nTick);
			c->setBank (offer->getPercentage() * offer->getPrice() * nTick );
			MakeReservation(c);
		}
	else if (optionMR_O == 0)
			MakeReservation(c);

	else
			throw InvalidOption(c);
}

void CancelReservation (Company *c)
{

}

void ViewFilesMenu (Company *c)
{
	unsigned int optionVFM = 0;
	cout << "************************" << endl;
	cout << "|      View Files      |" << endl;
	cout << "************************" << endl << endl;

	cout << "1 Clients" << endl;
	cout << "2 Suppliers" << endl;
	cout << "3 Offers" << endl;
	cout << "4 Back" << endl;
	cout << "Insert the desired option: ";
	cin >> optionVFM;
	cin.clear();
	cin.ignore(10000, '\n');

	switch(optionVFM)
	{
		case 1:
		{
			int optionVFM1;
			 cout << "************************" << endl;
			 cout << "|        Clients       |" << endl;
			 cout << "************************" << endl << endl;

			cout << "1 View all clients" << endl;
			cout << "2 View clients by points" << endl;
			cout << "3 Back" << endl;
			cout << "Insert the desired option: " << endl;
			cin >> optionVFM1;
			cin.clear();
			cin.ignore(10000, '\n');

			switch (optionVFM1)
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
			int optionVFM3;
			cout << "************************" << endl;
			cout << "|        Offers        |" << endl;
			cout << "************************" << endl << endl;

			cout << "1 View all offers" << endl;
			cout << "2 View offers by suppliers" << endl;
			cout << "3 Back" << endl;
			cout << "Insert the desired option: " << endl;
			cin >> optionVFM3;
			cin.clear();
			cin.ignore(10000, '\n');

			switch (optionVFM3)
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
					cin.clear();
					cin.ignore(10000, '\n');

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


