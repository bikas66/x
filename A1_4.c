#include <stdio.h>

void findMaxMin(int arr[], int low, int high, int* min, int* max){
    int mid, local_min, local_max;

    if (low == high){
        *min = arr[low];
        *max = arr[low];
        printf("Divide: [%d,%d]\n", low, high);
        printf("Solve: [%d,%d] => (%d,%d)\n", low, high, *min, *max);
        return;
    }
    
    if (high == low + 1){
        if (arr[low] > arr[high]){
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
        printf("Divide: [%d,%d]\n", low, high);
        printf("Solve: [%d,%d] => (%d,%d)\n", low, high, *min, *max);
        return;
    }
    mid = (low + high) / 2;
    printf("Divide: [%d,%d]\n", low, high);
    findMaxMin(arr, low, mid, &local_min, &local_max);
    int left_min = local_min, left_max = local_max;
    findMaxMin(arr, mid + 1, high, &local_min, &local_max);
    int right_min = local_min, right_max = local_max;
    if (left_min < right_min)
        *min = left_min;
    else
        *min = right_min;
    if (left_max > right_max)
        *max = left_max;
    else
        *max = right_max;
    printf("Solve: [%d,%d] => (%d,%d)\n", low, high, *min, *max);
}

int main(){
    int n, i, arr[10];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int min, max;
    printf("\nPasses:\n");
    findMaxMin(arr, 0, n - 1, &min, &max);

    printf("\nMinimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}
