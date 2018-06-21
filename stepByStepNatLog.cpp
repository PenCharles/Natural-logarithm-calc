#include <iostream>							//for I/O
#include <iomanip>							//for formattung output
#include <cstdlib>							//for process control functions
#include <cctype>							//for user defined functions
#include <cmath>							//for pre defined mathfunctions
#include <string>							//for string variables
using namespace std;

	//Author: James Saylor
	//Description : This program will provide a step by step display of each 
	//				calculation of the natural logarithm of 2

//function prototype
int UserInput (string statement);
double ResultDisplay (int num, int step);

int main ()
{
	//local variables
	int validNum;
	int validStep;
	double finalValue;
	string userPrompt = "Please enter a positive, non-zero value: ";
	
	cout << "This program will prompt the user to enter two numbers to help"
		 << " calculate the natural logarithm of 2 using fractions." << endl;
	
	validNum = UserInput (userPrompt);
	validStep = UserInput (userPrompt);
	finalValue = ResultDisplay (validNum, validStep);
	
	cout << endl << "Finally, after" << endl;
	cout << setw(2) << validNum << " steps:  ln(2) = " << finalValue << endl;

 	cout << endl << endl;
 	return 0;
}

int UserInput (string statement)
{
	int value;
	
	do 
	{
		cout << statement;
		cin >> value;
		cout << endl;
		if (value <= 0)
		{
			cout << "Error. Please enter a positive, non-zero value" << endl;
		}
	}
	while (value <= 0);
	
	return value;
}

double ResultDisplay (int num, int step)
{
	double counter;
	int stepList = 0;
	int stepCounter = 0;
	double logResult = 0;
	bool b1 = true;
	
	cout << "RESULTS at:" << endl;
	for (counter = 1; counter <= num; counter++)
	{
		if (b1 == true)
		{
			logResult = logResult + (1/counter);
			b1 = false;	
			stepCounter++;
			stepList++; 
		}
		else
		{
			logResult = logResult - (1/counter);
			b1 = true;
			stepCounter++;
			stepList++; 
		}
		while (stepCounter == step)
		{
			cout << setw(2) << stepList << " steps:  ln(2) = " << logResult;
			cout << endl;
			stepCounter = 0;
		}
	}
	
	return logResult;
}
