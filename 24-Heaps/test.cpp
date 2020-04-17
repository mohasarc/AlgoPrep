#include "Header_Files\heap.h"

#include <iostream>
using namespace std;

int main(){
    int arry[10] = {3, 4, 1, 5, 5, 9, 12, 5, 3, 0};

    int *arr = new int[10000];
    for (int i = 0; i < 10; i++)
        arr[i] = arry[i];

    ArrayMaxHeap fHeap(arr, 10);

    fHeap.print();

    for (int i = 0; i < 10; i++){
        cout << fHeap.peekTop() << "\t";
        fHeap.remove();
    }
    return 0;
}