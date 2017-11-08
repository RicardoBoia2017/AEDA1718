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
	cout << file;
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
		name = line.substr(0,line.find(','));
		line = line.substr(line.find(',') + 2);
		NIF = line.substr(0,line.find(';'));

		Client *c = new Client(name, std::stoi(NIF.c_str()));
		clients.push_back(c);
	}


	return clients;
}


