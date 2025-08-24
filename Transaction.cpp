#include <iostream>
using namespace std;
#include "Transaction.h"
Transaction::Transaction(int id, string t, double amt) : transactionId(id), type(t), amount(amt)
{
}
void Transaction::display() const
{
    cout << "Transaction ID: " << transactionId
        << " | Type: " << type
        << " | Amount: " << amount << '\n';
}