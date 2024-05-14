#include <stdio.h>

void swap(int *v1, int *v2){
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

int partition(int arr[], int s, int e){
    int pivot = arr[e];
    int i = s-1;
    int j;
   
    for(j = s; j < e; j++){
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[e]);
    
    return (i+1);
}

void quicksort(int arr[], int s, int e){
    int l, mid, i;
    if(s >= e)
    	return;
    else{
        printf("\n PIVOT ELEMENT:%d\n", arr[e]);
       
        int p = partition(arr, s, e);

        printf("\n Pass:");
        for(i = s; i <= e; i++)
        	printf("%d ", arr[i]);
          
        printf("\n Pass:");
        for(i = s; i <= p-1; i++)
        	printf("%d ", arr[i]);

        quicksort(arr, s, p-1);
        
        printf("\n Pass:");
        for(i = p+1; i <= e; i++)
        	printf("%d ", arr[i]);
        	
        quicksort(arr, p+1, e);
    }
}

int main(){
    int arr[20], n, l, p, check, m;
    
    printf("Enter the no. of elements:");
    scanf("%d", &n);
    
	printf("\n Enter the elements of the array:");
    for(l = 0; l < n; l++){
		scanf("%d", &arr[l]);
    }
    
	quicksort(arr, 0, n-1);
	
	printf("\n Elements of the array after sorting: ");
	for(l = 0; l < n; l++){
		printf("%d\t", arr[l]);
	}
	
    return 0;
}
