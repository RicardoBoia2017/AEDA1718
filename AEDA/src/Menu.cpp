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
	cout << "2 View files"         << endl;
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

		default:
			throw InvalidOption(c);
	}
}

void MakeReservation (Company *c)
{

}

void CancelReservation (Company *c)
{

}

void ViewFilesMenu (Company *c)
{
	int option;
	cout << "***********************" << endl;
	cout << "|     Porto Rivers    |" << endl;
	cout << "***********************" << endl << endl;

	cout << "1 Clients" << endl;
	cout << "2 Suppliers" << endl;
	cout << "Insert the desired option: ";
	cin >> option;

}


