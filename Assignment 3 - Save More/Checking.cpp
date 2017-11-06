#include "stdafx.h"
#include "Checking.h"
#include <iostream>


Checking::Checking(double intBalance) : BankAccount(intBalance)
{
	accountType = "Checking";
	annualInterestRate = 0;
	monthlyInterestRate = 1;
}

int Checking::withdrawal(double amt)
{
	originalBal = balance;

	if ((balance < amt) || 
		((balance >= 500) && ((balance - amt) < 500) && ((balance - amt - 5) < 0)))
		return 1; //withdrawal should never make account negative

	balance -= amt; 
	
	if ((originalBal >= 500) && (balance < 500))
		balance -= 5.00; //low balance fee

	return 0;
}

int Checking::deposit(double amt)
{
	if (amt < 0)
		return 1; //deposit should not be negative

	balance += amt;

	return 0;
}

void Checking::orderChecks()
{
	if ((balance - 15) < 0)
	{
		std::cout << "You must have at least $15.00 in your account to order checks." << std::endl;
		return; //cannot make account negative
	}
	else
	{
		balance -= 15;
		std::cout << "\n\nChecks were ordered. You were charged a $15.00 fee.\n\n" << std::endl;
		std::cout << "Your new balance is: $" << balance;
		return;
	}
}

