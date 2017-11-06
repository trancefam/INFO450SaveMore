#pragma once
#include "BankAccount.h"

class Checking : public BankAccount
{
	double originalBal;

public:
	Checking(double intBalance);
	int withdrawal(double amt);
	int deposit(double amt);
	void orderChecks();
};

