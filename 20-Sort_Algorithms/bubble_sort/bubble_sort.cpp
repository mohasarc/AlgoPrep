

void sortIterly(int* arr, int n){
    if(n < 2)
        return;
    
    for(int limit = n; limit >= 0; limit--){
        for(int i = 1; i < limit; i++){
            if(arr[i] < arr[i-1]){
                int tmp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = tmp;
            }
        }
    }
}