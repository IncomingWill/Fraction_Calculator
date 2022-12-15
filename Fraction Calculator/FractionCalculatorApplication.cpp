/*
Title: Chapter Thirteen Fraction Calculator Program -- Source File
Created by William Schaeffer
CPS 362
P. 1049, Challenge 3, Fraction Calculator Program, Week 7
03.03.2022
*/

//This program will demonstrate the updated Fraction Calculator Program with Division by Zero and Invalid Input Exceptions

#include <iostream>
#include "InvalidInputException.hpp"
#include "DivisionByZeroException.hpp"
#include "FracCalcFunctions.hpp"

using namespace std;

//Function Prototypes
void welcomeUser();										//to welcome user
int welcomeMenu();										//menu selection
int integerInput();										//to get integer and validate from the user for numerator
int integerDenomInput();									//to get integer and validate from the user for denominator
int gcd(int, int);										//calculate greatest common divisor
void reduce(int&, int&);									//reduce fraction
void addFractions(int, int, int, int, int*, int*);						//addition of fractions
void subtractFractions(int, int, int, int, int*, int*);						//subtraction of fractions
void multiplyFractions(int, int, int, int, int*, int*);						//multiplication of fractions

int main()
{
	char runAgain = 'Y';									//initialize variable to run program again, default to yes to start
	int menuSelection = 0;									//initialize menuSelection variable
	int denomOne = 0, denomTwo = 0, numerOne = 0, numerTwo = 0;				//initialize denominators and numerators
	int denomThree = 0, numerThree = 0;							//initialize integer pointers to hold arithmetic solution

	welcomeUser();										//call introduction function

	while (toupper(runAgain) == 'Y')							//while 'Y', run program, else quits

	{		
		menuSelection = welcomeMenu();

		if (menuSelection > 0 && menuSelection < 5)
		{

			cout << "You will now enter the fractions to perform operations on.\n"
				<< "Please only enter integers for the numerators and denominators.\n\n"
				<< "Enter the first numerator: ";
			numerOne = integerInput();

			cout << endl
				<< "Enter the first denominator: ";

			denomOne = integerDenomInput();

			cout << endl
				<< "Enter the second numerator: ";

			numerTwo = integerInput();

			cout << endl
				<< "Enter the second denominator: ";

			denomTwo = integerDenomInput();

			cout << endl;
		}

		if (menuSelection == 1)											//addition
		{
			cout << numerOne << "/" << denomOne << " + " << numerTwo << "/" << denomTwo << " = ";
			
			addFractions(numerOne, denomOne, numerTwo, denomTwo, &numerThree, &denomThree);
		}
		else if (menuSelection == 2)										//subtraction
		{
			cout << numerOne << "/" << denomOne << " - " << numerTwo << "/" << denomTwo << " = ";
			
			subtractFractions(numerOne, denomOne, numerTwo, denomTwo, &numerThree, &denomThree);
		}
		else if (menuSelection == 3)										//multiplication
		{
			cout << numerOne << "/" << denomOne << " * " << numerTwo << "/" << denomTwo << " = ";
			
			multiplyFractions(numerOne, denomOne, numerTwo, denomTwo, &numerThree, &denomThree);
		}
	//division by taking the reciprocal of numerTwo/denomTwo
		else if (menuSelection == 4)										//division
		{
			cout << numerOne << "/" << denomOne << " / " << numerTwo << "/" << denomTwo << " = ";
			
			multiplyFractions(numerOne, denomOne, denomTwo, numerTwo, &numerThree, &denomThree);
		}
		else if (menuSelection == 5)										//quit
		{
			runAgain = 'N';
		}

		if (menuSelection > 0 && menuSelection < 5)
		{
			cout << numerThree << " / " << denomThree << endl << endl;					//print the result
		}

	}

	cout << "Thank you for running the program." << endl << endl;

	return 0;
}
