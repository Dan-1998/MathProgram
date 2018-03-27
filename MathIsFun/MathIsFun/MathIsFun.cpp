// MathIsFun.cpp : main project file.
//Programmed by Daniel Rozhanskiy

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include "windows.h"
#include <io.h>
#include <fcntl.h>
#include <fstream>

using namespace std;

struct ArraySort		//struct req
{
	enum size { sizeOf = 10 };		//enum req
};

class AbstractClass
{
public:

	AbstractClass()		//constructor req
	{

	}

	virtual void function() = 0;		//abstract req

	~AbstractClass()		//destructor req
	{

	}
};

class DerivedClass
{
public:

	void function()
	{
		cout << "\tThis program will demonstrate Calculus and Discrete concepts" << endl;
	}

	void trigTriangle()
	{
		double adj, hyp;
		float deg;

		cout << "\n\tLet's find the length of the hypotenuse of a right triangle" << endl;
		cout << "\n\tAdjacent length: ";
		cin >> adj;

		while (!cin.good())		//Error Check req
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter valid input: ";
			cin >> adj;
		}

		while (adj < 0)
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter input in valid range: ";
			cin >> adj;
		}

		cout << "\n\tAngle (degrees): ";
		cin >> deg;

		while (!cin.good())
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter valid input: ";
			cin >> deg;
		}

		while (deg < 0 || deg > 360)
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter input in valid range: ";
			cin >> deg;
		}

		deg = deg * 3.14 / 180;		//This converts degrees (which is common use), to radians, which is what the pow function uses

		hyp = adj / cos(deg);		//more mathematical library functions req

		cout << "\n\tHypotenuse: " << fixed << showpoint << setprecision(2) << hyp << " units long" << endl;
	}
};

class Math		//base class req
{
	virtual void derivative()
	{
		cout << "Derivatives tend to be taught in Calc I" << endl;
		cout << "Partial Derivatives tend to be taught in Calc III" << endl;
	}

	virtual void integral()
	{
		cout << "Integration tends to be taught in Calc I" << endl;
		cout << "Integration by parts tend to be taught in Calc II" << endl;
	}	
};

class Calculus : public Math
{

public:

	float co, co2;
	int power, power2, request = 0;

	friend void Menu();		//friend req

	void normalDerivative()
	{		
		cout << "\n\tWhat order of derivatives would you like to take? \n\t(i.e. 1st derivative, 2nd derivative, 3rd derivative): ";
		cin >> request;

		while (!cin.good())		//Error Check req
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter valid input: ";
			cin >> request;
		}

