// Created by Udit Gupta (1803210166)
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; 
	cout << "Enter size of array\n";
	cin >> n;

	int arr[n];
	cout << "Enter space seperated array\n";
	for (auto &i : arr) {
		cin >> i;
	}

	int elem;
	cout << "Enter element to be searched\n";
	cin >> elem;

	int found = 0;

	for (int i = 0; i < n; ++i) {
		if (arr[i] == elem) {
			found = i + 1;
			break;
		}
	}

	if (found) {
		cout << "Element found at " << found << " position\n";
	} else {
		cout << "Element not found\n";
	}
	return 0;
}