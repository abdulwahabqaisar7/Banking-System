#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;
class Transaction
{
    int transactionId;
    string type;
    double amount;

public:

    Transaction(int id = 0, string t = "", double amt = 0.0);
    void display() const;
};

#endif