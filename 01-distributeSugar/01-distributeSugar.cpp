// 01-distributeSugar.cpp : This file contains the 'main' function. Program execution begins and ends there.
// The Problem : there going to be a list of students and a piece of sugar is goint to be given to a range of students
//               each time. After a few rounds, we want to know how many pieces of sugar did a particular student have.

#include <iostream>
using namespace std;

// Global constants
const int rangesCount = 10, rangeNo = 2;

// prototypes
void giveSugar(int ranges[][rangeNo], int students[]);
int askSugar(int studentIndex, int students[]);

int main()
{
	// Variables
	int students[500];
	int ranges[rangesCount][rangeNo] = { {3,6}, {2,5}, {2,9}, {5,9}, {4,9}, {1,23}, {43,250}, {143, 340}, {0,140}, {5, 150} };

	// The code
	// initialize students with 0 sugar
	for (int i = 0; i < sizeof students / sizeof students[0]; i++) {
		students[i] = 0;
	}

/*
	*************
	  SOLUTION 1
	*************
*/
	giveSugar(ranges, students);
	cout << askSugar(5, students) << endl;

}// main ends

void giveSugar(int ranges[][rangeNo], int students[]) {
	// variables
	int startingRange, endingRange;

	// The code
	// for each range, store its starting and ending
	for (int i = 0; i < rangesCount; i++) {
		startingRange = ranges[i][0];
		endingRange = ranges[i][1];
		
		// use the starting and ending indices to increment everything in between by 1
		for (int i = startingRange; i < endingRange; i++) {
			students[i] ++;
		}
	}
}

/*
ask sugar functiuon returns the number of sugar pieces does the student have
*/
int askSugar(int studentIndex, int students[]) {
	return students[studentIndex];
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
