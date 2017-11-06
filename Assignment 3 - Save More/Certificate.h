#pragma once
#include "BankAccount.h"

class Certificate :	public BankAccount
{

	static int TERM;
	double fee;

public:
	Certificate(double intBalance, int years);
	int withdrawal(double amt);
	int deposit(double amt);
	void displayInfo();
};

