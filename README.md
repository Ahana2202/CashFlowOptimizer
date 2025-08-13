# CashFlowOptimizer
A C++ program to minimize and optimize cash flow between multiple people based on their transactions.
Cashflow Optimiser
A C++ program that reduces cash flow amount among a group of people by optimising debt repayments.
Instead of performing many small transactions, this program will find the least number of transactions so that everyone can settle in the most efficient way.
 Features
Takes a transaction matrix input.
Calculates net amounts owing for each individual.
Outputs optimised transactions by number of transactions (minimal payments).
Runs for any number of individuals.

 Example
Input:
Number of people: 3

Transaction matrix (amount person i paid people j):
0 123 230
130 245 187
230 500 600

Output:
Person 2 needs to pay Person 0 an amount of 7
Person 2 needs to pay Person 1 an amount of 306
