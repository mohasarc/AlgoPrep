#include <iostream>
using namespace std;

void merge(int* arr, const int l, const int m, const int r){
    int li = l;
    int ri = m;
    int* sortedTmp = new int[r-l];
    int size = 0;

    // populating the first half

    while(li < m && ri < r){
        if(arr[li] <= arr[ri]){
            sortedTmp[size] = arr[li];
            size++;
            li++;
        } else {
            sortedTmp[size] = arr[ri];
            size++;
            ri++;
        }
    }

    // copy any items left in the left array
    while(li < m){
        sortedTmp[size] = arr[li];
        size++;
        li++;
    }

    while(ri < r){
        sortedTmp[size] = arr[ri];
        size++;
        ri++;
    }

    // copy sorted items back to the original array
    for (int i = 0; i < size; i++){
        arr[l+i] = sortedTmp[i];
    }
}

void sort(int* arr, int lowEnd,int upEnd){
    int m = (lowEnd+(upEnd-lowEnd)/2);

    if (upEnd - lowEnd < 1)
        return;

    if (upEnd - lowEnd > 1){
        sort(arr, lowEnd, m);
        sort(arr, m, upEnd);
    }

    merge(arr, lowEnd, m, upEnd);
}