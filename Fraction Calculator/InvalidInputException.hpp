/*
Title: Chapter Thirteen Fraction Calculator Program -- InvalidInputException Class
Created by William Schaeffer
CPS 362
P. 1049, Challenge 3, Fraction Calculator Program, Week 7
03.03.2022
*/

#pragma once

#ifndef H_invalidInputException
#define H_invalidInputException

#include <iostream> 
#include <string> 

using namespace std;

class invalidInputException
{
public:
	invalidInputException()
	{
		message = "Invalid input.";
	}

	invalidInputException(string str)
	{
		message = str;
	}

	string what()
	{
		return message;
	}

private:
	string message;
};

#endif