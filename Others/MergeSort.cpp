#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;

	int L[n1], M[n2];
	for (int i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (int j = 0; j < n2; j++)
		M[j] = arr[q + 1 + j];

	int i = 0, j = 0, k = p;
	while (i < n1 && j < n2) {
		if (L[i] <= M[j]) {
			arr[k++] = L[i++];
		} else {
			arr[k++] = M[j++];
		}
	}

	while (i < n1) {
		arr[k++] = L[i++];
	}

	while (j < n2) {
		arr[k++] = M[j++];
	}
}


void mergeSort_udit(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort_udit(arr, l, m);
		mergeSort_udit(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}



int main() {
	int size; 
	cout << "Enter the size of array\n";
	cin >> size;

	int arr[size];
	cout << "Enter space seperated array\n";
	for (auto &i : arr) {
		cin >> i;
	}

	mergeSort_udit(arr, 0, size - 1);

	cout << "Sorted array is: \n";
	for (auto i : arr) {
		cout << i << " ";
	}

	return 0;
}