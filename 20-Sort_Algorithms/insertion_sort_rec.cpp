#include "insertion_sort.cpp"

void sortRecly(int* arr, int n){
    // stopping case
    if(n == 1)
        return;

    // sort n-1 items
    sortRecly(arr, n-1);

    // insert nth item in its appropriate position
    for (int i = 0; i < n-1; i++){
        if(arr[n-1] <= arr[i]){
            insert(arr[n-1], i, arr, n);
        }
    }
}