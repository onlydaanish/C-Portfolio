// Arithmatic Program.cpp : Defines the entry point for the console application.
// Manually Written by Daanish Bhamla
#include "stdafx.h"
#include <iostream>
using namespace std;
void CreateArithmaticSequence(double square[16]);
void CreateArithmaticSeries(double square[16]);
void FindSequenceDifference();
void FindSequenceTerm();
void FindTermAmount();
void FindSeriesSum();
int StartSequence();
int StartSeries();
int ContinueOrNo();
int main()
{
	int answer;
	cout << "Which of the following would you like to do?: \n" << 
			"1. Create Arithmatic Sequence \n" <<
			"2. Find the Difference of an Aritmatic Sequence or Series \n" <<
			"3. Find a Certain Term in a Aritmatic Sequence (Explict Forumla) \n" <<
			"4. Create Aritmatic Series \n" <<
			"5. Find number of Terms in Aritmatic Series \n" <<
			"6. Find the Sum of an Arithmatic Series \n";
	cin >> answer;
	switch (answer)
	{
		case 1:
			StartSequence();
		break;
		case 2:
			FindSequenceDifference();
		break;
		case 3:
			FindSequenceTerm();
		break;
		case 4:
			StartSeries();
		break;
		case 5:
			FindTermAmount();
		break;
		case 6:
			FindSeriesSum();
		break;
	}
	system("pause");
}

int ContinueOrNo()
{
	cout << "\n \nDo you want to quit? <Y/N>";
	char answer;
	cin >> answer;
	if (answer == 'N' || answer == 'n')
	{
		cout << "\n";
		main();
	}
	else if (answer == 'Y' || answer == 'y')
	{
		exit (1);
	}
	else
	{
		cout << "\n Invalid, Type in Y for Yes, or N for No";
		ContinueOrNo();
	}
	return 0;
}

int StartSequence()
{
double square[16];
CreateArithmaticSequence(square);
system("pause");
return 0;
}

void CreateArithmaticSequence(double square[16])
{
double diff;
int amount;
cout<<"Enter The First Number In The Arithmatic Sequence: ";
cin>> square[0];
cout<<"\nEnter The Difference In The Arithmatic Sequence: ";
cin>>diff;
cout << "\nNumber of Term's to Be Calculated: ";
cin >> amount;
cout<<"\nYour Arithmatic Sequence Goes As Follows: \n \n" << square[0] << ", ";

for(int i=1; i<amount;i++)
	{
	square[i] = square[i-1] + diff ;
	if (i == amount-1)
		{
		cout<< square[i];
		ContinueOrNo();
		}
	cout<< square[i] << ", ";
	}
}

void FindSequenceDifference()
{
	char yesno;
	double diff [1];
	double A[2];
	cout << "Enter the First term of the Sequence: ";
	cin >> A[0];
	cout << "Enter the 2nd term of the Sequence: ";
	cin >> A[1];
	Repeat:
	cout << "Do you have a 3rd Term? <y/n> ";
	cin >> yesno;
	if (yesno == 'Y' || yesno == 'y')
	{
		cout << "Enter the 3rd term of the Sequence: ";
		cin >> A[2];
		diff[0] = A[1] - A[0];
		diff[1] = A[2] - A[1];
		if (diff[0] == diff[1])
		{
			cout << "The Difference of your Sequence is: " << diff[0] << "\n \n";
			ContinueOrNo();
		}
		else
		{
			cout << "\nNo Common Difference between the 3 terms, Therefore it is not a arithmatic \nsequence";
			system("pause");
			ContinueOrNo();
		}
	}
	else if (yesno == 'N' || yesno == 'n')
	{
		diff[0] = A[1] - A[0];
		cout << "The Difference of your Sequence is: " << diff[0] << "\n \n";
		ContinueOrNo();		
	}
	else
	{
		cout << "\nInvalid Character Entered. Type Y for Yes, or N for No";
		system("pause");
		goto Repeat;
	}
}

void FindSequenceTerm()
{
	double term[1];
	double diff;
	double answer[1];
	cout << "First Term in your Sequence: ";
	cin >> term[0];
	cout << "What is the Common Difference: ";
	cin >> diff;
	cout << "What is the Term Your looking for: ";
	cin >> term[1];
	answer[0] = (term[1] - 1) *diff;
	answer[1] = term[0] + answer[0];
	cout << "Term " << term[1] << " In the Sequence is: " << answer[1] <<"\n";
	ContinueOrNo();
}

int StartSeries()
{
double square[16];
CreateArithmaticSeries(square);
system("pause");
return 0;
}

void CreateArithmaticSeries(double square[16])
{
double diff;
int amount;
cout<<"Enter The First Number In The Arithmatic Series: ";
cin>> square[0];
cout<<"\nEnter The Difference In The Arithmatic Series: ";
cin>>diff;
cout << "\nNumber of Term's to Be Calculated: ";
cin >> amount;
cout<<"\nYour Arithmatic Sequence Goes As Follows: \n \n" << square[0] << " + ";
for(int i=1; i<amount;i++)
	{
	square[i] = square[i-1] + diff ;
	if (i == amount-1)
		{
		cout << square[i];
		ContinueOrNo();	
		}
	cout<< square[i] << " + ";	
	}
}

void FindTermAmount()
{
	double terms[1];
	double diff;
	double X;
	double answer;
	cout << "Enter the First term in The Aritmatic Series: ";
	cin >> terms[0];
	cout << "Enter the Last term in the Arithmatic Series: ";
	cin >> terms[1];
	cout << "Enter the Difference of the Aritmatic Series: ";
	cin >> diff;
	X = terms[0] - diff;
	answer = (terms[1] - X) / diff;
	cout << "\nThere are " << answer << " Terms in your Series";
	ContinueOrNo();
}

void FindSeriesSum()
{
	double term[2];
	double answer;
	cout << "What is the First term in Your Series: ";
	cin >> term[0];
	cout << "What is the Last term in your Series: ";
	cin >> term[1];
	cout << "How many terms are in your series: ";
	cin >> term[2];
	answer = ((term[0] + term[1]) / 2) * term[2];
	cout << "\nThe sum of your Series is: " << answer;
	ContinueOrNo();
}