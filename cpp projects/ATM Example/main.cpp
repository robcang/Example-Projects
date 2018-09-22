//------------------------------------------------------------------------------\\
//																				\\
// Author:			R. Mitchell Cangelosi										\\
// Description:		This program simulates the use of a real ATM.				\\
//																				\\
// File: main.cpp																\\
//------------------------------------------------------------------------------\\

#include "header.h"

int main()
{
	user current;
	cout << "Welcome to Mitch's ATM" << endl << endl;

	cout << "For this example the Account Number is 12345 and the PIN is 6789" << endl
		<< "You can also look in the text file 'accountexamples.txt' for more" << endl;


	int valAccNum, valAccPIN;

	// run the menu only if the account num and PIN are valid
	bool validComb = false;

	while (validComb != true)
	{
		// get the users account number
		valAccNum = current.getAccNum();

		// get the users PIN
		valAccPIN = current.getPIN();

		//check for a valid account and PIN combo
		validComb = current.validate(valAccNum, valAccPIN);

		cout << endl;
		if (validComb == false)
			cout << "Sorry no account matching that Account Number and PIN. Please try again..." << endl << endl;
	}

	// getting to the main menu if a valid combo
	if (validComb == true)
	{
		current.menu();
	}
	return 0;

}

// Thank you for looking at my code! Have a great day!