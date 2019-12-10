#include <iostream>
using namespace std;

void fourConnectivity( int** arr, int** labels, int row, int column,
int i, int j, int currLabel );
int** findConnectedComponents( int** arr, int row, int column );


int** findConnectedComponents( int** arr, int row, int column ) {
int** labels, i, j, currLabel;
labels = new int* [ row ];
for ( i = 0; i < row; i++ ) {
labels[ i ] = new int [ column ];
for ( j = 0; j < column; j++ )
labels[ i ][ j ] = 0;
}
currLabel = 1;
for ( i = 0; i < row; i++ )
for ( j = 0; j < column; j++ )
if ( arr[ i ][ j ] && !labels[ i ][ j ] )
fourConnectivity( arr, labels, row, column, i, j, currLabel++ );
return labels;
}

void fourConnectivity( int** arr, int** labels, int row, int column,
int i, int j, int currLabel ) {
if ( arr[i][j] == 0 )
return;
if ( labels[i][j] > 0 )
return;
labels[i][j] = currLabel;
if ( i - 1 >= 0 )
fourConnectivity( arr, labels, row, column, i - 1, j, currLabel );
if ( i + 1 < row )
fourConnectivity( arr, labels, row, column, i + 1, j, currLabel );
if ( j - 1 >= 0 )
fourConnectivity( arr, labels, row, column, i, j - 1, currLabel );
if ( j + 1 < column )
fourConnectivity( arr, labels, row, column, i, j + 1, currLabel );
}

int main(){

	int* anArray[10];
	for(int i = 0; i < 10; i++){
		anArray[i] = new int[10];
		for (int j = 0; j < 10; j++)
			anArray[i][j]= 0;
	} 

	cout << findConnectedComponents( anArray, 10, 10 );
	return 0;
}