// author : Mohammed S. Yaseen
// date   : 14/10/2019

// ********* PROBLEM *********
// Input: A set I of n intervals on the line.
// Output: What is the largest subset of mutually non-overlapping intervals which can
// be selected from I?

// ********* SOURCE  *********
// Title        : movie Scheduling Problem
// Author       : Steven S. Skiena
// Date         : 2008
// Type         : peudo code
// Version      : unknown
// Availability : The algorithm design manual book
// ***************************

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// prototypes
void earliestJobFirst();
bool compareThem(const pair<int,int> &a, const pair<int,int> &b);

void earliestJobFirst(){
	int a[] = {5, 3, 6, 13, 15, 22 };
	int b[] = {8, 8, 12, 25, 34, 38 };
	int n = sizeof a/ sizeof a[0];

  vector<pair<int,int>> intervals;
  
  for (int i = 0; i < n; i++){
  	intervals.push_back(make_pair(a[i], b[i]));
  }

  for (int i = 0; i < intervals.size(); i++){
  	cout<< "("<< intervals[i].first<<" , "<<
  	intervals[i].second<< ")";
  }

  sort(intervals.begin, intervals.end, compareThem);

}

  bool compareThem(const pair<int,int> &a, const pair<int,int> &b){
  	return (a.first<b.first);
  }

/*
void moveToFront(vector<pair<int,int>> v, int index){
	pair<int,int> tmp = v.front;
	v.front = 
}
*/

int main(){

  earliestJobFirst();
  return 0;
}
