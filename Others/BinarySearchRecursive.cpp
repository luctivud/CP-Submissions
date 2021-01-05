// Created by Udit Gupta (1803210166)
#include <bits/stdc++.h>

using namespace std;

void BinarySearchRecursive_udit(int arr[], int l, int r, int elem, int &found) {
	if (l > r) return;
	int mid = l + (r - l) / 2;
	if (arr[mid] == elem) {
		found = mid + 1;
		return;
	} else if (arr[mid] < elem) {
		BinarySearchRecursive_udit(arr, mid+1, r, elem, found);
	} else {
		BinarySearchRecursive_udit(arr, l, mid-1, elem, found);
	}
}

int main() {
	int n; 
	cout << "Enter size of array\n";
	cin >> n;

	int arr[n];
	cout << "Enter space seperated array\n";
	for (auto &i : arr) {
		cin >> i;
	}
	// sorting array here if not sorted.
	sort(arr, arr+n);

	int elem;
	cout << "Enter element to be searched\n";
	cin >> elem;

	int found = 0;
	
	BinarySearchRecursive_udit(arr, 0, n-1, elem, found);

	if (found) {
		cout << "Element found at " << found << " position in sorted array\n";
	} else {
		cout << "Element not found\n";
	}
	return 0;
}