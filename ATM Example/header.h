//------------------------------------------------------------------------------\\
//																				\\
// Author:			R. Mitchell Cangelosi										\\
// Description:		This program simulates the use of a real ATM.				\\
//																				\\
// File: header.h																\\
//------------------------------------------------------------------------------\\

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class user {
	
public:
	user();
	int getAccNum();
	int getPIN();
	bool validate(int valAccNum, int valAccPIN);
	void menu();
	void showBalance();
	double deposit();
	double withdrawl();
	void exitProg();
	void print();

private:
	int accountNum;
	int PIN;
	double balance;
	double totalChange; // keeps track of the total change within a transaction at the ATM
		
};

// struct for validation
struct allAccData
{
	int allAccNumber;
	int allPINum;
	int allBalance;
	allAccData *next;
};

allAccData *dataImport();

// Thank you for looking at my code! Have a great day!