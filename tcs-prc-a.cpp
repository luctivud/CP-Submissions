
#include <bits/stdc++.h>
using namespace std;

const long long int UGLYMOD {1000000007};
const long long int SEXYMOD {998244353};
const long int MAXN = (long int) 35;

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
int matr[MAXN][MAXN];
long long int dp[MAXN][MAXN];

long long int solve(int i, int j, int n, long long int curr){
    if (i >= n or j >= n)
        return INT_MAX;
    if (i == n-1 and j == n-1)
        dp[i][j] = min(curr/2 + matr[i][j], dp[i][j]);
    if (dp[i][j] > curr/2 + matr[i][j]){
        curr = curr/2 + matr[i][j];
        dp[i][j] = min(dp[i][j], min(solve(i+1, j, n, curr), solve(i, j+1, n, curr)));
    }
    return dp[i][j];
}

void solveEach() {
    int n; cin >> n;
    for (int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> matr[i][j];
    memset(dp, 999999, sizeof(dp));
    // for (int i=0; i<n; i++) for(int j=0; j<n; j++) cout << dp[i][j] << " ";
    cout << solve(0, 0, n, 0);
    cout << endl;
    return;
}

signed main() {

    LUCILLE_IS_THIRSTY();

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif 

    // TESTCASES_ARE_THERE()
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