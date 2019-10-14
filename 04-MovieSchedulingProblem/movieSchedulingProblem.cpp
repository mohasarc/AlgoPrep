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
using namespace std;

void earliestJobFirst(){
  vector<pair<int,int>> intervals{make_pair(5,8), make_pair(3,8), make_pair(6,12), make_pair(13,25), make_pair(15,34), make_pair(22,38) };
  
  cout<< intervals.front().first<<" , ";
  cout<< intervals.front().second;
}

int main(){

  earliestJobFirst();
  return 0;
}
