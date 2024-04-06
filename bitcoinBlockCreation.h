#ifndef BTCBLOCKCREATION_H
#define BTCBLOCKCREATION_H

#include <iostream>
#include <list>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <chrono>
using namespace std::chrono;
using namespace std;

typedef struct Transaction {
	std::string		tx_id;
	int				tx_size;
	int				tx_fee;
} Transaction;

typedef struct Block {
	std::vector<Transaction> transactions;
	int						block_size;
	int						block_fee;
} Block;

#endif