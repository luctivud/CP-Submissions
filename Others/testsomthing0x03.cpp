#include <bits/stdc++.h>
using namespace std;

signed main() {
    deque<int> a{1, 2, 3, 4, 5};
    for (auto i : a) {
        cout << i << " ";
        a.push_back(i);
    }
    return 0;
}
