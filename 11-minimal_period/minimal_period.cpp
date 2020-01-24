// You are given an array a of length n = 2m. Write a function that finds length of the minimal period T of array a.

// int MinPeriod(int * a, int n)

// Number T is a period of array a, if repeating first T elements of array a several times gives exactly array a, without any extra elements.

// Examples:
// input                                  output
// n = 8 	                             	4
// a = {2, 5, 3, 4, 2, 5, 3, 4}		
// n = 8                               		8
// a = {2, 5, 3, 2, 5, 3, 2, 5}

// source : https://www.microsoft.com/sr-latn-rs/mdcs/prepare-for-se-test.aspx

#include <iostream>
#include <vector>
using namespace std;

int MinPeriod(int * a, int n){
    bool found = false;
    int period = 0;
    vector<int> periodLst;
    for (period = 1; period<= n && !found; period++){
        // cout<<"checking period sixe of : "<< period<<endl;
        for (int j = 0; j <period; j++){
            periodLst.insert(periodLst.begin() + j, a[j]);
        }

        for (int i = 0; i < n; i++){
            // cout<<periodLst[i%period]<< " == " << a[i]<<endl;
            // cout<<(periodLst[i%period] == a[i] && i%period == (period - 1))<<endl;
            if(periodLst[i%period] == a[i] && i%period == (period - 1)){
                found = true;
            } else if (periodLst[i%period] == a[i] && i%period != (period - 1)) {
                found = false;
            } else if (periodLst[i%period] != a[i]){
                found = false;
                i = n;
            }
        }
    }

    return period - 1;
}

int main(){
    int a[] = {2, 5, 3, 4, 2, 5, 3, 4};
    int b[] = {2, 5, 3, 2, 5, 3, 2, 5};
    int c[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3};
    int d[] = {2, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3};
    int e[] = {1, 2, 3, 1, 2, 3, 1, 3, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3};
    int f[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4};

    cout<<MinPeriod(a, 8)<<endl;
    cout<<MinPeriod(b, 8)<<endl;
    cout<<MinPeriod(c, 18)<<endl;
    cout<<MinPeriod(d, 18)<<endl;
    cout<<MinPeriod(e, 18)<<endl;
    cout<<MinPeriod(f, 19)<<endl;
}