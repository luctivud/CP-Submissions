//                           जय श्री राम

#include <bits/stdc++.h>
using namespace std;

const long long int UGLYMOD {1000000007}; const long long int SEXYMOD {998244353};
const long int MAXN = (long int) 1e5;

typedef long long int ll;

#define LUCILLE_IS_THIRSTY()       ios_base::sync_with_stdio(false); cin.tie(0)
#define TESTCASES_ARE_THERE()      long int Test; cin>>Test; while(Test--)

inline int readint() {
    int res = 0; char c = 0; 
    while(!isdigit(c)) c = getchar(); 
    while(isdigit(c)) res = res*10+c-'0', c = getchar();
    return res;
}

void solveEachTestCase(long int Test) {
    
    cout << "\n";
    return;
}

signed main() {

    // LUCILLE_IS_THIRSTY();

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 

    TESTCASES_ARE_THERE()
        solveEachTestCase(Test);

    return 0;
}
/*
THE LOGIC AND APPROACH IS BY ME @luctivud ( UDIT GUPTA )
SOME PARTS OF THE CODE HAS BEEN TAKEN FROM WEBSITES LIKE::
(I Own the code if no link is provided here or I may have missed mentioning it)
>>> DO NOT PLAGIARISE.
TESTCASES:
*/