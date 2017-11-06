// Assignment3SaveMore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "BankAccount.h"
#include "Checking.h"
#include "Savings.h"
#include "Certificate.h"

static int LISTSIZE = 50;

int main()
{
	//set cout defaults
	std::cout.setf(std::ios::fixed);
	std::cout.precision(2);

	double amt;
	int yrs;
	int choice;
	char again ='y';
	char validEntry = 'y';
	int acctNum = 1000;
	int currentAcctNum;

	BankAccount **bankAccountList;
	bankAccountList = new BankAccount*[LISTSIZE]; //dynamically allocate list

	//test cases
	bankAccountList[acctNum] = new Savings(10000);
	bankAccountList[++acctNum] = new Checking(6000);
	bankAccountList[++acctNum] = new Certificate(10000, 3);

	bankAccountList[1000]->assessInterest();
	bankAccountList[1002]->assessInterest();
	bankAccountList[1001]->orderChecks();

	std::cout << "\n\nAcct #\tOpen Date\tAPR\tBalance\t\tType" << std::endl;
	bankAccountList[1000]->listInfo();
	bankAccountList[1001]->listInfo();
	bankAccountList[1002]->listInfo();

	bankAccountList[1001]->withdrawal(200);
	bankAccountList[1000]->withdrawal(1000);
	bankAccountList[1002]->withdrawal(2000);

	std::cout << "\n\nAcct #\tOpen Date\tAPR\tBalance\t\tType" << std::endl;
	bankAccountList[1000]->listInfo();
	bankAccountList[1001]->listInfo();
	bankAccountList[1002]->listInfo();

	acctNum++;

	//main menu
	do
	{
		std::cout << "\n\n************MENU************" << std::endl;
		std::cout << "            ----            " << std::endl;
		std::cout << "1.Create new account\n2.Deposit\n3.Withdrawal\n4.View specific account details";
		std::cout << "\n5.List all accounts\n6.Exit\n\n";
		std::cout << "Enter choice no.: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
		{
			//new account type
			system("cls");
			std::cout << "\n\n************NEW ACCOUNT*************" << std::endl;
			std::cout << "1.Checking\n2.Savings\n3.Certificate\n\n" << std::endl;

			std::cout << "Enter choice no.: ";
			std::cin >> choice;

			//opening balance
			system("cls");
			std::cout << "\n\n************NEW ACCOUNT*************" << std::endl;

			std::cout << "\nEnter opening balance: ";
			std::cin >> amt;
			
			//create new account
			switch (choice)
			{
			case 1:
			{				
				bankAccountList[acctNum] = new Checking(amt);
				break;
			}
			case 2:
			{				
				bankAccountList[acctNum] = new Savings(amt);
				break;
			}
			case 3:
			{
				std::cout << "Enter years: ";
				std::cin >> yrs;

				bankAccountList[acctNum] = new Certificate(amt, yrs);
				break;
			}
			}
			//show new account info
			bankAccountList[acctNum]->displayInfo();
			acctNum++;
			break;
		}
		case 2:
		{
			system("cls");
			std::cout << "\n\n************DEPOSIT*************" << std::endl;

			do
			{
				std::cout << "Enter account no.: ";
				std::cin >> currentAcctNum;
				
			} while ((currentAcctNum > acctNum - 1) || (currentAcctNum < 1000)); //check if acct valid

			std::cout << "Enter deposit amount: ";
			std::cin >> amt;
			
			if (bankAccountList[currentAcctNum]->deposit(amt) == 0) //success
			{
				std::cout << "\n\nDeposit success.\nYou deposited: " << amt;
				std::cout << " and your new balance is: ";
				std::cout << bankAccountList[currentAcctNum]->getBalance() << std::endl;
			}
			else
				std::cout << "\n\Deposit was not successful. Please try again." << std::endl;

			break;
		}
		case 3:
		{
			system("cls");
			std::cout << "\n\n**********WITHDRAWAL***********" << std::endl;

			do
			{
				std::cout << "Enter account no.: ";
				std::cin >> currentAcctNum;

			} while ((currentAcctNum > acctNum - 1) || (currentAcctNum < 1000)); //check if acct valid

			std::cout << "Enter withdrawal amount: ";
			std::cin >> amt;

			if (bankAccountList[currentAcctNum]->withdrawal(amt) == 0) //success
			{
				std::cout << "\n\nWithdrawal success.\nYou withdrew: " << amt;
				std::cout << " and your new balance is: ";
			}
			else
			{
				std::cout << "\n\nWithdrawal was not successful due to insufficient funds." << std::endl;
				std::cout << "Your available balance is: ";
			}
			//show balance
			std::cout << bankAccountList[currentAcctNum]->getBalance() << std::endl;
			
			break;
		}
		case 4:
		{
			do
			{
				std::cout << "Enter account no.: ";
				std::cin >> currentAcctNum;

			} while ((currentAcctNum > acctNum - 1) || (currentAcctNum < 1000)); //check if acct valid

			system("cls");

			bankAccountList[currentAcctNum]->displayInfo();
			break;
		}
		case 5:
		{
			system("cls");
			std::cout << "\n\n**********MASTER ACCOUNT LIST***********" << std::endl;
			std::cout << "Acct #\tOpen Date\tAPR\tBalance\t\tType" << std::endl;

			for (int i = 1000; i < acctNum; i++)
			{
				bankAccountList[i]->listInfo();
			}
			
			break;
		}
		case 6:
		{
			again = 'n';
			
			break;
		}
		default:
		{
			system("cls");
			std::cout << "\n\nEntered choice is invalid,\"TRY AGAIN\"";
			std::cin.clear();
			std::cin.ignore();
		}
		}

		if (again != 'n')
		{
			std::cout << "\n\nPress enter to return to menu." << std::endl;
			std::cin.get();
			std::cin.get();
			system("cls");
		}

	} while (again == 'y');

	// cleanup
	for (int i = 1000; i < acctNum; i++)
	{
		delete bankAccountList[i];
	}

	delete bankAccountList;

    return 0;
}

