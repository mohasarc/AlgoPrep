#include <iostream>
using namespace std;

void merge(int* arr, int lowEnd, int upEnd){
    cout<<"lowest item : "<<arr[lowEnd]<<" highest item : "<<arr[(lowEnd+(upEnd-lowEnd)/2)]<<endl;
    cout<<"lowest index : "<<lowEnd<<" highest index : "<<upEnd<<endl;

    int j = (lowEnd+(upEnd-lowEnd)/2);
    int i = lowEnd;
    int k = lowEnd;
    int i_end = k - 1;
    int j_end = upEnd;
    // int sortedSoFar = lowEnd;

    cout<<"before merging : \n";
    for(int l = lowEnd; l < upEnd; l++)
        cout<<arr[l]<<"\t";
    cout<<endl;

    while(i < upEnd && j < upEnd && k < upEnd){

        cout<<"merging step "<<k<<" : \n";
        for(int l = lowEnd; l < upEnd; l++)
            cout<<arr[l]<<"\t";
        for(int l = lowEnd; l < upEnd; l++){
            if(l == i && l == k)
                cout<<"\t"<<i<<"\t";
            else if(l == i)
                cout<<i<<"\t";
            else if(l == k)
                cout<<k<<"\t";
            else
                cout<<" "<<"\t";
        }
        cout<<endl;

        cout<<"i = "<<i<<" j = "<<j<<" k = "<<k<<endl;
        if( i < j){
            if(arr[j] <= arr[i] ){
                int tmp = arr[k];
                arr[k] = arr[j];
                arr[j] = tmp;
                if(i==k)
                    i = j;
                k++;
                if(j != j_end)
                    j++;
            } else {
                if(i == k){
                    i++;
                    k++;
                } else if (i == (j - 1)){
                    // swap i and k
                    int tmp = arr[k];
                    arr[k] = arr[i];
                    arr[i] = tmp;
                    i = k;
                } else {
                    // swap i and k
                    int tmp = arr[k];
                    arr[k] = arr[i];
                    arr[i] = tmp;
                    // swap j and i
                    int tmp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = tmp;

                    j = j_end = i;
                    i++;
                }


        //         i++;
        //         k++;
        //         if (i==j)
        //             i = k;
        //     }
        // } else if ( j < i){
        //     if(arr[j] <= arr[i] ){
        //         int tmp = arr[k];
        //         arr[k] = arr[j];
        //         arr[j] = tmp;
        //         if(i==k)
        //             i = j;
        //         k++;
        //         if(j != upEnd-1)
        //             j++;
        //     } else {
        //         int tmp = arr[k];
        //         arr[k] = arr[i];
        //         arr[i] = tmp;
        //         i++;
        //         k++;
        //         if (i==j)
        //             i = k;
            }
        } else if (j < i){
            if (arr[i] <= arr[j]){
                // swap i and k
                int tmp = arr[k];
                arr[k] = arr[i];
                arr[i] = tmp;
                if(j==k)
                    j = i;
                k++;
                if(i != i_end)
                    i++;
            } else {

                if(j == k && j != (i - 1)){
                    j++;
                    k++;
                } else if (j == (i - 1)){
                    // swap j and k
                    int tmp = arr[k];
                    arr[k] = arr[j];
                    arr[j] = tmp;
                    j = i_end + 1;
                } else {
                    // swap i and k
                    int tmp = arr[k];
                    arr[k] = arr[i];
                    arr[i] = tmp;
                    // swap j and i
                    int tmp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = tmp;

                    j = j_end = i;
                    i++;
                }
            }
        }

        cout<<"merging step "<<k<<" : \n";
        for(int l = lowEnd; l < upEnd; l++)
            cout<<arr[l]<<"\t";

        cout<<endl;
    }

    // if(arr[lowEnd] > arr[(lowEnd+(upEnd-lowEnd)/2)]){
    //     for (int i = lowEnd; i < (lowEnd+(upEnd-lowEnd)/2); i++){
    //         int tmp = arr[i];
    //         arr[i] = arr[j];
    //         arr[j] = tmp;
    //         j++;
    //     }
    // }
    for(int i = lowEnd; i < upEnd; i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
}

void sort(int* arr, int lowEnd,int upEnd){
    if (upEnd - lowEnd < 1)
        return;

    cout<<"in merge sort with : "<<lowEnd<<"\t"<<upEnd<<endl;
    if (upEnd - lowEnd > 1){
        sort(arr, lowEnd, (lowEnd+(upEnd-lowEnd)/2));
        sort(arr, (lowEnd+(upEnd-lowEnd)/2), upEnd);
    }

    cout<<"merging "<<lowEnd<<" , "<< (lowEnd+(upEnd-lowEnd)/2)<< " with : " << (lowEnd+(upEnd-lowEnd)/2)<<" , "<< upEnd <<endl;
    merge(arr, lowEnd, upEnd);
}