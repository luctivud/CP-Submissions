#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i) {
  int mx = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[mx])
    mx = l;

  if (r < n && arr[r] > arr[mx])
    mx = r;

  if (mx != i) {
    swap(arr[i], arr[mx]);
    heapify(arr, n, mx);
  }
}

void heapSort_udit(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);

    heapify(arr, i, 0);
  }
}


int main() {
  int size;
  cout << "Enter size of array\n";
  cin >> size;

  int arr[size];
  cout << "Enter space seperated array\n";
  for (auto &i : arr) {
    cin >> i;
  }

  heapSort_udit(arr, size);
  
  cout << "Sorted arr is: \n";
  for (auto i : arr) {
    cout << i << " ";
  }
}