// The Problem : there going to be a list of students and a piece of sugar is goint to be given to a range of students
//               each time. After a few rounds, we want to know how many pieces of sugar did a particular student have.

#include <iostream>
#include <vector>
using namespace std;

// Global constants
const int rangesCount = 10, rangeNo = 2;

// Global variables
int students[500];

// prototypes
void giveSugar(vector<pair<int,int>> ranges, int students[]);
int askSugar(int studentIndex, int students[]);
void giveSugarUlt(vector<pair<int,int>> ranges, int students[]);
int askSugarUlt(int studentIndex, int students[]);
void studentsInit();

int main()
{
	// Variables
	vector<pair<int, int>> rngs = { make_pair(3,6), make_pair(2,5), make_pair(2,9), make_pair(5,9), make_pair(4,9), make_pair(1,23), make_pair(43,250), make_pair(143, 340), make_pair(0,140), make_pair(5, 150) };;
	int ranges[rangesCount][rangeNo] = { {3,6}, {2,5}, {2,9}, {5,9}, {4,9}, {1,23}, {43,250}, {143, 340}, {0,140}, {5, 150} };

	// The code
/*
	*************
	  SOLUTION 1
	*************
*/
    studentsInit();
	giveSugar(rngs, students);
	cout << askSugar(5, students) << endl;

/*
	*************
	  SOLUTION 2
	*************
*/
    studentsInit();
    giveSugarUlt(rngs, students);
	cout << askSugarUlt(5, students) << endl;

}// main ends

void studentsInit(){
        // initialize students with 0 sugar
    	for (int i = 0; i < sizeof students / sizeof students[0]; i++) {
    		students[i] = 0;
    	}
    }

// ********************** functions for SOL 1 *************************
/*
	it increments every student that happens to be in the range by 1
*/
void giveSugar(vector<pair<int,int>> ranges, int students[]) {
	// variables
	int startingRange, endingRange;

	// The code
	// for each range, store its starting and ending
	for (int i = 0; i < rangesCount; i++) {
		startingRange = ranges[i].first;
		endingRange = ranges[i].second;
		
		// use the starting and ending indices to increment everything in between by 1
		for (int i = startingRange; i <= endingRange; i++) {
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

// ********************** functions for SOL 2 ******************************

void giveSugarUlt(vector<pair<int,int>> ranges, int students[]){
        // variables
    	int startingRange, endingRange;
    
    	// The code
    	// for each range, store its starting and ending
    	for (int i = 0; i < rangesCount; i++) {
    		startingRange = ranges[i].first;
    		endingRange = ranges[i].second;
    		
    		students[startingRange] += 1;
    		students[endingRange] -= 1;
    	}
    }
    
/*
	ask sugar ult functiuon returns the number of sugar pieces does the student have
*/
int askSugarUlt(int studentIndex, int students[]) {
    int sugarAmount = 0;
    
    for (int i = 0; i <= studentIndex; i++){
        sugarAmount += students[i];
        }
	return sugarAmount;
}