void sortRecly(int* arr, int n){
    if(n < 2)
        return;

    for(int i = 1; i < n; i++){
        if (arr[i] < arr[i-1]){
            int tmp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = tmp;
        }
    }

    sortRecly(arr, n-1);
}