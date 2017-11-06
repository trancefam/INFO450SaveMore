#pragma once
#include "BankAccount.h"

class Savings :	public BankAccount
{
	double oldInterestRate;

public:
	Savings(double intBalance);
	int withdrawal(double amt);
	int deposit(double amt);
	void updateInterestRate();
};

