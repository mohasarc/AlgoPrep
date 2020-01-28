#include <iostream>
using namespace std;

void quickSort(int* arr, int l, int r){
    if ((r - l) <= 1)
        return;
    
    int pivot = arr[r-1];
    int sorted = l;

    for(int i = l; i < r - 1; i++){
        if(arr[i] <= pivot){
            int tmp = arr[sorted];
            arr[sorted] = arr[i];
            arr[i] = tmp;
            sorted++;
        }
    }

    // put pivot at its appropriate position
    arr[r-1] = arr[sorted];
    arr[sorted] = pivot;

    if(sorted != l){
        quickSort(arr, l, sorted);
        quickSort(arr, sorted, r);
    }
}

void quickSort(int* arr, int size){
    quickSort(arr, 0, size);
}

int main(){
    int arr[13] = {5, 4, 2, 0, 3, 3, 3, 2, 0, 12, 432, 01, 33};
    int arr2[1] = {0};
    quickSort(arr, 13);
    quickSort(arr2, 1);

    for (int i = 0; i < 13 ; i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}