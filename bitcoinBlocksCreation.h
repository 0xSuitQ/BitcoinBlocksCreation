#ifndef BTCBLOCKCREATION_H
#define BTCBLOCKCREATION_H

#include <iostream>
#include <list>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

typedef struct Transaction {
	std::string		id;
	int				size;
	int				fee;
} Transaction;

#endif