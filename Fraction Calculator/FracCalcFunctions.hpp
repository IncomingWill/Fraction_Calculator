#pragma once

#ifndef H_FracCalcFunctions
#define H_FracCalcFunctions

//Function Definitions

//Introduce User to Program

void welcomeUser()
{
	cout << "\tWelcome to the Fraction Calculator Program.\n\n"
		<< "You will be given 5 menu selections to perform one of four different\n"
		<< "mathematical operations or quit to program. After making your menu selection\n"
		<< "you will enter the numerator and denominator for two different fractions. \n\n";
}

//Menu Selection
	//first example of invalid input exception

int welcomeMenu()
{
	int selection = 0;

	cout << "(1) Addition\n\n";
	cout << "(2) Subtraction\n\n";
	cout << "(3) Multiplication\n\n";
	cout << "(4) Division\n\n";
	cout << "(5) Quit\n\n";

	cout << "Please enter the menu's corresponding integer to select mathematical operation:\n\n";
	
	try
	{
		cin >> selection;

		if (!cin)
			throw invalidInputException();
		else if(selection > 5 || selection < 1)
			throw selection;
	}
	catch (invalidInputException invalid)
	{
		cout << invalid.what() << endl << endl;
		cin.clear();
		cin.ignore(100, '\n');
	}
	catch (int selection)
	{
		cout << "Invalid menu selection.\n"
			<< "Clearing the input...\n\n";
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Restarting menu..." << endl << endl;
	}

	return selection;
}

//Function to get Numerator input
	//example of fix the error and continue

int integerInput()
{
	char str[] = "\nThe input stream is in the fail state.\n\n";
	int number = 0;
	bool done = false;
	
	do
	{
		try
		{
			cin >> number;

			if (!cin)
				throw str;
			else if (number == 0)
				throw divisionByZeroException("Numerator");
			done = true;
		}
		catch (const char messageStr[])
		{
			cout << messageStr;
			cout << "Restoring the input stream." << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please re-enter the numerator integer: ";
		}
		catch (divisionByZeroException zero)
		{
			cout << zero.what() << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please re-enter the numerator non-zero integer: ";
		}
	} while (!done);

	return number;
}

//Function to get Numerator input
	//try/catch invalid input & DivisionByZero

int integerDenomInput()
{
	int number = 0;
	bool done = false;

	do
	{
		try
		{
			cin >> number;

			if (!cin)
				throw invalidInputException();
			else if (number == 0)
				throw divisionByZeroException("Denominator");
			done = true;
		}
		catch (invalidInputException invalid)
		{
			cout << invalid.what() << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
		catch (divisionByZeroException zero)
		{
			cout << zero.what() << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please re-enter the denominator non-zero integer: ";
		}
	} while (!done);

	return number;
}

//Function to calculate Greastest Common Divisor for addition and subtraction
	//used for LCM and reducing the final fraction

int gcd(int num1, int num2)
{
	if (num1 == 0)
		return num2;
	return gcd(num2 % num1, num1);
}

//Function to reduce the final fraction
	//find common factor, then convert into simpler terms by dividing each
	//pass by reference so we don't have to return

void reduce(int& num, int& den)
{
	int factor = gcd(num, den);

	num = num / factor;
	den = den / factor;
}

//Function to add fractions
	//calculate greatest common divisor
	//calculate least common multiple
	//calculate numerator (think cross multiplication trick)
	//give num3 and den3 pointer values to pass to main() without return
	//d = divisor/denominator, n = numerator

void addFractions(int num1, int den1, int num2, int den2, int* num3, int* den3)
{
	int d = gcd(den1, den2);									//calculate gcd

	d = (den1 * den2) / d;										//calculate lcm

	int n = (num1 * (d / den1)) + (num2 * (d / den2));						//calculate numerator

	reduce(n, d);											//reduce fraction

	*num3 = n;											//store in pointer to return multiple values
	*den3 = d;
}

//Function to subtract fractions
	//works the same as addition, just swap the (+) operator for (-) operator

void subtractFractions(int num1, int den1, int num2, int den2, int* num3, int* den3)
{
	int d = gcd(den1, den2);									//calculate gcd

	d = (den1 * den2) / d;										//calculate lcm

	int n = (num1 * (d / den1)) - (num2 * (d / den2));						//calculate numerator

	reduce(n, d);

	*num3 = n;
	*den3 = d;
}

//Function to multiply fractions
	//calculate product of numerators
	//calculate product of denominators
	//simplify and give to pointers
		//division simulated by taking reciprocal of num2/den2
		//parameter 3 and 4 are swapped in the main() function call of multiplyFractions()

void multiplyFractions(int num1, int den1, int num2, int den2, int* num3, int* den3)
{
	int n = num1 * num2;										//calculate numerator
	int d = den1 * den2;										//calculate denominator

	reduce(n, d);

	*num3 = n;
	*den3 = d;
}


#endif
