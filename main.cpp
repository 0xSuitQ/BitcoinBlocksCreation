#include "bitcoinBlockCreation.h"

void	init_block(Block &block) {
	block.block_size = 0;
	block.block_fee = 0;
}

void	sort_transactions(std::vector<Transaction> &transactions) {
	std::sort(transactions.begin(), transactions.end(), [](Transaction a, Transaction b) {
		return (a.tx_fee / a.tx_size) > (b.tx_fee / b.tx_size);
	});
}

void	build_block(std::vector<Transaction> &transactions, Block &block) {
	for (Transaction transaction : transactions) {
		if (transaction.tx_size + block.block_size <= 1048576) {
			block.transactions.push_back(transaction);
			block.block_size += transaction.tx_size;
			block.block_fee += transaction.tx_fee;
		}
	}
}

void	parse_transaction(std::vector<Transaction> &transactions, vector<string> row) {
	Transaction transaction;

	transaction.tx_id = row[0];
	transaction.tx_size = stoi(row[1]);
	transaction.tx_fee = stoi(row[2]);
	transactions.push_back(transaction);
}

void	read_parse_csv(std::vector<Transaction> &transactions, std::string filename) {
	fstream 		fin;
	vector<string> 	row;
	bool			is_first_line;
	string 			line, word, temp;

	fin.open(filename, ios::in);
	if (!fin.is_open()) {
		std::cout << "Error: file not found" << std::endl;
		return;
	}
	is_first_line = true;
	while (getline(fin, line)) {
		row.clear();
		if (is_first_line) {
			is_first_line = false;
			continue;
		}
		stringstream s(line);
		while (getline(s, word, ',')) {
			row.push_back(word);
		}
		parse_transaction(transactions, row);
	}
}

void	print_info(Block block, long time_elapsed) {
	char	choice;

	std::cout << "Block size: " << block.block_size << " bytes" << std::endl;
	std::cout << "Block fee: " << block.block_fee << " SATS" << std::endl;
	std::cout << "Block creation time: " << time_elapsed << " ms" << std::endl;
	std::cout << "Number of transactions: " << block.transactions.size() << std::endl;
	std::cout << "Do you want to see the list of transactions? (y/n): ";
	std::cin >> choice;
	if (tolower(choice) == 'y') {
		for (Transaction transaction : block.transactions) {
			std::cout << transaction.tx_id << " " << transaction.tx_size << " " << transaction.tx_fee << std::endl;
		}
	}
}

int main() {
	std::vector<Transaction> transactions;
	Block block;
	std::string filename;
	long time_elapsed = 0;

	std::cout << "Enter the name of the file with transactions: ";
	std::cin >> filename;
	auto start = high_resolution_clock::now();
	read_parse_csv(transactions, filename);
	init_block(block);
	sort_transactions(transactions);
	build_block(transactions, block);
	auto stop = high_resolution_clock::now();
	time_elapsed = duration_cast<milliseconds>(stop - start).count();
	print_info(block, time_elapsed);
	return 0;
}