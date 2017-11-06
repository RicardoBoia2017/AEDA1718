/*
 * FileReader.h
 *
 *  Created on: 06/11/2017
 *      Author: ricar
 */

#ifndef SRC_FILEREADER_H_
#define SRC_FILEREADER_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Client.h"
#include "Supplier.h"
#include "Offer.h"

class FileReader
{
private:
	static std::vector<std::string> readLines(std::string file);
public:
	static std::vector<Client *> readClients(std::string file);
};



#endif /* SRC_FILEREADER_H_ */
