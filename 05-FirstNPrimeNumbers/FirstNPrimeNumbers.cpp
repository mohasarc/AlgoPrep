#include <iostream>
using namespace std;

// check whether a number is divisible by other elements in the given array "arr"
bool divisibleByOthers(int *arr, int size, int toCheck ){
	// bool isPrime = false;
	for (int i = 0; i < size; i++){
		if (arr[i]!=0 && (toCheck % arr[i]) == 0){
			//cout<< toCheck<< "   %   "<< arr[i] << "   ->   "<< toCheck % arr[i]<< endl;
			return true;
		} 
	}
	return false;	
}

bool PrimesUpTo(int n, int *&arr, int size){
	if (n > size){
		return false;
	}

	// initializing the n portion of the array to zeros
	// note : having a 1 in the array would cause an infinite loop
	for (int i = 0; i < size && i <= n; i++){
		arr[i] = 0;
	}
	// filling the small array with primes
	int countUp = 2;
	for (int i = 0; i < size && i <= n; i++){
		if (!divisibleByOthers(arr, size, countUp)){
			//cout<< i << " th one to be added    " <<countUp<< endl;
			arr[i] = countUp++;
		}
		else{
			countUp ++;
			if (i > 0)
				i--;
		}
	}

	return true;
}

int main(){
	int arraySize = 50;
	int* array = new int[arraySize];

	PrimesUpTo(50, array, arraySize);

	for (int i = 0; i < arraySize; i++){
		if (i % 5 == 0)
			cout << "\n";
		cout << array[i]<< "\t";
	}
	return 0;
}