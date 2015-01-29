/*Author: Jonathan Flessner		Date: 15-July-2013
**Description: Finds the area under the curve of 5 possible given functions using 
**the rectangular midpoint or trapezoid methods between two given x points.
**Input: function to evaluate, method to evaluate, number of rectangles and/or trapezoids,
**beginning x value, ending x value.
**Output: Area under the curve for the selected function bounded by the start and end x points.
**Number of rectangles/trapezoids used, beginning/ending x values.
*/

#include <iostream>
#include <cmath>
using namespace std;

void rectangleMeth (int functionNum);
//calls the proper rectangle method function
void f1r (int nR, double a, double b);
void f2r (int nR, double a, double b);
void f3r (int nR, double a, double b);
void f4r (int nR, double a, double b);
void f5r (int nR, double a, double b);
//calculates and returns the area under chosen function using nR as the number of rectangles
//and a and b as the bounds for the start and end points of x.
void trapezoidMeth (int functionNum);
//calls the proper trapezoid method function
void f1t (int nT, double a, double b);
void f2t (int nT, double a, double b);
void f3t (int nT, double a, double b);
void f4t (int nT, double a, double b);
void f5t (int nT, double a, double b);
//calculates and returns the area under chosen function using nT as the number of trapezoids
//and a and b as the bounds for the start and end points of x.

int main ()
{
	int functionNum; //identifies user-selected function
	int calcMeth; //identifies method for calculating area
	int contCheck; //variable to check for continuing or ending the program
	
	do 
	{
		//opening statement for selecting function or exiting program
		cout << "Please choose a function to evaluate the area under the curve: \n"
			 << "	1: f1(x) = 2x^5 + x^3 - 10x + 2 \n"
			 << "	2: f2(x) = 6x^2 - x + 10 \n"
			 << "	3: f3(x) = 5x + 3 \n"
			 << "	4: f4(x) = 2x^3 + 120 \n"
			 << "	5: f5(x) = 2x^2 \n"
			 << " 	Enter any other number to exit. \n"
			 << "Please enter your choice: ";
		cin >> functionNum; //stores function to evaluate. used in switch statement.
		if (functionNum > 5 || functionNum < 1) //checks to see if user chooses to exit
			return 0; 							//exits if number is not 1-5
		
		//determines method user wants to use to evaluate area under
		cout << "You can calculate the area using: \n"
			 << "	1: rectangle method \n"
			 << "	2: trapezoid method \n"
			 << "	3: both rectangle and trapezoid method \n"
			 << "	Enter any other number to exit. \n"
			 << "How would you like to continue?  ";
		cin >> calcMeth; //stores response
		if (calcMeth == 1) 
			rectangleMeth(functionNum); //if 1 then calls rectangle method function
		else if (calcMeth == 2)
			trapezoidMeth(functionNum); // if 2 then calls trapezoid method function
		else if (calcMeth == 3) { 
			rectangleMeth(functionNum); // if 3 then both functions are called. 
			trapezoidMeth(functionNum); } // first rectangle, then trapezoid.
		else 
			return 0; //exits if response is not 1-3
		
		//checks if user would like to continue or exit
		cout << "Would you like to run the program again or exit? \n"
			 << "Enter zero to exit and any other number to run again. \n";
		cin >> contCheck; //stores response
	} while (contCheck != 0); //continues with any non-zero number
	
	return 0; //ends program if 0 is entered
}

