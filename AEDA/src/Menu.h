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

void CompanyMenu (Company *c);

void MakeReservation (Company *c);
void MakeReservation_Registered (Company *c);
void MakeReservation_Occasional (Company *c);

void CancelReservation (Company *c);

void ViewFilesMenu (Company *c);

void Check_Bank (Company *c);

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
		std::cout << std::endl << "Sorry! There aren't enough seats available." << std::endl;
		MakeReservation(c);
	}
};
