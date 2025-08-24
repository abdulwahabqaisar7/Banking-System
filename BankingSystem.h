#ifndef BANKINGSYSTEM_H
#define BANKINGSYSTEM_H

#include <vector>
#include "Customer.h"
#include "Account.h"

class BankingSystem {
private:
    vector<Customer> customers;
    vector<Account> accounts;

public:

    void menu();
    void createCustomer();
    void createAccount();
    void deposit();
    void withdraw();
    void transfer();
    void showBalance();
    void showTransactions();
};

#endif

