#include<bits/stdc++.h>
class CornerZeros {
public:
	std::vector<int> cornerZeros(std::vector<int> arr) {
		// Code here
		int i = 0, j = 0, n = (int)arr.size();
		while (j < n) {
			while (i < n and arr[i] != 0) {
				i++;
			}
			if (j < i) j = i;
			if (j < n and arr[j] == 0) {
				j++;
			}
			// std::cout << i << " " << j;
			if (i < n and j < n) {
				std::swap(arr[i], arr[j]);
			}
		}
		return arr;
	}
};

int main() {
	CornerZeros c;
	for (auto i : c.cornerZeros({0, 1, 2, 0, 3, 0})) {
		std::cout << i << " ";
	}
	return 0;
}