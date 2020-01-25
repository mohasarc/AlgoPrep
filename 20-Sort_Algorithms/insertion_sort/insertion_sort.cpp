// created by : Mohammed S. Yaseen

#include <iostream>
using namespace std;

void insert(int item, int index, int* arr, int n){
    if(index >= n && index < 0)
        return;

    // shift items
    for (int i = (n-1); i >= index; i--){
        if(i != index)
            arr[i] = arr[i-1];
        else
            arr[i] = 0;
    }

    // insert new item
    arr[index] = item;
}

void sort(int* arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            //cout<<i<<"\t"<<j<<"\t"<<arr[i]<<"\t"<<arr[j]<<endl;
            if(arr[j] <= arr[i]){
                // shift right and insert new item at i
                insert(arr[j], i, arr, j+1);
            }
        }
    }
}