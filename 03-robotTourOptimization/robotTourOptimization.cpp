// author : Mohammed S. Yaseen
// date   : 13/10/2019

#include <iostream>
#include "math.h"
using namespace std;

// prototypes
void nearistNeighbor();
void remove(pair<int, int>* array, int j);
double distance(pair<int, int> a, pair<int, int> b);

// this function starts from the first point looking each time for the closest
// point and choosing it
// downsides : 
// *******************
// Title        : nearistNeighbor
// Author       : Steven S. Skiena
// Date         : 2008
// Type         : peudo code
// Version      : unknown
// Availability : The algorithm design manual book
// *******************
void nearistNeighbor(){
	// variables
	int nPoints = 4;
	int currentlyOccupied;
	pair<int,int> p[nPoints] = {make_pair(6,9),make_pair(5,9),make_pair(-5,-2),make_pair(0,5)};
	pair<int,int> path[nPoints];

	path[0] = p[0];
	currentlyOccupied = 1;
	remove(p, 0);
	nPoints --;

	//cout<< p[0].first<< " , "<< p[0].second<<endl;

	while (nPoints > 0){
		path[currentlyOccupied] = p[0];
		int k;
		for (k = 0; k < nPoints; k++){
			double dis1 = distance(path[currentlyOccupied], path[currentlyOccupied-1]);
			double dis2 = distance(p[k], path[currentlyOccupied - 1]);
			if ( (dis1 > dis2) && dis1 != 0 && dis2 != 0){
				path[currentlyOccupied + 1] = path[currentlyOccupied];
				path[currentlyOccupied] = p[k];
				remove(p, k);
				nPoints --;
				currentlyOccupied ++;
			}
			
			//cout<< p[0].first<< " , "<< p[0].second<<endl;
			//cout<< path[currentlyOccupied].first<< " , "<< path[currentlyOccupied].second<<endl;
			
		}
		remove(p, 0);
		nPoints --;
		currentlyOccupied ++;
	}

		cout<< "( " <<path[0].first<< " , "<< path[0].second<< " ), ( ";
		cout<< path[1].first<< " , "<< path[1].second<< " ), ( ";
		cout<< path[2].first<< " , "<< path[2].second<< " ), ( ";
		cout<< path[3].first<< " , "<< path[3].second<< " )";
}

// closest pair 
//void closestPair(){
//        
//}

// optimal
// optimalTSP(){
//
//}

// remove the element at index j and shift the other elements
// up the array
void remove(pair<int, int>* array, int j){

	for (int i = j; i < (sizeof array) - 1; i++){
		array[i] = array[i+1];
	}
}

// calculate the distance between two points in 2d
double distance(pair<int, int> a, pair<int, int> b){
	//cout<< "the distance"<< " between ("<< a.first<< ","<< a.second<< ") and (" <<b.first<< " , "<< b.second << ") is : ";
	//out<< sqrt(pow((a.first - b.first), 2)+pow((a.second - b.second),2))<< endl; 
	return sqrt(pow((a.first - b.first), 2)+pow((a.second - b.second),2));
}

int main(){

	nearistNeighbor();

	return 0;
}
