void sortRecly(int* arr, int n){
    if (n < 1)
        return;

    int max = arr[n-1];
    int max_index;
    for(int i = 0; i < n-1; i++)
        if (arr[i] > max){
            max = arr[i];
            max_index = i;
        }
    if (max != arr[n-1]){
        arr[max_index] = arr[n-1];
        arr[n-1] = max;
    }

    sortRecly(arr, n-1);
}