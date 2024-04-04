#include "bitcoinBlocksCreation.h"

void	sort_transactions(std::vector<Transaction> &transactions) {
	std::sort(transactions.begin(), transactions.end(), [](Transaction a, Transaction b) {
		return (a.fee / a.size) > (b.fee / b.size);
	});
}

void	parse_transaction(std::vector<Transaction> &transactions, vector<string> row) {
	Transaction transaction;

	transaction.id = row[0];
	transaction.size = stoi(row[1]);
	transaction.fee = stoi(row[2]);
	transactions.push_back(transaction);
}

void	read_parse_csv(std::vector<Transaction> &transactions, std::string filename) {
	fstream fin;
	vector<string> row;
	string line, word, temp;

	fin.open(filename, ios::in);
	if (!fin.is_open()) {
		std::cout << "Error: file not found" << std::endl;
		return;
	}
	while (fin >> temp) {
		row.clear();
		getline(fin, line);
		stringstream s(line);
		while (getline(s, word, ',')) {
			row.push_back(word);
		}
		parse_transaction(transactions, row);
	}
}

int main() {
	std::vector<Transaction> transactions;
	std::string filename;

	std::cout << "Enter the name of the file with transactions: ";
	std::cin >> filename;
	read_parse_csv(transactions, filename);
	sort_transactions(transactions);
}