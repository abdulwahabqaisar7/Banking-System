#include "Account.h"
#include <iostream>
using namespace std;
Account::Account(int id, int cId, string type, double bal) : accountId(id), customerId(cId), accountType(type)
{
    if (bal < 0.0)
    {
        balance = 0.0;
        return;
    }
    balance = bal;
}
void Account::deposit(double amount)
{
    if (amount < 0.0)
    {
        cout << "Not possible" << "\n";
        return;
    }
    balance += amount;
    addTransaction("Deposit", amount);
}

bool Account::withdraw(double amount)
{
    if (amount <= balance)
    {
        balance -= amount;
        addTransaction("Withdraw", amount);
        return true;
    }
    return false;
}

bool Account::transfer(Account& to, double amount)
{
    if (amount <= balance)
    {
        balance -= amount;
        to.deposit(amount);
        addTransaction("Transfer Out", amount);
        to.addTransaction("Transfer In", amount);
        return true;
    }
    return false;
}

void Account::addTransaction(string type, double amount)
{
    transactions.push_back(Transaction(transactions.size() + 1, type, amount));
}

void Account::showTransactions() const
{
    cout << "Transaction history for Account " << accountId << ":\n";
    for (const auto& t : transactions)
    {
        t.display();
    }
}

void Account::display() const
{
    cout << "Account ID: " << accountId
        << " | Customer ID: " << customerId
        << " | Type: " << accountType
        << " | Balance: " << balance << '\n';
}

int Account::getId() const
{
    return accountId;
}
int Account::getCustomerId() const
{
    return customerId;
}
double Account::getBalance() const
{
    return balance;
}