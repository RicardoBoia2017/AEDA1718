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

std::vector<Client *> FileReader::readClients(std::string file)
{
	std::vector<Client *> clients;
	std::vector<std::string> lines = FileReader::readLines(file);

	for (unsigned int i = 0; i < lines.size(); i++)
	{
		std::string line = lines[i];
		std::string name, NIF;

		line = line.substr(line.find(',') + 2);
		name = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		NIF = line.substr(0, line.find(';'));

		RegisteredClient *c = new RegisteredClient(name, std::stoi(NIF.c_str()));
		clients.push_back(c);
	}


	return clients;
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


//std::vector<Offer *> FileReader::readOffers (std::string file)
//{
//	std::vector<Offer *> offers;
//	std::vector<std::string> lines = FileReader::readLines(file);
//
//	for (unsigned int i = 0; i < lines.size(); i++)
//	{
//		std::string line = lines[i];
//		std::string name, NIF, address;
//
//		line = line.substr(line.find(',') + 2);
//	}
//
//}
