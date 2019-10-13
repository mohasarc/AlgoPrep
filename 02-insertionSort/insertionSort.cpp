// Author: Mohammed S. Yaseen
// Date : 13/10/2019
// 

#include <iostream>
using namespace std;

// the swap method to chenge the places of two adjacent numbers
void swap (int* first, int* second){
	int temp;

	temp = *second;
	*second = *first;
	*first = temp;
}

// - starting from the left swapping every element smaller than
// the one before it (to sort in increasing order)
// - the opposit if it was asked to sort in decreasing
// order (change s[j] < s[j-1] to s[j] > s[j-1])
// *******************
// Title        : insersion sort
// Author       : Steven S. Skiena
// Date         : 2008
// Type         : Source code
// Version      : unknown
// Availability : The algorithm design manual book
// *******************
void insertionSort(int* s, int n){
	int i, j;   /*the counters*/

	for (i = 1; i < n; i ++){
		j = i;

		while (j > 0 && s[j] < s[j-1]){
			swap (&s[j], &s[j-1]);
			j--;
		}
	}
}

int main(){
	int n = 10; /*number of items in the array to be sorted*/
	int toSort[n] = {3,4,2,6,1,9,7,6,4,3};

	cout<<"Before sorting : ";
	for (int i = 0; i < n; i++){
		cout<<toSort[i]<< " ";
	}

	cout<<endl;

	// performing the sort
	insertionSort(toSort, n);

	cout<<"After sorting  : ";
	for (int i = 0; i < n; i++){
		cout<< toSort[i]<< " ";
	}

}