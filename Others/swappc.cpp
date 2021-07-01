#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;

int getval(int anum) {
    int i = anum;
    if (i % 2 == 0) {
        i = i / 2;
    } else {
        i = 3 * i + 1;
    }
    return i;
}

void getdig(int anum) {
    int hlse = anum;
    if (hlse == 1) {
        cout << hlse;
    } else {
        cout << hlse;
        getdig(getval(hlse));
    }
}

int countlen(int anum) {
    int hlse = anum;
    if (hlse == 1) return 1;
    return 1 + countlen(getval(hlse));
}

signed main() {
    
    // Input - Output and optimization
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

    getdig(13);

    #ifdef LUCTIVUD
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    
    return 0;
}
