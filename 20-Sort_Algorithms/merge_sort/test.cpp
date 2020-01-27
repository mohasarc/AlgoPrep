#include <iostream>
#include "merge_sort.cpp"
using namespace std;

int main(){
    const int arrSize = 16;
    int a[arrSize] = {35, 4, 2, 7, 7, 0, -4, 2, 6, 2, 0, 34, 2, 8, 1, 3};
    int b[arrSize] = {35, 4, 2, 7, 7, 0, -4, 2, 6, 2, 0, 34, 2, 8, 1, 3};
    // sortRecly(a, arrSize);
    sort(b, 0, arrSize);

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