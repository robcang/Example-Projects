//------------------------------------------------------------------------------\\
//																				\\
// Author:			R. Mitchell Cangelosi										\\
// Description:		This program simulates the use of a real ATM.				\\
//																				\\
// File: implementation.cpp														\\
//----------------------------------------------------------------------------- \\

#include "header.h"

user::user()
{
	accountNum = NULL;
	PIN = NULL;
	balance = NULL;
}

int user::getAccNum()
{
	int getAccountNum;

	// get the users account number
	cout << endl;
	cout << "Please enter your account number: ";
	cin >> getAccountNum;
	
	return getAccountNum;
}

int user::getPIN()
{
	int getPIN;

	// get the users PIN
	cout << endl;
	cout << "Please enter your PIN: ";
	cin >> getPIN;

	return getPIN;
}

bool user::validate(int valAccNum, int valAccPIN)
{

	allAccData *list = dataImport();

	// while the list exists we will check through the list of accounts
	while (list)
	{
		int accNumCheck = list->allAccNumber;
		int accPINCheck = list->allPINum;

		if (valAccNum == accNumCheck)
		{
			if (valAccPIN == accPINCheck)
				balance = list->allBalance;
				accountNum = accNumCheck;
				PIN = accPINCheck;
				return true;
		}
		list = list->next;
			
	}
	return false;

	//Not returning anything here so the program closes if the list doesnt exist
}

allAccData *dataImport()
{

	allAccData *list, *head;
	allAccData *x, *z;

	// Gathering account information from text file (this part could be connected to a server but for the example I am using a file)
	ifstream inFile;
	list = NULL;
	x = new allAccData;
	// opening the file containing the data
	inFile.open("accountexamples.txt");

	// importing file info into the struct
	while (!inFile.eof())
	{
		x = new allAccData;
		inFile >> x->allAccNumber;
		inFile >> x->allPINum;
		inFile >> x->allBalance;
		x->next = NULL;

		if (list == NULL)
		{
			list = x;
			head = x;
		}
		else
		{
			z = list;

			while (z->next != NULL)
				z = z->next;
			z->next = x;
		}
	}

	//closing the file
	inFile.close();

	return head;

}

void user::menu()
{
	int choice = -1;

	while (choice = -1)
	{
		cout << "Welcome to the Main Menu" << endl
			<< "Enter 1 to show balance" << endl
			<< "Enter 2 to make a deposit" << endl
			<< "Enter 3 to make a withdrawl" << endl
			<< "Enter 4 to exit" << endl << endl // exit gives you the option to print a receipt
			<< "Your Choice: ";
		cin >> choice;
		cout << endl;

		if (choice == 1)
		{
			showBalance();
		}
		else if (choice == 2)
		{
			totalChange += deposit();
		}
		else if (choice == 3)
		{
			totalChange -= withdrawl();
		}
		else if (choice == 4)
		{
			exitProg();
		}
	}

}

void user::showBalance()
{
	cout << endl
		<< "------------------------------" << endl
		<< "Current Balance: $" << balance << endl
		<< "------------------------------" << endl << endl;

	menu();
}

double user::deposit()
{
	double amount;

	cout << "------------------------------" << endl;
	cout << "Enter the amount you would like to deposit" << endl
		<< "(enter 0 to return to the menu)" << endl
		<< "Amount: $";
	cin >> amount;
	cout << "------------------------------" << endl << endl;

	if (amount < 0)
	{
		cout << "You can't deposit a negative. Returning to the main menu" << endl << endl;
		menu();
	}
	else
	{
		cout << endl;

		balance += amount;

		return amount;
	}
	
}

double user::withdrawl()
{
	double amount = -1;

	while (amount <= -1)
	{
		cout << "------------------------------" << endl;
		cout << "Enter the amount you would like to withdrawl" << endl
			<< "(enter 0 to return to the menu)" << endl
			<< "Amount: -$";
		cin >> amount;
		cout << "------------------------------" << endl << endl;

		if (amount < 0)
		{
			cout << "Please re enter without a negative sign" << endl << endl;
			amount = -1;
		}

		if (amount > balance)
		{
			cout << "Amount exceeds your balance. Enter a diffirent amount" << endl << endl;
			amount = -1;
		}
	}
		cout << endl;

		balance -= amount;

		return amount;
}

void user::exitProg()
{
	cout << "------------------------------" << endl;
	string choice;

	cout << "Would you like to print a receipt?" << endl
		<< "(enter y or n)" << endl
		<< "Your Choice: ";
	cin >> choice; //using cin instead of getline because of 1 char response.
	cout << "------------------------------" << endl << endl;

	if (choice == "y" || choice == "Y")
	{
		print();
	}
	else
		cout << "Thank You!" << endl;
		system("pause");
		exit(0);

}

void user::print()
{
	cout << "------------------------------" << endl
		<< "Printed Receipt: " << endl << endl;

	cout << "Account Number: " << accountNum << endl << endl
		<< "Previouse Balance: ";
	
	if (totalChange >= 0)
		cout << (balance - totalChange) << endl << endl;
	else
		cout << (totalChange * -1) + balance << endl << endl;

	cout << "Current Balance: " << balance << endl << endl
		<< "Thank You for Using Mitch's ATM!" << endl;

	cout << "------------------------------" << endl << endl;
	system("pause");
	exit(0);
	// ALL VALUES RESET FOR EXAMPLE PURPOSES!
}

// Thank you for looking at my code! Have a great day!