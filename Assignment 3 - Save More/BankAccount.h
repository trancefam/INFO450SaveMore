#pragma once
#include <string>

class BankAccount
{
protected:
	char openDate[11]; 
	std::string accountType;
	static int accountNumberGenerator;
	int accountNumber;
	double monthlyInterestRate;
	double annualInterestRate;
	double balance = 0;
	double intAmt;

public:
	BankAccount(double intBalance);
	virtual int withdrawal(double amt) = 0;
	virtual int deposit(double amt) = 0;
	virtual void displayInfo();
	virtual void assessInterest();
	virtual void orderChecks();
	void listInfo();
	double getBalance();
	void setOpenDate();
};