void rectangleMeth (int functionNum) //function to determine which rectangle function (1-5) to call
{
	bool errorTest = false; //checks for errors in start and end points
	int nR; //holds number of rectangles
	double a; //holds starting point
	double b; //holds ending point
	
	cout << "How many rectangles do you want?  ";
	cin >> nR; //stores number of rectangles
	
	while (errorTest == false) //loop to ensure a is less than b
	{
		cout << "Please select a starting point, a = ";
		cin >> a;
		
		cout << "Please select an ending point, b = ";
		cin >> b;
		
		if ( b <= a) //ensures a is greater than b. throws error and restarts loop if not
		{
			cout << "Error. 'a' must be less than 'b'. \n"
				 << "Please re-enter the starting and ending points. \n";
			continue; //restarts loop
		}
		else
			errorTest = true; //ends loop
	}
	
	switch (functionNum) //switch statement to call rectangle function functions
		{
			case 1:
				f1r (nR, a, b);
				break;
			case 2:
				f2r (nR, a, b);
				break;
			case 3:
				f3r (nR, a, b);
				break;
			case 4:
				f4r (nR, a, b);
				break;
			case 5:
				f5r (nR, a, b);
				break;
		}
}
void f5r (int nR, double a, double b) //rectangle function 5
{
	double recArea; //area of each rectangle to be added together
	double totalArea = 0; //total area under the curve
	double w = ((b - a) / nR); //width of each rectangle
	double m = a + (w / 2); //midpoint of each rectangle. set to a to begin calculation
	double h; //height of each rectangle
	
	while (m < b) //ends loop once a rectangle would be past the endpoint
	{
		h = 2 * pow(m , 2.0); //find height using f(midpoint)
		recArea = w * h; //find area of each rectangle
		totalArea = totalArea + recArea; //add area of each rectangle to totalArea.
		m = m + w; //add width to midpoint to move to next rectangle
	}

	//prints out area under curve and n, a, and b values
	cout << "The area under 2x^2 between " << a << " and " << b << " using "
		 << nR << " rectangles is " << totalArea  << endl;
}
void f4r (int nR, double a, double b) //rectangle function 4
{
	double recArea; //area of each rectangle to be added together
	double totalArea = 0; //total area under the curve
	double w = ((b - a) / nR); //width of each rectangle
	double m = a + (w / 2); //midpoint of each rectangle. set to a to begin calculation
	double h; //height of each rectangle
	
	while (m < b) //ends loop once a rectangle would be past the endpoint
	{
		h = (2 * (pow(m , 3.0)))+120; //find height using f(midpoint)
		recArea = w * h; //find area of each rectangle
		totalArea = totalArea + recArea; //add area of each rectangle to totalArea.
		m = m + w; //add width to midpoint to move to next rectangle
	}

	//prints out area under curve and n, a, and b values
	cout << "The area under 2x^3 + 120 between " << a << " and " << b << " using "
		 << nR << " rectangles is " << totalArea  << endl;
}
void f3r (int nR, double a, double b) //rectangle function 3
{
	double recArea; //area of each rectangle to be added together
	double totalArea = 0; //total area under the curve
	double w = ((b - a) / nR); //width of each rectangle
	double m = a + (w / 2); //midpoint of each rectangle. set to a to begin calculation
	double h; //height of each rectangle
	
	while (m < b) //ends loop once a rectangle would be past the endpoint
	{
		h = (5 * m) + 3; //find height using f(midpoint)
		recArea = w * h; //find area of each rectangle
		totalArea = totalArea + recArea; //add area of each rectangle to totalArea.
		m = m + w; //add width to midpoint to move to next rectangle
	}

	//prints out area under curve and n, a, and b values
	cout << "The area under 5x + 3 between " << a << " and " << b << " using "
		 << nR << " rectangles is " << totalArea  << endl;
}
void f2r (int nR, double a, double b) //rectangle function 2
{
	double recArea; //area of each rectangle to be added together
	double totalArea = 0; //total area under the curve
	double w = ((b - a) / nR); //width of each rectangle
	double m = a + (w / 2); //midpoint of each rectangle. set to a to begin calculation
	double h; //height of each rectangle
	
	while (m < b) //ends loop once a rectangle would be past the endpoint
	{
		h = (6 * pow(m , 2.0)) - m + 10; //find height using f(midpoint)
		recArea = w * h; //find area of each rectangle
		totalArea = totalArea + recArea; //add area of each rectangle to totalArea.
		m = m + w; //add width to midpoint to move to next rectangle
	}

	//prints out area under curve and n, a, and b values
	cout << "The area under 6x^2 - x + 10 between " << a << " and " << b << " using "
		 << nR << " rectangles is " << totalArea  << endl;
}
void f1r (int nR, double a, double b) //rectangle function 1
{
	double recArea; //area of each rectangle to be added together
	double totalArea = 0; //total area under the curve
	double w = ((b - a) / nR); //width of each rectangle
	double m = a + (w / 2); //midpoint of each rectangle. set to a to begin calculation
	double h; //height of each rectangle
	
	while (m < b) //ends loop once a rectangle would be past the endpoint
	{
		h = (2 * pow(m , 5.0)) + (pow(m , 3.0)) - (10 * m) + 2; //find height using f(midpoint)
		recArea = w * h; //find area of each rectangle
		totalArea = totalArea + recArea; //add area of each rectangle to totalArea.
		m = m + w; //add width to midpoint to move to next rectangle
	}

	//prints out area under curve and n, a, and b values
	cout << "The area under 2x^5 + x^3 - 10x + 2 between " << a << " and " << b << " using "
		 << nR << " rectangles is " << totalArea  << endl;
}

