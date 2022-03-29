/*
Title: Chapter Thirteen Fraction Calculator Program -- DivisionByZeroException Class
Created by William Schaeffer
CPS 362
P. 1049, Challenge 3, Fraction Calculator Program, Week 7
03.03.2022
*/

#pragma once

#ifndef H_divisionByZeroException
#define H_divisionByZeroException

#include <iostream> 
#include <string> 

using namespace std;

class divisionByZeroException
{                       
public:   
    divisionByZeroException()
    { 
        message = "Division by zero not allowed.";
    } 

    divisionByZeroException(string str)
    {
        message = str + " cannot be zero";
    }

    string what() 
    { 
        return message;
    }   

private:
    string message;
};

#endif