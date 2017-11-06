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

	std::ifstream inFile(file.c_str());
	if (inFile.is_open()) {
		std::string line;

		while (getline(inFile, line))
			lines.push_back(line);
		inFile.close();
	}
	return lines;
}

std::vector<Client *> FileReader::readClients(std::string file)
{
	std::vector<Client *> clients;
	std::cout << "1";
	std::vector<std::string> lines = FileReader::readLines(file);
	std::cout << lines.size() << endl;
	for (unsigned int i = 0; i < lines.size(); i++)
	{
		std::string line = lines.at(i);
		std::cout << "3";
		std::string name, NIF=0;

		line = line.substr(line.find(',') + 2);
		name = line.substr(0,line.find(','));
		line = line.substr(line.find(',') + 2);
		NIF = line.substr(0,line.find(';'));

		Client *c = new Client(name, std::stoi(NIF.c_str()));
		clients.push_back(c);
		Client *c1 = new Client ("32",i);
		clients.push_back(c1);
		std::cout << "4";
	}
	std::cout << "5";
	return clients;
}