void trapezoidMeth (int functionNum) //determines which trapezoid function to call
{
	bool errorTest = false; //checks for errors in start and end points
	int nT; //number of trapezoids
	double a; //starting point
	double b; //ending point
	
	cout << "How many trapezoids do you want?  ";
	cin >> nT; //stores number of trapezoids
	
	while (errorTest == false) //loop to ensure a is less than b
	{
		cout << "Please select a starting point, a = ";
		cin >> a;
		
		cout << "Please select an ending point, b = ";
		cin >> b;
		
		if ( b <= a) //ensures a is greater than b. throws error and restarts loop if not
		{
			cout << "Error. 'a' must be less than 'b'. \n"
				 << "Please re-enter the starting and ending points. \n";
			continue; //restarts loop
		}
		else
			errorTest = true; //ends loop
	}
	
	switch (functionNum) //switch statement to call trapezoid function functions
		{
			case 1:
				f1t (nT, a, b);
				break;
			case 2:
				f2t (nT, a, b);
				break;
			case 3:
				f3t (nT, a, b);
				break;
			case 4:
				f4t (nT, a, b);
				break;
			case 5:
				f5t (nT, a, b);
				break;
		}
}
void f5t (int nT, double a, double b) //trapezoid function 5
{
	double trapArea; //area of each trapezoid to be added together
	double totalArea = 0; //total area under the curve
	double w = ((b - a) / nT); //width of each trapezoid
	double x = a; //function evaluator
	double l; //left height of trapezoid
	double r; //right height of trapezoid
	double h; //height of each trapezoid
	
	while (x < b) //ends loop once x is greater than or equal to b value
	{
		l = 2 * pow(x , 2.0); //find left height
		r = 2 * pow((x + w) , 2.0); //find right height
		h = (l + r) / 2;
		trapArea = w * h; //find area of each trapezoid
		totalArea = totalArea + trapArea; //add area of each trapezoid to totalArea.
		x = x + w; //add width to midpoint to move to next rectangle
	}

	//prints out area under curve and n, a, and b values
	cout << "The area under 2x^2 between " << a << " and " << b << " using "
		 << nT << " trapezoids is " << totalArea  << endl;
}
void f4t (int nT, double a, double b) //trapezoid function 4
{
	double trapArea; //area of each trapezoid to be added together
	double totalArea = 0; //total area under the curve
	double w = ((b - a) / nT); //width of each trapezoid
	double x = a; //function evaluator
	double l; //left height of trapezoid
	double r; //right height of trapezoid
	double h; //height of each trapezoid
	
	while (x < b)
	{
		l = 2 * pow(x , 3.0) + 120; //find left height
		r = 2 * pow((x + w) , 3.0) + 120; //find right height
		h = (l + r) / 2;
		trapArea = w * h; //find area of each trapezoid
		totalArea = totalArea + trapArea; //add area of each trapezoid to totalArea.
		x = x + w; //add width to midpoint to move to next rectangle
	}

	//prints out area under curve and n, a, and b values
	cout << "The area under 2x^3 + 120 between " << a << " and " << b << " using "
		 << nT << " trapezoids is " << totalArea  << endl;
}
void f3t (int nT, double a, double b) //trapezoid function 3
{
	double trapArea; //area of each trapezoid to be added together
	double totalArea = 0; //total area under the curve
	double w = ((b - a) / nT); //width of each trapezoid
	double x = a; //function evaluator
	double l; //left height of trapezoid
	double r; //right height of trapezoid
	double h; //height of each trapezoid
	
	while (x < b)
	{
		l = (5 * x) + 3; //find left height
		r = (5 * (x + w)) + 3; //find right height
		h = (l + r) / 2;
		trapArea = w * h; //find area of each trapezoid
		totalArea = totalArea + trapArea; //add area of each trapezoid to totalArea.
		x = x + w; //add width to midpoint to move to next rectangle
	}

	//prints out area under curve and n, a, and b values
	cout << "The area under 5x + 3 between " << a << " and " << b << " using "
		 << nT << " trapezoids is " << totalArea  << endl;
}
void f2t (int nT, double a, double b) //trapezoid function 2
{
	double trapArea; //area of each trapezoid to be added together
	double totalArea = 0; //total area under the curve
	double w = ((b - a) / nT); //width of each trapezoid
	double x = a; //function evaluator
	double l; //left height of trapezoid
	double r; //right height of trapezoid
	double h; //height of each trapezoid

	while (x < b)
	{
		l = 6 * pow(x , 2.0) - x + 10; //find left height
		r = 6 * pow((x + w) , 2.0) - (x + w) + 10; //find right height
		h = (l + r) / 2;
		trapArea = w * h; //find area of each trapezoid
		totalArea = totalArea + trapArea; //add area of each trapezoid to totalArea.
		x = x + w; //add width to midpoint to move to next rectangle
	}

	//prints out area under curve and n, a, and b values
	cout << "The area under 6x^2 - x + 10 between " << a << " and " << b << " using "
		 << nT << " trapezoids is " << totalArea  << endl;
}
void f1t (int nT, double a, double b) //trapezoid function 1
{
	double trapArea; //area of each trapezoid to be added together
	double totalArea = 0; //total area under the curve
	double w = ((b - a) / nT); //width of each trapezoid
	double x = a; //function evaluator
	double l; //left height of trapezoid
	double r; //right height of trapezoid
	double h; //height of each trapezoid
	
	while (x < b)
	{
		l = (2 * pow(x , 5.0)) + (pow(x , 3.0)) - (10 * x) + 2; //find left height
		r = (2 * pow((x + w) , 5.0)) + (pow((x + w) , 3.0)) - (10 * (x + w)) + 2; //find right height
		h = (l + r) / 2;
		trapArea = w * h; //find area of each trapezoid
		totalArea = totalArea + trapArea; //add area of each trapezoid to totalArea.
		x = x + w; //add width to midpoint to move to next rectangle
	}

	//prints out area under curve and n, a, and b values
	cout << "The area under 2x^2 between " << a << " and " << b << " using "
		 << nT << " trapezoids is " << totalArea  << endl;
}