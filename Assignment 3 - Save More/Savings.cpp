#include "stdafx.h"
#include "Savings.h"
#include <iostream>


Savings::Savings(double intBalance) : BankAccount(intBalance)
{
	accountType = "Savings";
	updateInterestRate();
}

int Savings::withdrawal(double amt)
{
	if ((balance - 2) < amt)
	{
		std::cout << "There is a $2.00 fee for early withdrawal." << std::endl;
		return 1; //withdrawal should never make account negative
	}

	balance -= amt + 2;
	updateInterestRate();

	return 0;
}

int Savings::deposit(double amt)
{

	if (amt < 0)
		return 1; //deposit should never make account negative
	
	balance += amt;
	updateInterestRate();

	return 0;
}

void Savings::updateInterestRate()
{
	oldInterestRate = monthlyInterestRate;

	if (balance < 10000)
	{
		annualInterestRate = 0.01;
		monthlyInterestRate = 1 + (0.01 / 12); //compounded monthly
	}
	else if (balance >= 10000)
	{
		annualInterestRate = 0.02;
		monthlyInterestRate = 1 + (0.02 / 12); //compounded monthly
	}
	if (oldInterestRate != monthlyInterestRate)
		std::cout << "Your APR is now: " << annualInterestRate*100 <<"%"<< std::endl;
	return ;
}



