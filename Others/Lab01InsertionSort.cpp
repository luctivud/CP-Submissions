// Program by Udit Gupta
#include <bits/stdc++.h>
using namespace std;

void InsertionSort_udit(int arr[], int n) {
	for (int i = 1; i < n; i++) {  
        int val = arr[i];  
        int j = i - 1; 
        while (j >= 0 && arr[j] > val) {  
            arr[j + 1] = arr[j];  
            j--;
        }  
        arr[j + 1] = val;  
    }  
}

int main() {

	int n; 
	printf("Enter the size of array \n");
	scanf("%d", &n);

	int arr[n];
	printf("Enter space seperated sorted array \n");
	for (int i=0; i < n; i++) {
		scanf("%d", &(arr[i]));
	}		

	InsertionSort_udit(arr, n);

	printf("Sorted Array is\n");
	for (int i=0; i < n; i++) {
		printf("%d ", (arr[i]));
	}printf("\n");

	return 0;
}