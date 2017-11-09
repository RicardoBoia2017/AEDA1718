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
	int option;
	cout << "***********************" << endl;
	cout << "|   Make Reservation   |" << endl;
	cout << "***********************" << endl << endl;

	cout << "Are you a registered client?" << endl;
	cout << " 1 Yes" << endl;
	cout << " 2 No" << endl;
	cout << "3 Back" << endl;
	cin >> option;

	switch (option)
	{
		case 1:
		{
			int id;
			cout << "Insert your id: ";
			cin >> id;

			if ( id > 0 && id < c->getClients().size() )
				cout << c->getClients()[id-1]->getInformation();
			else
			{
				cout << "Invalid id" << endl;
				MakeReservation(c);
			}
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
			cout << endl;
			c->printClients();
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


