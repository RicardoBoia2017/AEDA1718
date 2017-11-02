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
