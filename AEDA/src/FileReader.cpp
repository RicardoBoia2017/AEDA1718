/*
 * FileReader.cpp
 *
 *  Created on: 06/11/2017
 *      Author: ricar
 */

#include "FileReader.h"

#include <iostream>


using namespace std;


std::vector<std::string> FileReader::readLines(std::string file) {
	std::vector<std::string> lines;

	ifstream inFile(file);
	if (inFile.is_open())
	{
		std::string line;

		while (getline(inFile, line)) {
			lines.push_back(line);
		}

		inFile.close();
	}

	return lines;
}

std::vector<RegisteredClient *> FileReader::readRegisteredClients(std::string file)
{
	std::vector<RegisteredClient *> rClients;
	std::vector<std::string> lines = FileReader::readLines(file);

	for (unsigned int i = 0; i < lines.size(); i++)
	{
		std::string line = lines[i];
		std::string name, NIF, points;

		line = line.substr(line.find(',') + 2);
		name = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		NIF = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		points = line.substr(0, line.find(';'));

		RegisteredClient *rc = new RegisteredClient(name, std::stoi(NIF.c_str()), std::stoi(points.c_str()));
		rClients.push_back(rc);
	}


	return rClients;
}

std::vector<OccasionalClient*> FileReader::readOccasionalClients(std::string file)
{
	std::vector<OccasionalClient *> oClients;
	std::vector<std::string> lines = FileReader::readLines(file);

	for (unsigned int i = 0; i < lines.size(); i++)
	{
		std::string line = lines[i];
		std::string name, NIF;

		line = line.substr(line.find(',') + 2);
		name = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		NIF = line.substr(0, line.find(';'));

		OccasionalClient *oc = new OccasionalClient(name, std::stoi(NIF.c_str()) );
		oClients.push_back(oc);
	}


	return oClients;
}

std::vector<Supplier *> FileReader::readSuppliers(std::string file)
{
	std::vector<Supplier *> suppliers;
	std::vector<std::string> lines = FileReader::readLines(file);

	for (unsigned int i = 0; i < lines.size(); i++)
	{
		std::string line = lines[i];
		std::string name, NIF, address;

		line = line.substr(line.find(',') + 2);
		name = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		NIF = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		address = line.substr(0 ,line.find(';'));

		Supplier *s = new Supplier (name, std::stoi(NIF.c_str()), address);
		suppliers.push_back (s);

	}

	return suppliers;
}


std::vector<Offer *> FileReader::readOffers (std::string file)
{
	std::vector<Offer *> offers;
	std::vector<std::string> lines = FileReader::readLines(file);

	for (unsigned int i = 0; i < lines.size(); i++)
	{
		std::string line = lines[i];
		std::string supName, price, dist, cap, bType, dest, points, percentage, day, month, year;

		line = line.substr(line.find(',') + 2);
		day = line.substr(0, line.find('/'));
		line = line.substr(line.find('/') + 1);
		month = line.substr(0,line.find('/'));
		line = line.substr(line.find('/') + 1);
		year = line.substr (0, line.find(','));
		line = line.substr(line.find(',') + 2);
		supName = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		price = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		dist = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		cap = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		bType = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		dest = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		points = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		percentage = line.substr(0, line.find(';'));

		Date d = Date(stoi(day.c_str()), stoi(month.c_str()), stoi(year.c_str()) );
		Offer *o = new Offer (std::stoi(price.c_str()), std::stoi(dist.c_str()),std::stoi(cap.c_str()), bType, dest, supName, std::stoi(points.c_str()), std::stod(percentage.c_str()),d );

		offers.push_back(o);
	}

	return offers;
}
