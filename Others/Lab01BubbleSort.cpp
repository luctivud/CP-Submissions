// Program by Udit Gupta
#include <bits/stdc++.h>
using namespace std;

void BubbleSort_udit(int arr[], int n) {
	for (int i = 0; i < n-1; i++)      
		for (int j = 0; j < n-i-1; j++)  
        	if (arr[j] > arr[j+1])  
            	swap(arr[j], arr[j+1]);  
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

	BubbleSort_udit(arr, n);

	printf("Sorted Array is\n");
	for (int i=0; i < n; i++) {
		printf("%d ", (arr[i]));
	}printf("\n");

	return 0;
}