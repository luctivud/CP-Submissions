#include <bits/stdc++.h>

using namespace std;

signed main() {

	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int ptr1 = 0, ptr2 = 2;
	int ans = 0;

	while (ptr2 < n) {
		while (ptr2 < n and arr[ptr1] + arr[ptr1 + 1] > arr[ptr2]) {
			ptr2++;
		}
		ans = max(ans, ptr2 - ptr1);
		ptr1++;
		ptr2 = max(ptr2, ptr1+2);
	}

	cout << (ans > 2 ? ans : -1);

	return 0;
}