		while (request > 3 || request < 1)
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter input in valid range: ";
			cin >> request;
		}

		cout << "\n\tWe find the derivative of an algebraic function with the formula " << endl;
		cout << "\t(c*n)x^(n-1). Let's Check it out!!" << endl;
		cout << "\n\tWhat coefficient of x would you like to use? (i.e. 2x, 3x, etc.): ";
		cin >> co;

		while (!cin.good())		//Error Check req
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter valid input: ";
			cin >> co;
		}

		cout << "\tWhat power would you like to raise it to? (i.e. x^1, x^2, etc.): ";
		cin >> power;

		while (!cin.good())		//Error Check req
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter valid input: ";
			cin >> power;
		}

		cout << "\n\tf(x) = " << co << "x^" << power << "  ------  Original Function"<< endl;
			
				co = co * power;		//calculates the derivative
				power--;

				cout << "\tf'(x) = " << co << "x^" << power <<  "  ------  1st Derivative" << endl;

				if (request == 2 || request == 3)		//if request is 3, still should display second derivative
				{
					co = co * power;
					power--;

					cout << "\tf''(x) = " << co << "x^" << power << "  ------  2nd Derivative" << endl;
				}

				if (request == 3)
				{
					co = co * power;
					power--;

					cout << "\tf'''(x) = " << co << "x^" << power << "  ------  3rd Derivative" << endl;
				}
	}

	void partialDerivative()
	{
		char partialChoice;

		bool partialX = false;		//Bool Req
		bool partialY = false;

		cout << "\n\tWe will demonstrate partial derivatives by ";
		cout << "\n\tholding one variable constant and deriving the other. \n\tLet's Check it out!!" << endl;
		cout << "\n\tPlease Enter coefficient for x: ";
		cin >> co;

		while (!cin.good())		//Error Check req
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter valid input: ";
			cin >> co;
		}

		cout << endl;

		cout << "\n\tPlease Enter power for x: ";
		cin >> power;

		while (!cin.good())		//Error Check req
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter valid input: ";
			cin >> power;
		}

		cout << endl;

		cout << "\n\tPlease Enter coefficient for y: ";
		cin >> co2;

		while (!cin.good())		//Error Check req
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter valid input: ";
			cin >> co2;
		}

		cout << endl;

		cout << "\n\tPlease Enter power for y: ";
		cin >> power2;

		while (!cin.good())		//Error Check req
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter valid input: ";
			cin >> power2;
		}

		cout << endl;

		cout << "\tf(x,y) = " << co << "x^" << power << " * " << co2 << "y^" << power2 << endl;

		cout << "\n\tPress X for partial w/ respect to x (d/dx) or \n\tPress Y for partial w/ respect to y (d/dy) or Press B for both: ";
		cin >> partialChoice;

		while (!cin.good())		//Error Check req
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter valid input: ";
			cin >> partialChoice;
		}

		partialChoice = toupper(partialChoice);		//capitalizes input

		while (partialChoice != 'Y' && partialChoice != 'N' && partialChoice != 'B')
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter input in valid range: ";
			cin >> partialChoice;
		}

		if (partialChoice == 'X')
		{
			partialX = true;
		}
		else if (partialChoice == 'Y')
		{
			partialY = true;
		}
		else if (partialChoice == 'B')
		{
			partialX = true;
			
			partialY = true;
		}
		
		if (partialX)
		{
			float x = co * power;		//takes derivative of x and leaves y alone

			power = power--;

			cout << "\n\td/dx = " << x << "x^" << power << " * " << co2 << "y^" << power2 << endl;

			power++;		//this prevents (strange error) when partialChoice == 'B' 
		}

		if (partialY)
		{			
			float y = co2 * power2;		//takes derivative of y and leaves x alone
			
			power2 = power2--;

			cout << "\n\td/dy = " << co << "x^" << power << " * " << y << "y^" << power2 << endl;
		}
	}

	void derivative() 
	{
		int derivChoice;

		cout << "\n\tPress 1 for normal derivative, or 2 for partial derivative: ";
		cin >> derivChoice;

		while (!cin.good())		//Error Check req
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter valid input: ";
			cin >> derivChoice;
		}

		while (derivChoice > 2 || derivChoice < 1)
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter input in valid range: ";
			cin >> derivChoice;
		}

		if (derivChoice == 1)
		{
			normalDerivative();
		}

		else if (derivChoice == 2)
		{
			partialDerivative();
		}
	}

	void normalIntegral()
	{
		cout << "\n\tWe take the integral (area under the curve)";
		cout << "\n\tof a single term algebraic function with the formula" << endl;
		cout << "\n\t(1/n)*x^(n+1). Let's Try it!" << endl;
		cout << "\n\tWhat coefficient of x would you like to use? (i.e. 2x, 3x, etc.): ";
		cin >> co;

		while (!cin.good())		//Error Check req
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter valid input: ";
			cin >> co;
		}

		cout << "\n\tWhat power would you like to raise it to? (i.e. x^1, x^2, etc.): ";
		cin >> power;

		while (!cin.good())		//Error Check req
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter valid input: ";
			cin >> power;
		}


		cout << "\n\tf(x) = " << co << "x^" << power << endl;
		cout << "\n\tArea under curve";
		cout << " " << co << "x^" << power << " = ";
		co = (co / (power + 1));
		power++;
		cout << fixed << left << showpoint << setprecision(2) << co << "x^" << power << " + C" <<  endl;		//manipulator req
	}
	
	void definiteIntegral()
	{
		double lower, upper, area;

		cout << "\n\tWe take the integral (area under the curve)";
		cout << "\n\tof a single term algebraic function with the formula" << endl;
		cout << "\n\t(1/n)*x^(n+1). Let's Try it!" << endl;
		cout << "\n\tWhat coefficient of x would you like to use? (i.e. 2x, 3x, etc.): ";
		cin >> co;

		while (!cin.good())		//Error Check req
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter valid input: ";
			cin >> co;
		}

		cout << "\n\tWhat power would you like to raise it to? (i.e. x^1, x^2, etc.): ";
		cin >> power;

		while (!cin.good())		//Error Check req
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter valid input: ";
			cin >> power;
		}

		cout << "\n\tf(x) = " << co << "x^" << power << endl;
		cout << "\n\tUpper bound: ";

		cin >> upper;

		while (!cin.good())		//Error Check req
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter valid input: ";
			cin >> upper;
		}

		while (request < 0)
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter input in valid range: ";
			cin >> upper;
		}

		cout << endl << "\tLower bound: ";
		cin >> lower;
		
		while (!cin.good())		//Error Check req
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter valid input: ";
			cin >> lower;
		}

		while (lower < 0)
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter input in valid range: ";
			cin >> lower;
		}

		while (lower >= upper)
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tLower Bound must be less than upper bound " << endl << "\tto get non-zero positive value. Lower: ";
			cin >> lower;
		}

		co = (co / (power + 1));		//finds derivative
		power++;

		area = (co * pow(upper, power)) - (co * pow(lower,power));		//based off of FTC Part II

		cout << "\n\tThe Area under the curve is: " << fixed << showpoint << setprecision(2) << area << endl;
	}

	void integral()
	{
		int integChoice;

		cout << "\n\tPress 1 for Indefinite Integral, or 2 for Definite Integral: ";
		cin >> integChoice;

		while (!cin.good())		//Error Check req
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter valid input: ";
			cin >> integChoice;
		}

		while (integChoice > 2 || integChoice < 1)
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter input in valid range: ";
			cin >> integChoice;
		}

		if (integChoice == 1)
		{
			normalIntegral();
		}

		else if (integChoice == 2)
		{
			definiteIntegral();
			
		}		
	}
};
	
