#include "stdafx.h"
#include "BankAccount.h"
#include <iostream>
#include <stdio.h>
#include <ctime>


int BankAccount::accountNumberGenerator = 1000;


BankAccount::BankAccount(double intBalance)
{
	accountNumber = accountNumberGenerator++;
	balance = intBalance;
	setOpenDate();	
}

void BankAccount::displayInfo()
{
	std::cout << "\n\n**********************************" << std::endl;
	std::cout << "\tAccount Information" << std::endl;
	std::cout << "**********************************" << std::endl;
	std::cout << "Account Type:\t\t " << accountType << std::endl;
	std::cout << "Account Number:\t\t " << accountNumber << std::endl;
	std::cout << "Open Date:\t\t " << openDate << std::endl;
	std::cout << "Current Balance:\t $" << balance << std::endl;
	std::cout << "APR:\t\t\t " << annualInterestRate * 100 << "%" << std::endl;
}

void BankAccount::listInfo()
{
	std::cout << accountNumber << "\t" << openDate << "\t" << annualInterestRate*100;
	std::cout << "%\t$" << balance << "\t" << accountType << std::endl;
}

double BankAccount::getBalance()
{
	return balance;
}

void BankAccount::setOpenDate()
{
	time_t rawtime;
	struct tm timeinfo;

	time(&rawtime);
	localtime_s(&timeinfo,&rawtime);

	strftime(openDate, 11, "%m/%d/%Y", &timeinfo);
}

void BankAccount::assessInterest()
{
	intAmt = balance * (monthlyInterestRate - 1);
	balance *= monthlyInterestRate;
	std::cout << "\n\nMonthly interest assessed in the amount of $" << intAmt << std::endl;
	std::cout << "Your new balance is $" << balance << std::endl;
}

void BankAccount::orderChecks()
{
	std::cout << "Checks cannot be ordered for this account type." << std::endl;
}