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
    long int n;
    scanf("%ld", &n);
    bool visited[n+1] = {false};
    long int ans = -1;
    for (long int i = 1L; i<n+1; i++) {
        long int x; 
        scanf("%ld", &x);
        vector<long int> arr(x);
        for(long int j = 0; j<x; j++) {
            scanf("%ld", &arr[j]);
        }
        bool flag2 = true;
        for (auto j: arr) {
            if (!visited[j]) {
                visited[j] = true;
                flag2 = false;
                break;
            }
        }
        if (flag2) {
            ans = i;
        }
        arr.clear();
    }
    long int ans2 = -1;
    if (ans != -1) {
        for (long int k=1; k<n+1; k++) {
            if (!visited[k]){
                printf("IMPROVE\n%ld %ld\n", ans, k);
                break;
            }
        }
    } else {
        printf("OPTIMAL\n");
    }
    
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