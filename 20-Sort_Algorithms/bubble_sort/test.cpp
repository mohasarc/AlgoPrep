#include <iostream>
#include "bubble_sort.cpp"
#include "bubble_sort_recly.cpp"
using namespace std;

int main(){
    const int arrSize = 15;
    int a[arrSize] = {35, 4, 2, 7, 7, 0, -4, 2, 6, 2, 0, 34, 2, 8, 1};
    int b[arrSize] = {35, 4, 2, 7, 7, 0, -4, 2, 6, 2, 0, 34, 2, 8, 1};
    sortRecly(a, arrSize);
    sortIterly(b, arrSize);

    // print a
    for (int i = 0; i < arrSize; i++){
        cout<<a[i]<<"\t";
    }

    cout<<endl;
    
    // print b
    for (int i = 0; i < arrSize; i++){
        cout<<b[i]<<"\t";
    }
}