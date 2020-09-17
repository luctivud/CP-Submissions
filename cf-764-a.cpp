//         जय श्री राम          //

#include <bits/stdc++.h>
using namespace std;

const long long int UGLYMOD {1000000007};
const long long int SEXYMOD {998244353};
const long long int MAXN = 1e6 + 1;

typedef long long int lld;

#define GREED_FOR_SPEED            ios_base::sync_with_stdio(false); cin.tie(0)
#define TESTCASES_ARE_THERE()      long long int Test; cin>>Test; while(Test--)
#define mems(arr,val)              memset((arr), val, sizeof((arr)))
#define endl                       "\n"

inline int readint() {
    int res = 0; char c = 0;
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) res = res*10+c-'0', c = getchar();
    return res;
}


void solveEach() {
    lld a, b, n;
    cin >> a >> b >> n;
    
    a = (a*b) / __gcd(a, b);

    cout << n / a;
    cout << endl;
    return;
}

signed main() {

    GREED_FOR_SPEED;

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 

    // TESTCASES_ARE_THERE()
        solveEach();
    return 0;
}
/*
THE LOGIC AND APPROACH IS BY ME @luctivud ( UDIT GUPTA )
SOME PARTS OF THE CODE HAS BEEN TAKEN FROM WEBSITES LIKE::
(I Own the code if no link is provided here or I may have missed mentioning it)
>>> DO NOT PLAGIARISE.
*/