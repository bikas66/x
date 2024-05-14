#include<stdio.h>

void bubbleSort(int arr[], int n){
	int i, j, temp;
	for (i = 0; i<n-1; i++){
		for (j = 0; j<n-i-1; j++){
			if (arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int binarySearch(int arr[], int low, int high, int target){
	while (low <= high){
		int mid = low+(high-low)/2;
		int i;
		printf("Pass: ");
		for (i = low; i<=high; i++){
			printf("%d", arr[i]);
		}
		printf("\n");
		if (arr[mid == target]){
			return mid;
		}
		else if (arr[mid < target]){
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}
	return -1;
}

int main(){
	int n, target, i;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the array elements: \n");
	for (i = 0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	bubbleSort(arr, n);
	printf("Enter the target element to search: ");
	scanf("%d", &target);
	int result = binarySearch (arr, 0, n-1, target);
	if (result == -1){
		printf("Element not present in the array.\n");
	}else{
		printf("Element found at index %d\n", result);
	}
	return 0;
}
