#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, k,temp;

	for(i = 0; i<n-1; i++){
		for(k=0; k<n-i-1; k++){
			if(arr[k]>arr[k+1]){
				temp = arr[k+1];
				arr[k+1] = arr[k];
				arr[k] = temp;
			}
		}
	}
    
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
