//                           जय श्री राम

#include <bits/stdc++.h>
using namespace std;

const long long int UGLYMOD {1000000007};
const long long int SEXYMOD {998244353};
const long int MAXN = (long int) 1e6;

typedef long long int ll;

#define LUCILLE_IS_THIRSTY()       ios_base::sync_with_stdio(false); cin.tie(0)
#define TESTCASES_ARE_THERE()      long int Test; cin>>Test; while(Test--)
#define mems(arr,val)              memset((arr), val, sizeof((arr)))
#define endl                       "\n"

inline int readint() {
    int res = 0; char c = 0;
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) res = res*10+c-'0', c = getchar();
    return res;
}


void solveEach() {

    unsigned long long int I, B, N;

    scanf("%llu %llu %llu", &I, &B, &N);

    for(unsigned long long int i=0; i < N ; i++) {
        unsigned long long int x, y, z;
        scanf("%llu %llu %llu", &x, &y, &z);
    }
    unsigned long long int ans =  I-1;
    bool flag = false;

    if (B & 1) {
        flag = true;
    }
    B = B >> 1;
    ans += B;
    printf("%llu", ans);
    if (flag) {
        printf(".5");
    } else {
        printf(".0");
    }
    printf("\n");
    // printf("%.1lf\n", (II + (BB/2) - 1));
    return;
}

signed main() {

    // LUCILLE_IS_THIRSTY();

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 

    TESTCASES_ARE_THERE()
        solveEach();
    return 0;
}
/*
THE LOGIC AND APPROACH IS BY ME @luctivud ( UDIT GUPTA )
SOME PARTS OF THE CODE HAS BEEN TAKEN FROM WEBSITES LIKE::
(I Own the code if no link is provided here or I may have missed mentioning it)
>>> DO NOT PLAGIARISE.
TESTCASES:
*/