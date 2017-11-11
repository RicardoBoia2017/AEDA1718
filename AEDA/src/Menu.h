/*
 * Menu.h
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#pragma once
#include <iostream>

#include "Company.h"

void CompanyMenu (Company *c);

void MakeReservation (Company *c);

void CancelReservation (Company *c);

void ViewFilesMenu (Company *c);

class InvalidOption
{
public:
	InvalidOption(Company *c)
	{
		std::cout << std::endl << "Invalid option"  << std::endl;
		CompanyMenu(c);
	}
};

class NoSeatsAvailable
{
public:
	NoSeatsAvailable (Company *c)
	{
		std::cout << std::endl << "Sorry! There are no more seats available for this trip." << std::endl;
		MakeReservation(c);
	}
};
