#include "BankingSystem.h"
#include <iostream>
using namespace std;
void BankingSystem::menu()
{
	int choice;
	do {
		cout << "\n--- Banking System Menu ---\n";
		cout << "1. Create Customer\n";
		cout << "2. Create Account\n";
		cout << "3. Deposit\n";
		cout << "4. Withdraw\n";
		cout << "5. Transfer\n";
		cout << "6. Show Balance\n";
		cout << "7. Show Transactions\n";
		cout << "0. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			createCustomer();
			break;
		}
		case 2:
		{
			createAccount();
			break;
		}
		case 3:
		{
			deposit();
			break;
		}
		case 4:
		{
			withdraw();
			break;
		}
		case 5:
		{
			transfer();
			break;
		}
		case 6:
		{
			showBalance();
			break;
		}
		case 7:
		{
			showTransactions();
			break;
		}
		case 0:
		{
			cout << "Exiting...\n"; break;
		}
		default:
		{
			cout << "Invalid choice!\n";
		}
		}
	} while (choice != 0);

}
void BankingSystem::createCustomer()
{
	int id;
	string name, addr;
	cout << "Enter Customer ID: ";
	cin >> id;
	cout << "Enter Name: ";
	cin >> name;
	cout << "Enter Address: ";
	cin >> addr;
	customers.push_back(Customer(id, name, addr));
	cout << "Customer created successfully!\n";
}

void BankingSystem::createAccount()
{
	int accId;
	int custId;
	string type;
	double bal;
	cout << "Enter Account ID: ";
	cin >> accId;
	cout << "Enter Customer ID: ";
	cin >> custId;
	cout << "Enter Account Type: ";
	cin >> type;
	cout << "Enter Initial Balance: ";
	cin >> bal;
	accounts.push_back(Account(accId, custId, type, bal));
	cout << "Account created successfully!\n";
}

void BankingSystem::deposit()
{
	int accId; double amt;
	cout << "Enter Account ID: ";
	cin >> accId;
	cout << "Enter Amount to Deposit: ";
	cin >> amt;
	for (auto& a : accounts)
	{
		if (a.getId() == accId)
		{
			a.deposit(amt);
			cout << "Deposit successful!\n";
			return;
		}
	}
	cout << "Account not found!\n";
}

void BankingSystem::withdraw()
{
	int accId;
	double amt;
	cout << "Enter Account ID: ";
	cin >> accId;
	cout << "Enter Amount to Withdraw: ";
	cin >> amt;
	for (auto& a : accounts)
	{
		if (a.getId() == accId)
		{
			if (a.withdraw(amt))
			{
				cout << "Withdrawal successful!\n";
			}
			else
			{
				cout << "Insufficient balance!\n";
			}
			return;
		}
	}
	cout << "Account not found!\n";
}
void BankingSystem::transfer()
{
	int fromId, toId; double amt;
	cout << "Enter From Account ID: ";
	cin >> fromId;
	cout << "Enter To Account ID: ";
	cin >> toId;
	cout << "Enter Amount to Transfer: ";
	cin >> amt;
	Account* from = nullptr;
	Account* to = nullptr;
	for (auto& a : accounts)
	{
		if (a.getId() == fromId)
		{
			from = &a;
		}
		if (a.getId() == toId)
		{
			to = &a;
		}
	}
	if (from && to)
	{
		if (from->transfer(*to, amt))
		{
			cout << "Transfer successful!\n";
		}
		else
		{
			cout << "Insufficient balance!\n";
		}
	}
	else
	{
		cout << "Account not found!\n";
	}
}

void BankingSystem::showBalance()
{
	int accId;
	cout << "Enter Account ID: ";
	cin >> accId;
	for (auto& a : accounts)
	{
		if (a.getId() == accId)
		{
			a.display();
			return;
		}
	}
	cout << "Account not found!\n";
}

void BankingSystem::showTransactions()
{
	int accId;
	cout << "Enter Account ID: ";
	cin >> accId;
	for (auto& a : accounts)
	{
		if (a.getId() == accId)
		{
			a.showTransactions();
			return;
		}
	}
	cout << "Account not found!\n";
}
