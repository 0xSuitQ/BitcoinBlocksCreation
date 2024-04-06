# BitcoinBlocksCreation

Backpack with Bitcoin transactions

You are a developer of the Bitcoin mining software. The goal is to implement the most efficient method for constructing the block, which extracts the biggest fee from the user’s transactions. There are several requirements:

- As input, the program receives an array with 100,000 transactions
- Each transaction has 2 arbitrary parameters that need to be accounted for:
	- Size (in bytes)
	- Fee (in number of satoshies)
- The program's output is the Bitcoin block, which is limited to 1MB
- The extracted fee must be the biggest possible

Create a console app that consumes the file with transactions. The input is a CSV file with the following structure: `tx_id, tx_size, tx_fee`. The amount of transactions is limited to 100,000 (optionally unlimited).

The program should display the following output:

- Constructed block
- Amount of transactions in the block
- The block size
- The total extracted value
- Construction time
- The max memory dedicated to storing intermediate pre-calculations
- The probability of the extracted fee value being the biggest (optionally)

## How to run

1. Clone the repository from GitHub.
2. Open a terminal and navigate to the project directory.
3. Run the program by typing `./bitcoinBlockCreation`.
4. Enter a name of the .csv file with transactions. I already have randomly generated files with 100,000 transactions, so you can use those.
5. If you want to see all transactions after the block is created press `y`.

## Efficiency

The solution is efficient in terms of both storage and execution time. Here are some reasons why:

- Vector Usage: Employs std::vector for transactions and block.transactions. Vectors efficiently manage memory, dynamically adjusting size as needed, avoiding unnecessary allocations or unused space.
- The core logic is streamlined, focusing on essential tasks for block creation without extraneous processing.

Approximate amount of time spent on the task: 3h