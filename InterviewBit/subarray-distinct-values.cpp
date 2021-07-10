#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    }
};


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    int64_t ans = 0ll;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // map to store count of elements which are present in our sliding window
    // unordered_map with custom hash just to avoid hash collision
    unordered_map<int, int, custom_hash> countOfElements;

    /*
     startingIndex is the fixed index to the start, 
     endingIndex is moving-end of the window
     currentCount is the total distinct elements present in our window
     Idea : To fix staringIndex and then calculate the maximum subarray with K or less distinct elements
     using the approach by Akash Sir. 
     Then if we have first the first end of the subarray, the total possible arrays will be 
     (endingIndex - startingIndex) as we can choose any end and all of the arrays will have K or less distinct
     [
        If any set has K or less distinct elements, 
        then all of its subsets will have K or less distinct elements too.
     ]
    */
    for (int startingIndex = 0, endingIndex = 0, currentCount = 0; 
            startingIndex < n; 
            startingIndex++) {
        while (endingIndex < n && currentCount <= k) {
            // if including this index causes currentCount exceed k
            if (countOfElements[arr[endingIndex]] == 0 and currentCount == k) {
                break;
            }
            // a new element is found
            if (countOfElements[arr[endingIndex]] == 0) {
                currentCount += 1;
            }
            countOfElements[arr[endingIndex]] += 1;
            endingIndex++;
        }

        // assertion if everything worked fine.
        assert(currentCount <= k);
        ans += (int64_t)(endingIndex - startingIndex);

        // if removing the first element causes any distinct element to disappear
        if (--countOfElements[arr[startingIndex]] == 0) currentCount--;
    }
    cout << ans << "\n";

    return 0;
}
