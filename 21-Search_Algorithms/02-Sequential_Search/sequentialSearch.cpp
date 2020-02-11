#include <iostream>
// checks each item of the list until a match is found
int sequentialSearch( int* arr, int size, int target ){

    for (int i = 0; i < size; i++){
        if (arr[i] == target)
            return i;
    }
    
    return -1;
}

// int main (){
//     int arr[6] = {0, 4, 3, 9, 3, 5};
//     std::cout<<sequentialSearch(arr, 6, 3);
// }