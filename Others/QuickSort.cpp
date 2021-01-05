#include <bits/stdc++.h>
using namespace std;


int partition(int arr[], int l, int r) {
  int pivot = arr[r];
  int i = (l - 1);

  for (int j = l; j < r; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[r]);
  return (i + 1);
}

void quickSort_udit(int arr[], int l, int r) {
  if (l < r) {
    int pi = partition(arr, l, r);
    quickSort_udit(arr, l, pi - 1);
    quickSort_udit(arr, pi + 1, r);
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

  quickSort_udit(arr, 0, size - 1);
  cout << "Sorted arr is: \n";
  for (auto i : arr) {
    cout << i << " ";
  }
}
