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
	cout << "3 Add a supplier"     << endl;
	cout << "4 View files"         << endl;
	cout << "5 Check bank"		   << endl;
	cout << "6 Exit"               << endl;
	cout << "Insert the desired option: ";

	cin >> optionCM;
	cin.clear();

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

			AddSupplier(c);
			break;

		}

		case 4:
		{
			ViewFilesMenu (c);
			break;
		}

		case 5:
		{
			cout << "Total: " << c->getBank() << "€" << endl;
			CompanyMenu(c);
			break;
		}

		case 6:
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
			int idClient;

			cout << "Insert your id: ";
			cin >> idClient;
			cin.clear();
			cin.ignore(10000, '\n');
			MakeReservation_Registered(c, idClient);
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
			{
				int idClient;

				c->printOccasionalClients();

				cout << "Insert your id: ";
				cin >> idClient;
				cin.clear();
				cin.ignore(10000, '\n');
				MakeReservation_Occasional(c, idClient);
			}
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

				MakeReservation_Registered(c, idReg);
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
				MakeReservation_Occasional(c, c->getOccasionalClients().size() - 1);
			}
			else if (optionMR3 == 1)
			{
				int id = c->RegisterClient(name, NIF);
				cout << "Your new id is: " << id << endl << endl;
				MakeReservation_Registered(c, id);
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

}

