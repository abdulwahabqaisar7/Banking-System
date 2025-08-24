#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include "Transaction.h"
using namespace std;
enum AccountType { SAVINGS, CURRENT };
class Account {
private:
    int accountId;
    int customerId;
    string accountType;
    double balance;
    vector<Transaction> transactions;

public:
    Account(int id = 0, int cId = 0, string type = "Saving", double bal = 0.0);
    void deposit(double amount);
    bool withdraw(double amount);
    bool transfer(Account& to, double amount);
    void addTransaction(string type, double amount);
    void showTransactions() const;
    void display() const;
    int getId() const;
    int getCustomerId() const;
    double getBalance() const;
};
#endif
