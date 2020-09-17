/*  Created by: @luctivud  at 2020-07-09 18:52:09  */

#include <bits/stdc++.h>
using namespace std;

const long long int UGLYMOD {1000000007};
const long long int SEXYMOD {998244353};
const long long int MAXN = 1e6 + 1LL;

typedef long long int lld;

#define GREED_FOR_SPEED               ios_base::sync_with_stdio(false); cin.tie(0)
#define TESTCASES_ARE_THERE()         long long int Test; cin>>Test; while(Test--)
#define mems(arr,val)                 memset((arr), val, sizeof((arr)))
#define FORFWD(itr, start, end, step) for(lld itr = start; itr < end; itr += step)
#define FORBWD(itr, start, end, step) for(lld itr = start; itr > end; itr -= step)
#define endl                          "\n"
// #define println()
// #define input()
inline lld readlld() {
    lld res = 0; char c = 0;
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) res = res*10+c-'0', c = getchar();
    return res;
}


void solveEach() {
    lld n; cin >> n;
    vector <lld> arr(n);
    for(auto &i: arr) cin >> i;
    vector< pair<lld, lld> > ans;
    FORFWD(i, 0, n-1, 1) {
        lld mn = i;
        FORFWD(j, i, n, 1) {
            if (arr[j] < arr[mn]) mn = j;
        }
        if (i ^ mn) {
            ans.push_back(make_pair(i, mn));
            swap(arr[i], arr[mn]);
        }
    }
    cout << ans.size() << "\n";

    for(auto i : ans) {
        cout << i.first << " " << i.second << "\n";
    }
    
    cout << endl;
    return;
}

signed main() {

    // GREED_FOR_SPEED;

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 

    // TESTCASES_ARE_THERE()
        solveEach();
    return 0;
}
/*
THE LOGIC AND APPROACH IS MINE ( UDIT GUPTA )
SOME PARTS OF THE CODE MAY HAVE BEEN TAKEN FROM WEBSITES LIKE::
(I Own the code if no link is provided here or I may have missed mentioning it)
*/