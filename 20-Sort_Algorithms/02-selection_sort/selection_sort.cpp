void sortIterly(int* arr, int n){
    for (int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if (arr[j] < arr[i]){
                int tmp;
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}