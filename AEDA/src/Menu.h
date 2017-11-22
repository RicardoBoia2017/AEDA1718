/*
 * Menu.h
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#pragma once
#include <iostream>
#include <limits>

#include "Company.h"
#include "FileReader.h"


void CompanyMenu (Company *c);

void MakeReservation (Company *c);
void MakeReservation_Registered (Company *c, unsigned int id);
void MakeReservation_Occasional (Company *c, unsigned int id);

void CancelReservation (Company *c);
void CancelReservationRegClient(Company *c);
void CancelReservationOccClient(Company *c);

void ViewFilesMenu (Company *c);

void AddSupplier(Company *c);
void AddOffer(Company *c);

/**
 * Called when the user inserts an invalid option in a menu.
 * @param c company.
 * @param menu that will be called.
 */
class InvalidOption
{
public:
	InvalidOption(Company *c, int menu)
	{
		std::cout << std::endl << "Invalid option"  << std::endl;

		switch (menu)
		{
			case 1:
				CompanyMenu (c);

			case 2:
				MakeReservation (c);

			case 3:
				CancelReservation (c);

			case 4:
				ViewFilesMenu (c);

		}

	}
};

/**
 * Called when the user tries more tickets than the ones available.
 * @param c company.
 */
class NoSeatsAvailable
{
public:
	NoSeatsAvailable (Company *c)
	{
		std::cout << std::endl << "Sorry! There aren't enough seats available." << std::endl;
		MakeReservation(c);
	}
};
