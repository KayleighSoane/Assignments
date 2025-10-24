#include <iostream>
using namespace std;

// Kayleigh Soane - Student ID 10860938


void coordinates() {
	//Task 7
	double a = 3;
	double b = 8;			//ID numbers are 3 and 8
	double x = 6;
	double y = 7;
	cout << "Coordinate 1: (" << a << ", " << b << ")" << endl;
	cout << "Coordinate 2: (" << x << ", " << y << ")" << endl;
	//double coord = sqrt(((a*a)-(x*x)) + ((b*b)-(y*y))); - this code didnt work - procuded nan (not a number)
	double coord = sqrt(pow(x - a, 2) + pow(y - b, 2));  //corrected code - Tried ^2 but it also didn't work, github suggested pow
	cout << "The euclidean distance between the two coordinates is " << coord << endl;
}

void task8count(int rep) {
	for (int i = 1; i <= rep; i++) {
		cout << "Function called " << i << " times" << endl;
	}

}

// Function: Computes average of positive numbers until -1 is entered
// Note: Code contains multiple logical errors for you to fix
double averagePositive() {
	double sum = 0;	
	double count = 0;			
	int num = 0;

	cout << "Calculating the average of inputted values" << endl;
	do {
		do {
			cout << "Enter a positive number (input -1 to end): ";
			cin >> num;
		} while (num < -1);	// Bug 1: Should ignore negatives except -1
		// Fix 1: Changed to < so if number is less than -1, will keep asking for input
		if (num == -1) {
			break;			// Bug 2: If num is -1, gets added to sum
		} else {
			sum += num;		
			count ++;  }	
		// Fix 2: added if else statement so if num is -1, loop stops and -1 isn't added
	} while (num != -1);	
	if (count > 0) {
		double avg = sum / count;		// Bug 3: Dividing integers doesnt give decimals
		// Fix 3: changed sum and count to double to include decimals
		cout << "Average = " << avg << endl;
	}
	else {
		cout << "No values given. Exiting Function" << endl;
		return 0;
	}
	// Bug 4: if no values added, count is 0 so gives division error.
	// Fix 4: create an if else statement so if count = 0, doesn't calculate average.
}

int globvar = 10860938;				//Global variable
static int statvar = 10860938;		//Static global variable

void global() {
	cout << "Global Variable = " << globvar << endl;
}

void statglobal() {
	cout << "Static Global Variable = " << statvar << endl;
}

int main()
{
	int id = 10860938;	//For future reference
	cout << "Kayleigh Soane" << endl;
	cout << "My Student ID number is " << id << endl;
	cout << "*********************************" << endl;
	cout << endl;


	void task1();
	cout << "Task 1" << endl;
	//To add two numbers, create two integers and display sum.
		int a = 3;
		int b = 8;
		cout << "The last two numbers of my student ID are " << a << " and " << b << endl;
		cout << "The sum of these two numbers is " << a + b << endl;
	cout << endl;


	void task2();
	cout << "Task 2" << endl;
	//To multiply two numbers, use *.
		int c = 1;		//create new integer for first number of ID
		cout << "The first number of my student ID is " << c << endl;
		cout << "The product of " << c << " and " << b << " is " << c * b << endl;	//Using b, integer from previous task
	cout << endl;


	void task3();
	cout << "Task 3" << endl;
	//To print each number between 1 and mod20, create a loop that adds 1 until mod20.
		cout << "Mod20 of ID = " << id % 20 << endl;
		int num = 1;		// printing numbers from 1 to mod20, not from 0
		do {
			cout << num << " ";
			num++;
		} while (num <= id % 20);  //stops looping once reached mod20
		cout << endl;
	cout << endl;


	void task4();
	cout << "Task 4" << endl;
	//I need to create an if statement that states if my ID is even or else odd.
		if (id % 2 == 0) {						// attempted with division, didnt work. Referred back to week 3 lecture slides for help.	
			cout << "My ID is an even number" << endl;		// if value is even, mod 2 leaves no remainders, answer is zero.
			}	
			else {
			cout << "My ID is an odd number" << endl;		//if value isn't 0, has remainder of 1 which would be .5, so odd.
			}
	cout << endl;


	void task5();
	cout << "Task 5" << endl;
	//Use switch statement to use the value of mod7 as a case to print the number for day of the week.
	int day = ((id % 7) + 1);			//mod 7 = 3, +1 = 4
		cout << "The value of mod7 of my ID is " << id % 7 << ". Added to 1 is " << day << endl;
		switch (day) {
			case 1: cout << "Monday" << endl;
				break;				// break stops program from continuing to other cases.
			case 2: cout << "Tuesday" << endl;
				break;
			case 3: cout << "Wednesday" << endl;
				break;
			case 4: cout << "Thursday" << endl;
				break;
			case 5: cout << "Friday" << endl;
				break;
			case 6: cout << "Saturday" << endl;
				break;
			case 7: cout << "Sunday" << endl;
				break;
			default:
				cout << "Error: Invalid day" << endl;
				break;
		}
	cout << endl;


	void task6();
	cout << "Task 6" << endl;
	//I need to create an array and print the third value (which will be [2]), including mod50 as a value.
		cout << "Mod50 of my ID is " << id % 50 << endl;		// answer = 38
		int array[] = {34, 35, 36, 37, (id % 50)};
		// tested the array - cout << array[4] << endl; - to see if value 38 printed, which it did
		cout << "The third element of the array is " << array[2] << endl;
	cout << endl;


	void task7();
	cout << "Task 7" << endl;
	// euclidean distance = root (x-a)^2 + (y-b)^2
	// attempted to make Point data type but couldn't get it to work - was overcomplicating it
	// referred to week 5 lecture slides for help
		coordinates(); // function located above main
	cout << endl;


	void task8();
	cout << "Task 8" << endl;
		// 'Call function (Student ID % 5)+1 times.'
		int rep = (id % 5) + 1;		// answer is 4
		//create a function that repeats a message mod5 + 1 times
		//function states number of repititions
		task8count(rep); // function located above main
	cout << endl;


	void task9();
	cout << "Task 9" << endl;
		averagePositive(); // function located above main
		// goals: - Reads integers until -1 is entered.
		//		  - Ignores all negatives(except - 1 as the stop signal).
		//	  	  - Computes the average(double) of all valid positive numbers.
		//		  - Returns 0.0 if no valid positives were entered.

		// I stepped through the code to see what was happening
		// int sum is adding inputted values together
		// There is no output to the function. As long as the input isnt -1, it keeps going.
		// Added code to display values.
		// Fixed bugs as explained above.
		// If entered value is negative, repeats question, value isnt added to calculation.
		// If enter -1, loop stops and average is calculated.
		// If enter -1 as first number (while count is 0), average isnt calculated, function ends
		// If enter 0 with other numbers, average is calculated including 0 as a number, as it should.
		// If no positive values are added before -1, function ends and returns 0.
		// The value of avg is type double and produces decimals.
		
	cout << endl;


	void task10();
	cout << "Task 10" << endl;
	// Global variable is accessible in whole file and other files, located outside of functions
	// Static global variable is only accessible in one file.
	// The only difference is their accessiblity to external files - how do I demonstrate this?
	// Asked for help - i was overcomplicating it
	// Created one global anmd one static global variable, both with my student ID value
	
		global();
		statglobal();

	cout << endl;


	return 0;
}