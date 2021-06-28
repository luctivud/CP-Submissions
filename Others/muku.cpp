#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;


int solve(int a[] , int n) 
{
    int res = a[0];
    for (int i = 1; i < n; i++) {
        res = res ^ a[i];
    }
    return res;
}

signed main() {
    
    // Input - Output and optimization
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    int a[] = {2, 14, 8, 22, 2, 34, 22, 6, 6, 14, 8};

    cout << solve(a, sizeof(a)/sizeof(a[0]));

    return 0;
}