void MakeReservation_Registered (Company *c, int idClient)
{
	int idOffer, nTick;
	string d1, d2;

	if (idClient > c->getRegisteredClients().size() || idClient <= 0)
	{
		cout << "Invalid client id" << endl << endl;
		MakeReservation(c);
	}

	cout << c->getRegisteredClients()[idClient-1]->getInformation() << endl << endl;

	cout << "Enter the range of dates you're interested in: " << endl;
	cout << "Initial date (format DD-MM-YYYY): ";
	cin >> d1;
	Date date1 = Date(d1);

	cout << "Final date (format DD-MM-YYYY): " << endl;
	cin >> d2;
	Date date2 = Date (29,10,2017);

	c->printOfferbyDate(d1,d2);

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

void MakeReservation_Occasional (Company *c, int idClient)
{
	int idOffer, nTick;
	string d1,d2;

	cout << endl;
	c->printOccasionalClients();

	if ((idClient > c->getOccasionalClients().size() ))
	{
		cout << "Invalid client id" << endl;
		MakeReservation(c);
	}

	cout << c->getOccasionalClients()[idClient-1]->getInformation() << endl << endl;

	cout << "Enter the range of dates you're interested in: " << endl;
	cout << "Initial date (format DD-MM-YYYY): ";
	cin >> d1;
	Date date1 = Date(d1);

	cout << "Final date (format DD-MM-YYYY): " << endl;
	cin >> d2;
	Date date2 = Date (29,10,2017);

	c->printOfferbyDate(d1,d2);
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
	unsigned int optionC = 0;
	cout << "************************" << endl;
	cout << "|  Cancel Reservation  |" << endl;
	cout << "************************" << endl << endl;

	cout << "What type of client are you?" << endl;
	cout << " 1 Registered Client" << endl;
	cout << " 2 Occasional Client" << endl;
	cout << " 3 Back" << endl;
	cout << "Insert the desired option: ";
	cin >> optionC;
	cin.clear();
	cin.ignore(10000, '\n');

	switch(optionC)
		{
			case 1:
			{
				CancelReservationRegClient(c);
				break;
			}
			case 2:
			{
				CancelReservationOccClient(c);
				break;
			}
			case 3:
			{
				CompanyMenu(c);
			}
			default:
				throw InvalidOption(c);
			}
	}

void CancelReservationRegClient(Company *c)
{
	int idClient, idOffer, nTick;
	Date d1 ("20-11-2017");

	c->printRegisteredClients();
	cout << "What's you client id?";
	cin >> idClient;
	cin.clear();
	cin.ignore(10000, '\n');
	cout << endl;
	if (idClient > c->getRegisteredClients().size() || idClient <= 0)
		{
			cout << "Invalid client id" << endl <<endl;
			MakeReservation(c);
		}
	cout << c->getRegisteredClients()[idClient-1]->getInformation() << endl << endl;
	cout << endl << "Insert the id of the corresponding offer: ";
	cin >> idOffer;
	cin.clear();
	cin.ignore(10000, '\n');
	Offer * offer = c->getOffers()[idOffer-1];
	cout << "How many tickets do you want to cancel?" ;
	cin >> nTick;
	cin.clear();
	cin.ignore(10000, '\n');
	cout << endl;
	offer->elimRegisteredClient(c->getRegisteredClients()[idClient-1], nTick);

	Date d2 = offer->getDate();
		//Vamos ver a diferença das datas

	unsigned int diffDates = d1.daysBetween(d2);

	if (diffDates >=7 )
		{
			unsigned int devol = (offer->getPrice() * nTick);
			c->setBank( (-1) * offer->getPercentage() * devol);
			cout << "The refund amount is: " << devol << "€ " << endl;
		}
	else if (7 > diffDates && diffDates > 2)
		{
			unsigned int devol = (offer->getPrice() * nTick * 0.5);
			c->setBank( (-0.5) * offer->getPercentage() * devol);
			cout << "The refund amount is: " << devol << "€ " << endl;
		}
	else
		{
			cout << "Your cancelation was done too late. You have no refound." << endl;
		}

	CompanyMenu(c);
}

void CancelReservationOccClient(Company *c)
{

	int idClient, idOffer, nTick;
	Date d1 ("20-11-2017");

	c->printOccasionalClients();

	cout << "What's you client id?";
	cin >> idClient;
	cin.clear();
	cin.ignore(10000, '\n');
	cout << endl;

	if (idClient > c->getOccasionalClients().size() || idClient <= 0)
	{
			cout << "Invalid client id" << endl <<endl;
	}
	cout << c->getOccasionalClients()[idClient-1]->getInformation() << endl << endl;

	cout << endl << "Insert the id of the corresponding offer: ";
	cin >> idOffer;
	cin.clear();
	cin.ignore(10000, '\n');
	Offer * offer = c->getOffers()[idOffer-1];
	cout << "How many tickets do you want to cancel?" ;
	cin >> nTick;
	cin.clear();
	cin.ignore(10000, '\n');
	cout << endl;

	offer->elimOccasionalClient(c->getOccasionalClients()[idClient-1], nTick);
	Date d2 = offer->getDate();
	//Vamos ver a diferença das datas

	unsigned int diffDates = d1.daysBetween(d2);

	if (diffDates >=7 )
	{
		unsigned int devol = offer->getPrice() * nTick;
		c->setBank( (-1) * offer->getPercentage() * devol);
		cout << "The refund amount is: " << devol << "€ " << endl;
	}

	else if (7 > diffDates && diffDates > 2)
	{
		unsigned int devol = offer->getPrice() * nTick * 0.5;
		c->setBank( (-0.5) * offer->getPercentage() * devol);
		cout << "The refund amount is: " << devol << "€ " << endl;
	}
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
					cout << endl << "Enter the id of the offer to see who bought the tickets (enter 0 to exit): ";
					cin >> idOffer;

					if( idOffer == 0)
						break;
					else if (idOffer < 0 || idOffer > c->getOffers().size() )
						throw InvalidOption(c);
					else
						c->printClientsByOffer(idOffer);
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

void AddSupplier(Company *c)
{
	string name;
	int NIF;
	string address;

	cout << "Please enter the supplier's name: ";
	getline(cin, name);
	cin.clear();
	cin.ignore(10000, '\n');

	cout << "Please enter the supplier's NIF: ";
	cin >> NIF;
	cin.clear();
	cin.ignore(10000, '\n');

	cout << "Please enter the supplier's address: ";
	getline(cin, address);
	cin.clear();

	c->AddSupplier(name, NIF, address);

	unsigned int option;

	while (1)
	{
		cout << "Want to add offers?" << endl;
		cout << " 1 Yes" << endl;
		cout << " 2 No " << endl;
		cout << "Enter the desired option: ";
		cin >> option;

		if(option != 1 && option != 2)
			throw InvalidOption(c);

		else if (option == 2)
			break;

		else
		{
			unsigned int cap, dist, pri, points;
			double perc;
			string dest, bT, date;
			int b_option, d_option;

			do
			{
				cout << endl << "Enter the destination: " << endl;
				cout << " 1 Régua" << endl;
				cout << " 2 Barca d'Alva " << endl;
				cout << " 3 Pinhão" << endl;
				cout << "Enter the desired option: ";
				cin >> d_option;

				if (d_option < 1 || d_option > 3)
					cout << "Invalid option. Try again" ;
				else
					switch (d_option)
					{
						case 1:
							dest = "Régua";
						case 2:
							dest = "Barca d'Alva";
						case 3:
							dest = "Pinhão";
					}
			} while (d_option < 1 || d_option > 3);

			do
			{

				cout << endl << "Enter the type of boat: " << endl;
				cout << " 1 Veleiro" << endl;
				cout << " 2 Barco Rabelo" << endl;
				cout << " 3 Iate" << endl;
				cout << "Enter the desired option: ";
				cin >> b_option;

				if (b_option < 1 || b_option > 3)
					cout << "Invalid option. Try again" << endl;

				else
					switch(b_option)
					{
						case 1:
							bT = "Veleiro";
						case 2:
							bT = "Barco Rabelo";
						case 3:
							bT = "Iate";
					}
			} while (b_option < 1 || b_option > 3);

			cout << "Enter the boat's capacity: ";
			cin >> cap;

			cout << "Enter the distance to travel: ";
			cin >> dist;

			cout << "Enter the price: ";
			cin >> pri;

			cout << "Enter the points/ticket available for registered clients: ";
			cin >> points;

			cout << "Enter the percentage of each ticket that goes to 'Porto Rivers': ";
			cin >> perc;

			cout << "Enter the date of this offer (format DD-MM-YYYY): ";
			cin >> date;
			Date d(date);


			c->addOffer(pri, dist, cap, points, perc, bT, dest, name,d);

		}
	}


	CompanyMenu (c);
}

