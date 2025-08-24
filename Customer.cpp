#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer(int id, string n, string addr) : customerId(id), name(n), address(addr)
{
}
void Customer::display() const
{
    cout << "Customer ID: " << customerId
        << " | Name: " << name
        << " | Address: " << address << '\n';
}
int Customer::getId() const
{
    return customerId;
}
string Customer::getName() const
{
    return name;
}
#include "Customer.h"
