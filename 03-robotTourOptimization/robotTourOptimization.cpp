#include <iostream>
#include "math.h"
using namespace std;

// prototypes
void nearistNeighbor();
void remove(pair<int, int>* array, int j);
double distance(pair<int, int> a, pair<int, int> b);

// the code
void nearistNeighbor(){
	int nPoints = 4;
	int currentlyOccupied;
	pair<int,int> p[nPoints] = {make_pair(0,4),make_pair(5,9),make_pair(-5,-2),make_pair(-10,25)};
	pair<int,int> path[nPoints];

	path[0] = p[0];
	currentlyOccupied = 1;
	remove(p, 0);

	cout<< p[0].first<< " , "<< p[0].second<<endl;

	while (sizeof p > 0){
		path[currentlyOccupied] = p[0];
		for (int k = 0; k < sizeof p; k++){
			if (distance(path[currentlyOccupied], path[currentlyOccupied-1]) > distance(p[k], path[currentlyOccupied - 1]))
				path[currentlyOccupied] = p[k];

			remove(p, k);
			currentlyOccupied ++;
		}
	}

		cout<< path[0].first<< " , "<< path[0].second<< " ), (";
		cout<< path[1].first<< " , "<< path[1].second<< " ), (";
		cout<< path[2].first<< " , "<< path[2].second<< " ), (";
		cout<< path[3].first<< " , "<< path[3].second<< " ), (";
}

// remove the element at index j and shift the other elements
// up the array
void remove(pair<int, int>* array, int j){

	for (int i = j; i < (sizeof array) - 1; i++){
		array[i] = array[i+1];
	}
}

double distance(pair<int, int> a, pair<int, int> b){
	return sqrt(pow((a.first - b.first), 2)+pow((a.second - b.second),2));
}

int main(){

	nearistNeighbor();

	return 0;
}