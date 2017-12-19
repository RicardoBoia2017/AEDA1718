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

/**
 * Main menu.
 * @param c company.
 */
bool CompanyMenu (Company *c);

/**
 * Menu to make a reservation.
 * @param c company.
 */
bool MakeReservation (Company *c);
/**
 * Menu to make a reservation for registered clients.
 * @param c company
 * @param client's id.
 */
bool MakeReservation_Registered (Company *c, unsigned int id);
/**
 * Menu to make a reservation for occasional clients.
 * @param c company
 * @param client's id.
 */
bool MakeReservation_Occasional (Company *c, unsigned int id);

/**
 * Menu to cancel reservations.
 */
bool CancelReservation (Company *c);
/**
 * Menu to cancel registered client's reservations.
 * @param c company.
 */
bool CancelReservationRegClient(Company *c);
/**
 * Menu to cancel occasional client's reservations.
 * @param c company.
 */
bool CancelReservationOccClient(Company *c);

/**
 * Menu where is possible to view all text files.
 * @param c company.
 */
bool ViewFilesMenu (Company *c);

/**
 * Menu to add a new supplier.
 * @param c company.
 */
bool AddSupplier(Company *c);

/**
 * Menu to add a new offer.
 * @param c company.
 */
bool AddOffer(Company *c);

/**
 * Called when the user inserts an invalid option in a menu.
 */
class InvalidOption
{
public:
	/**
	 * The constructor
	 * @param c company.
	 * @param menu that will be called.
	 */
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
 * Called when the user tries to buy more tickets than the ones available.

 */
class NoSeatsAvailable
{
public:
	/* *
	 * The constructor
	 * @param c company.
	 */
	NoSeatsAvailable (Company *c)
	{
		std::cout << std::endl << "Sorry! There aren't enough seats available." << std::endl;
		MakeReservation(c);
	}
};
