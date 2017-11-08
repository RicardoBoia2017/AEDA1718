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
	cout << "fdfd";
	ifstream inFile(file);
	if (inFile.is_open())
	{
		cout << "ff" ;
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
	cout << "lll";
	std::vector<std::string> lines = FileReader::readLines(file);
	for (unsigned int i = 0; i < lines.size(); i++)
	{
		cout << "e";
		std::string line = lines[i];
		std::cout << "3";
		std::string name, NIF=0;

		line = line.substr(line.find(',') + 2);
		name = line.substr(0,line.find(','));
		line = line.substr(line.find(',') + 2);
		NIF = line.substr(0,line.find(';'));

		Client *c = new Client(name, std::stoi(NIF.c_str()));
		clients.push_back(c);
		std::cout << "4";
	}
	std::cout << "5";
	return clients;
}