class Discrete : public Math
{

public:

	friend void Menu();		//friend req
	
	void truthTable()
	{
		
		
		cout << "\n\tTruth table for the statement: p implies not q" << endl;
		cout << "\n\tWe determine (T/F) with the understanding that" << endl;
		cout << "\ta True premise cannot imply a false conclusion..." << endl;
		
		cout << "\n\t\tP\t\tQ\t      not Q\t  p implies not q" << endl;
		cout << "\t\t-\t\t-\t      -----\t  ---------------" << endl;
		cout << "\t\tT\t\tT\t\tF\t\tF" << endl;
		cout << "\t\tT\t\tF\t\tT\t\tT" << endl;
		cout << "\t\tF\t\tT\t\tF\t\tT" << endl;
		cout << "\t\tF\t\tF\t\tT\t\tT" << endl;
	}
};

void displayHeader();
void displayMenu();
void displayQuickSort();
void displayBinarySearch();
void screenGreeting();
void quickSort(vector<int>&, int, int);
int partition(vector<int>&, int, int);
int binarySearch(const int sorted[], int, int, int);
void startingOver();

int choice, subChoice;

int main()
{
	screenGreeting();
	displayHeader();
	displayMenu();
	Menu();

	cout << "\n\tThank you for participating, press any key to exit" << endl;
	
	cin.ignore();
	cin.get();

    return 0;
}

void displayHeader()
{
	DerivedClass *obj;		//pointers to class objects req

	cout << "\n\tWelcome to the demonstration program 'Math is Fun'" << endl;
	obj->function();
	cout << "\tYou will choose to explore Calculus or Discrete Math" << endl;
}

void displayMenu()
{
	cout << "\n\tPress 1 for Calculus" << endl;
	cout << "\tPress 2 for Discrete Math" << endl;
	cout << "\tPress 3 for Trigonometry" << endl;
	cout << "\tPress 0 to Exit" << endl;
	cout << "\n\tChoice: ";
}

void Menu()
{	
	cin >> choice;
	
	while (!cin.good())		//Error Check req
	{
		cin.clear();
		cin.ignore();
		cout << "\n\n\tPlease Enter valid input: ";
		cin >> choice;
	}

	while (choice < 0 || choice > 3)
	{
		cin.clear();
		cin.ignore();
		cout << "\n\n\tPlease Enter input in valid range: ";
		cin >> choice;
	}

	if (choice == 0)
	{

	}

	else if (choice == 1)
	{
		Calculus calcObj;		//creates Calc Object

		cout << "\n\tPress 1 for Derivatives or Press 2 for Integrals: ";

		cin >> subChoice;

		while (!cin.good())		//Error Check req
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter valid input: ";
			cin >> subChoice;
		}

		while (subChoice < 1 || subChoice > 2)
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter input in valid range: ";
			cin >> subChoice;
		}

		if (subChoice == 1)
		{
			calcObj.derivative();		//uses class object to call member function
			startingOver();		//calls Menu, causes recursion
		}
		else if (subChoice == 2)
		{
			calcObj.integral();
			startingOver();
		}		
	}

	else if (choice == 2)
	{
		Discrete discObj;		//creates Discrete object
		int discChoice;

		cout << "\n\tPress 1 for Truth Table or 2 for Quick Sort/Binary Search: ";

		cin >> discChoice;

		while (!cin.good())		//Error Check req
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter valid input: ";
			cin >> discChoice;
		}

		while (discChoice < 1 || discChoice > 2)
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n\tPlease Enter input in valid range: ";
			cin >> discChoice;
		}

		if (discChoice == 1)
		{
			discObj.truthTable();
			startingOver();
		}

		else if (discChoice == 2)
		{
			displayQuickSort();
			startingOver();
		}	
	}

	else if (choice == 3)
	{
		DerivedClass *obj2;		//pointer to class object
		obj2->trigTriangle();
		startingOver();
	}
}

