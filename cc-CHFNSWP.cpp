#include<bits/stdc++.h>
using namespace std;



#define all(arr) (arr).begin(), (arr).end()
int main()
{
    // for (int ss = 1; ss < 100; ss++) {
    int t; cin >> t;
    vector<int> arr = {0, 0, 2, 2, 0, 0, 3, 3, 0, 0, 4, 4, 0, 0, 5, 5, 0, 0, 6, 112, 0, 0, 7, 8, 0, 0, 9, 9, 0, 0, 10, 10, 0, 0, 11, 11, 0, 0, 12, 12, 0, 0, 13, 14, 0, 0, 14, 15, 0, 0, 16, 16, 0, 0, 17, 17, 0, 0, 18, 18, 0, 0, 19, 19, 0, 0, 20, 21, 0, 0, 21, 22, 0, 0, 23, 23, 0, 0, 24, 24, 0, 0, 25, 25, 0, 0, 26, 26, 0, 0, 27, 28, 0, 0, 28, 29, 0, 0, 30, 30, 0, 0, 31, 31, 0, 0, 32, 32, 0, 0, 33, 33, 0, 0, 34, 35, 0, 0, 4116, 36, 0, 0, 37, 37, 0, 0, 38, 38, 0, 0, 39, 39, 0, 0, 40, 40, 0, 0, 41, 42, 0, 0, 43, 43, 0, 0, 44, 44, 0, 0, 45, 45, 0, 0, 46, 46, 0, 0, 47, 48, 0, 0, 48, 49, 0, 0, 50, 50, 0, 0, 51, 51, 0, 0, 52, 52, 0, 0, 53, 53, 0, 0, 54, 55, 0, 0, 55, 56, 0, 0, 57, 57, 0, 0, 58, 58, 0, 0, 59, 59, 0, 0, 60, 60, 0, 0, 61, 62, 0, 0, 62, 63, 0, 0, 64, 64, 0, 0, 65, 65, 0, 0, 66, 66, 0, 0, 67, 67, 0, 0, 68, 69, 0, 0, 69, 70, 0, 0, 71, 71, 0, 0, 72, 72, 0, 0, 73, 73, 0, 0, 74, 74, 0, 0, 75, 76, 0, 0, 77, 77, 0, 0, 78, 78, 0, 0, 79, 79, 0, 0, 80, 80, 0, 0, 81, 81, 0, 0, 82, 83, 0, 0, 84, 84, 0, 0, 85, 85, 0, 0, 86, 86, 0, 0, 87, 87, 0, 0, 88, 89, 0, 0, 89, 90, 0, 0, 91, 91, 0, 0, 92, 92, 0, 0, 93, 93, 0, 0, 94, 94, 0, 0, 95, 96, 0, 0, 96, 97, 0, 0, 98, 98, 0, 0, 99, 99, 0, 0, 100, 100, 0, 0, 101, 101, 0, 0, 102, 103, 0, 0, 103, 104, 0, 0, 105, 105, 0, 0, 106, 106, 0, 0, 107, 107, 0, 0, 108, 108, 0, 0, 109, 110, 0, 0, 110, 111, 0, 0, 112, 112, 0, 0, 113, 113, 0, 0, 114, 114, 0, 0, 115, 115, 0, 0, 116, 117, 0, 0, 118, 118, 0, 0, 119, 119, 0, 0, 120, 120, 0, 0, 121, 121, 0, 0, 122, 122, 0, 0, 123, 124, 0, 0, 125, 125, 0, 0, 126, 126, 0, 0, 127, 127, 0, 0, 128, 128, 0, 0, 129, 130, 0, 0, 130, 131, 0, 0, 132, 132, 0, 0, 133, 133, 0, 0, 134, 134, 0, 0, 135, 135, 0, 0, 136, 137, 0, 0, 137, 138, 0, 0, 139, 139, 0, 0, 140, 140, 0, 0, 141, 141, 0, 0, 142, 142, 0, 0, 143, 144, 0, 0, 144, 145, 0, 0, 146, 146, 0, 0, 147};
    while (t--) {
        int n; cin >> n;
        cout << arr.at(n-1) << "\n";
    }
    return 0;
}


// The above list was generated using :

// #include<bits/stdc++.h> 
// using namespace std; 
  
// // Returns split point. If not possible, then 
// // return -1. 

// int ans = 0;
// int findSplitPoint(vector<int>&arr, int n) 
// { 
//     // traverse array element and compute sum 
//     // of whole array 
//     int leftSum = 0; 
//     for (int i = 0 ; i < n ; i++) 
//         leftSum += arr[i]; 
  
//     // again traverse array and compute right sum 
//     // and also check left_sum equal to right 
//     // sum or not 
//     int rightSum = 0; 
//     for (int i=n-1; i >= 0; i--) 
//     { 
//         // add current element to right_sum 
//         rightSum += arr[i]; 
  
//         // exclude current element to the left_sum 
//         leftSum -=  arr[i] ; 
  
//         if (rightSum == leftSum) 
//             return i ; 
//     } 
  
//     // if it is not possible to split array 
//     // into two parts. 
//     return -1; 
// } 
  
// // Prints two parts after finding split point using 
// // findSplitPoint() 
// void printTwoParts(vector<int> &arr, int n) 
// { 
//     int splitPoint = findSplitPoint(arr, n); 
  
//     if (splitPoint == -1 || splitPoint == n ) 
//     { 
//         // cout << "Not Possible" <<endl; 
//         return; 
//     } 
//     ans++;
// } 
  
// // driver program 

// #define all(arr) (arr).begin(), (arr).end()
// int main() 
// { 
//     int ssr; cin >> ssr;
//     for (int ss = 300; ss < ssr; ss++) {
//         ans = 0;
//         vector<int> arr(ss); 
//         iota(all(arr), 1);

//         // for(auto i : arr) {
//         //     cout << i << " ";
//         // }
//         // vector<int> arr {1, 2, 3, 4};
//         int n = int(arr.size());
//         for (int i = 0; i<n; i++) {
//             for (int j = i+1; j < n; j++) {
//                 vector<int> brr{arr};
//                 swap(brr[i], brr[j]);
//                 printTwoParts(brr, n); 
//             }
//         }
//         cout <<  ans <<  ", ";
//     }
//     return 0; 
// } 
