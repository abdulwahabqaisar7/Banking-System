#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer {
private:
    int customerId;
    string name;
    string address;

public:
    Customer(int id = 0, string n = "", string addr = "");
    void display() const;
    int getId() const;
    string getName() const;
};

#endif
