// Program by Udit Gupta
#include <bits/stdc++.h>

int BinarySearch_udit(int arr[], int l, int r, int val) {
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == val) {
			return mid;
		} else if (arr[mid] > val) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	return -1;
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

	std::sort(arr, arr+n);

	int val;
	printf("Enter the value to be searched\n");
	scanf("%d", &val);

	int ans = BinarySearch_udit(arr, 0, n, val);

	if (ans + 1) {
		printf("Element found at %d\n", ans);
	} else {
		printf("Element not found\n");
	}

	return 0;
}