void quickSort(vector<int>& A, int p, int q)	//vector req, pointer as parameter req
{
	int r;
	if (p < q)		//lower search bound < higher search bound, (q is technically the pivot element)
	{
		r = partition(A, p, q);
		quickSort(A, p, r);			//part of list before pivot value
		quickSort(A, r + 1, q);		//part of list after (greater than) pivot element (value)
	}
}

int partition(vector<int>& A, int p, int q)		//quicksort req
{
	int x = A[p];
	int i = p;		//temp holding variable for swap
	int j;

	for (j = p + 1; j < q; j++)		//from number after lower bound to the upper bound
	{
		if (A[j] <= x)		//if number after lower bound is less than lower bound
		{
			i = i + 1;		//lower bound increases by 1
			swap(A[i], A[j]);		//sorting vector req, flip
		}
	}

	swap(A[i], A[p]);		//swapping out of order elements
	return i;
}

void displayQuickSort()
{
	vector<int> A = { 6,10,13,5,8,3,2,25,4,11 };		//unsorted list
	int p = 0;		//lower bound
	int q = 10;		//upper bound

	cout << "\n\t        List\n\t" << "\t----\n\t";

	for (auto e : A)
	{
		cout << e << " ";		//prints each element of list
	}
		cout << endl;
	
	quickSort(A, p, q);		

	cout << "\n\t      Quicksort\n\t" << "      ---------\n\t";

	for (auto e : A)
	{
		cout << e << " ";		//prints each element of now sorted list
	}
		cout << endl;
	
	displayBinarySearch();		//function to let user search for an element in sorted vector
	startingOver();
}

void screenGreeting()		//screen control req
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);		//native to windows
	COORD position;

	position.X = 30;
	position.Y = 3;

	SetConsoleCursorPosition(screen, position);
	cout << "Hello There!" << endl << endl;
}

void displayBinarySearch()		//demonstrates a search on an ordered list
{
	ArraySort size;		//struct
	
	int searchNum;

	int sorted[10] = {2, 3, 4, 5, 6, 8, 10, 11, 13, 25};		//sorted list of array elements
	int result;
	cout << "\n\tEnter the number you wish to search for: ";
		 cin >> searchNum;

		 while (!cin.good())		//Error Check req
		 {
			 cin.clear();
			 cin.ignore();
			 cout << "\n\n\tPlease Enter valid input: ";
			 cin >> searchNum;
		 }

	 result = binarySearch(sorted, 0, size.sizeOf - 1, searchNum);

	 if (result == -1)		//sentinel req
	 {
		 cout << "\n\tThat number does not exist in the array. \ n";
	 }

	 else if (result == 0)		//0 is the element
	 {
		 cout << "\n\tThat number is the " << result + 1;		//1 is the position
		 cout << "st one in the list\n";
	 }

	 else if (result == 1)		//1 is the element
	 {
		 cout << "\n\tThat number is the " << result + 1;		//2 is the position
		 cout << "nd one in the list\n";
	 }
	 
	 else if (result == 2)		//2 is the element
	 {
		 cout << "\n\tThat number is the " << result + 1;		//3 is the position
		 cout << "rd one in the list\n";
	 }

	 else
	 {
		 cout << "\n\tThat number is the " << result + 1;
		 cout << "th one in the list\n";
	 }	
}

int binarySearch(const int sorted[], int first, int last, int value)
 {	
	 int middle;  

	 if (first > last)		//error check
	 { 
		return -1;
	 }
		 
	 middle = (first + last)/ 2;		//average formula
	 
	 if (sorted[middle] == value)
	 {
		 return middle;		//if searching for the middle number
	 }
		 
	 if (sorted[middle] < value)		//if searching for higher than middle number
	 {
		 return binarySearch(sorted, middle + 1, last, value);		//recursion, with num above middle as the lower bound
	 }
	 else
	 {
		 return binarySearch(sorted, first, middle - 1, value);		//recursion, with num below middle as the upper bound
	 }		
 }

void startingOver()		//allows user to decide to return to main menu
{
	char startOver;

	cout << "\n\tWould you like to start over?(Y/N): ";
	cin >> startOver;

	while (!cin.good())
	{
		cin.clear();
		cin.ignore();
		cout << "\n\n\tPlease Enter valid input: ";
		cin >> startOver;
	}

	startOver = toupper(startOver);

	while (startOver != 'Y' && startOver != 'N')
	{
		cin.clear();
		cin.ignore();
		cout << "\n\n\tPlease Enter Y for yes or N for no: ";
		cin >> startOver;
		startOver = toupper(startOver);
	}

	if (startOver == 'Y')
	{
		displayMenu();
		Menu();		//recursion in Menu call
	}
	else if (startOver == 'N')
	{

	}
}



