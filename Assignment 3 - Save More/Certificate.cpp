#include "stdafx.h"
#include "Certificate.h"
#include <iostream>


int Certificate::TERM;

Certificate::Certificate(double intBalance, int years) : BankAccount(intBalance)
{
	accountType = "Certificate";
	TERM = years;
	
	if (TERM == 5)
	{
		monthlyInterestRate = 1 + (0.10 / 12);
		annualInterestRate = 0.10;
	}
	else if (TERM < 5)
	{
		monthlyInterestRate = 1 + (0.05 / 12);
		annualInterestRate = 0.05;
	}
	else
	{
		monthlyInterestRate = 1;
		annualInterestRate = 0;
	}
}

int Certificate::withdrawal(double amt)
{
	fee = balance*0.1;
	
	if (TERM > 0)
	{
		
		if (balance - amt - fee < 0)
			return 1; //withdrawal cannot make account negative
		else
			balance = balance - amt - fee; // 10% fee for early withdrawal
	}
	else
	{
		balance -= amt;
	}

	if (TERM > 0)
		std::cout << "You were charged a fee of: " << fee << std::endl;
	
	return 0;
}

int Certificate::deposit(double amt)
{
	if (amt < 0)
		return 1; //deposit should not be negative

	balance += amt;

	return 0;
}

void Certificate::displayInfo()
{
	std::cout << "\n\n**********************************" << std::endl;
	std::cout << "\tAccount Information" << std::endl;
	std::cout << "**********************************" << std::endl;
	std::cout << "Account Type:\t\t " << accountType << std::endl;
	std::cout << "Account Number:\t\t " << accountNumber << std::endl;
	std::cout << "Open Date:\t\t " << openDate << std::endl;
	std::cout << "Current Balance:\t $" << balance << std::endl;
	std::cout << "Term:\t\t\t " << TERM << std::endl;
	std::cout << "APR:\t\t\t " << annualInterestRate*100 << "%" << std::endl;
}





