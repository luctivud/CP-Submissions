#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;

signed main() {
    
    // Input - Output and optimization
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    srand(time(0));
    int maxn = int(1e5);
    int arr[2];
    arr[0] = rand() % maxn + 1;
    arr[1] = arr[0] - (rand() % 1000);
    if (arr[1] < 0) arr[1] = arr[0] + 1000;
    sort(arr, arr+2);
    int s = rand() % (1000);
    if (arr[1] - arr[0] > 1000) {
        arr[0] = 1;
        arr[1] = 100;
    }
    cout << arr[0] << " " << arr[1] << " " << s << "\n";

    return 0;
}
