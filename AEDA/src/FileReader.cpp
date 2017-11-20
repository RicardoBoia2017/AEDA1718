/*
 * FileReader.cpp
 *
 *  Created on: 06/11/2017
 *      Author: ricar
 */

#include "FileReader.h"

#include <iostream>


using namespace std;


vector<string> FileReader::readLines(string file) {
	vector<string> lines;

	ifstream inFile(file);
	if (inFile.is_open())
	{
		string line;

		while (getline(inFile, line)) {
			lines.push_back(line);
		}

		inFile.close();
	}

	return lines;
}

vector<RegisteredClient *> FileReader::readRegisteredClients(string file)
{
	vector<RegisteredClient *> rClients;
	vector<string> lines = FileReader::readLines(file);

	for (unsigned int i = 0; i < lines.size(); i++)
	{
		string line = lines[i];
		string name, NIF, points;

		line = line.substr(line.find(',') + 2);
		name = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		NIF = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		points = line.substr(0, line.find(';'));

		RegisteredClient *rc = new RegisteredClient(name, stoi(NIF.c_str()), stoi(points.c_str()));
		rClients.push_back(rc);
	}


	return rClients;
}

vector<OccasionalClient*> FileReader::readOccasionalClients(string file)
{
	vector<OccasionalClient *> oClients;
	vector<string> lines = FileReader::readLines(file);

	for (unsigned int i = 0; i < lines.size(); i++)
	{
		string line = lines[i];
		string name, NIF;

		line = line.substr(line.find(',') + 2);
		name = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		NIF = line.substr(0, line.find(';'));

		OccasionalClient *oc = new OccasionalClient(name, stoi(NIF.c_str()) );
		oClients.push_back(oc);
	}


	return oClients;
}

vector<Supplier *> FileReader::readSuppliers(string file)
{
	vector<Supplier *> suppliers;
	vector<string> lines = FileReader::readLines(file);

	for (unsigned int i = 0; i < lines.size(); i++)
	{
		string line = lines[i];
		string name, NIF, address;

		line = line.substr(line.find(',') + 2);
		name = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		NIF = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		address = line.substr(0 ,line.find(';'));

		Supplier *s = new Supplier (name, stoi(NIF.c_str()), address);
		suppliers.push_back (s);

	}

	return suppliers;
}


vector<Offer *> FileReader::readOffers (string file)
{
	vector<Offer *> offers;
	vector<string> lines = FileReader::readLines(file);

	for (unsigned int i = 0; i < lines.size(); i++)
	{
		string line = lines[i];
		string supName, price, dist, cap, bType, dest, points, percentage, day, month, year;

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
		Offer *o = new Offer (stoi(price.c_str()), stoi(dist.c_str()),stoi(cap.c_str()), bType, dest, supName, stoi(points.c_str()), stod(percentage.c_str()),d );

		offers.push_back(o);
	}

	return offers;
}
