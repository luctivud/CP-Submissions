// C++ implementation of the above approach 

#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std; 
using namespace __gnu_pbds; 

// Defining the policy based Data Structure 
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> 
	indexed_set; 

// Elements in the array are not unique, 
// so a pair is used to give uniqueness 
// by incrementing cnt and assigning 
// with array elements to insert in mySet 
int cnt = 0; 

// Variable to store the data in the 
// policy based Data Structure 
indexed_set mySet; 

// Function to insert the elements 
// of the array in mySet 
void insert(int n, int arr[]) 
{ 
	for (int i = 0; i < n; i++) { 
		mySet.insert({ arr[i], cnt }); 
		cnt++; 
	} 
} 

// Function to update the value in 
// the data structure 
void update(int x, int y) 
{ 
	// Get the pointer of the element 
	// in mySet which has to be updated 
	auto it = mySet.lower_bound({ y, 0 }); 

	// Delete from mySet 
	mySet.erase(it); 

	// Insert the updated value in mySet 
	mySet.insert({ x, cnt }); 
	cnt++; 
} 

// Function to find the K-th smallest 
// element in the set 
int get(int k) 
{ 
	// Find the pointer to the kth smallest element 
	auto it = mySet.find_by_order(k - 1); 
	return (it->first); 
} 

// Function to perform the queries on the set 
void operations(int arr[], int n, 
				vector<vector<int> > query, int m) 
{ 
	// To insert the element in mySet 
	insert(n, arr); 

	// Iterating through the queries 
	for (int i = 0; i < m; i++) { 

		// Checking if the query is of type 1 
		// or type 2 
		if (query[i][0] == 1) { 

			// The array is 0-indexed 
			int j = query[i][1] - 1; 
			int x = query[i][2]; 

			// Update the element in mySet 
			update(x, arr[j]); 

			// Update the element in the array 
			arr[j] = x; 
		} 
		else { 
			int K = query[i][1]; 

			// Print Kth smallest element 
			cout << get(K) << endl; 
		} 
	} 
} 

// Driver code 
int main() 
{ 
	int n = 5, m = 6, arr[] = { 1, 0, 4, 2, 0 }; 

	vector<vector<int> > query = { { 1, 2, 1 }, 
								{ 2, 2 }, 
								{ 1, 4, 5 }, 
								{ 1, 3, 7 }, 
								{ 2, 1 }, 
								{ 2, 5 } }; 

	operations(arr, n, query, m); 

	return 0; 
} 
