#include<bits/stdc++.h>
using namespace std;


// solution to check if brute force is helpful or not.
// taken from geeksforgeeks.

// Returns split point. If not possible, then
// return -1.

int ans = 0;
int findSplitPoint(vector<int>&arr, int n)
{
    // traverse array element and compute sum
    // of whole array
    int leftSum = 0;
    for (int i = 0 ; i < n ; i++)
        leftSum += arr[i];

    // again traverse array and compute right sum
    // and also check left_sum equal to right
    // sum or not
    int rightSum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        // add current element to right_sum
        rightSum += arr[i];

        // exclude current element to the left_sum
        leftSum -=  arr[i] ;

        if (rightSum == leftSum)
            return i ;
    }

    // if it is not possible to split array
    // into two parts.
    return -1;
}

// Prints two parts after finding split point using
// findSplitPoint()
void printTwoParts(vector<int> &arr, int n)
{
    int splitPoint = findSplitPoint(arr, n);

    if (splitPoint == -1 || splitPoint == n )
    {
        // cout << "Not Possible" <<endl;
        return;
    }
    ans++;
}

// driver program

#define all(arr) (arr).begin(), (arr).end()
int main()
{
    int t; cin >> t;
    while (t--) {
    // for (int ss = 1; ss < 100; ss++) {

        int ss; cin >> ss;
        ans = 0;
        vector<int> arr(ss);
        iota(all(arr), 1);

        // for(auto i : arr) {
        //     cout << i << " ";
        // }
        // vector<int> arr {1, 2, 3, 4};
        int n = int(arr.size());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                vector<int> brr{arr};
                swap(brr[i], brr[j]);
                printTwoParts(brr, n);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
