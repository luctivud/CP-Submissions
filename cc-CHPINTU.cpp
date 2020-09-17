/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
  Udit Gupta @luctivud  神 | LIGHT | GREED | CIPHER | XAYN
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                **      **  *******  * *  ******
                **      **  **   **  ***    **
                **      **  **    *  * *    **
                ******* **  *******  * *    **
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    | WORSHIPPER OF GREED |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/* *******   All Required Header Files ********/
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
/********   //All Required Header Files ********/

using namespace std;
using llu = unsigned long long int;
typedef long long int ll;
typedef long double ldo;
#define MOD                                 1000000007
#define FASTIO                              ios_base::sync_with_stdio(false);
#define TESTCASES()                         llu TestCases; cin>>TestCases; while(TestCases--)
#define mp                                  make_pair
#define pb                                  push_back
#define mems(arr,val)                       memset((arr), val, sizeof((arr)))
#define loop(iter, start, end, incr)        for (int iter=start ; i<end ; i+=incr)
#define rloop(iter, start, end, decr)       for (int iter=start ; i>=end ; i-=decr)
#define FOREACH(it, ___vect)                for (auto it = ___vect.begin(); it != ___vect.end(); it++)

void solve(){
    ll n, m;
    cin>>n>>m;
    ll arr[m+1];
    mems(arr,-1);
    ll F[n], P[n];
    loop(i,0,n,1) cin>>F[i];
    loop(i,0,n,1) cin>>P[i];
    loop(i,0,n,1) {
        if (arr[F[i]] == -1) arr[F[i]]=0;
        arr[F[i]] += P[i];
    }
    ll ans = INT8_MAX;
    loop(i,1,m+1,1){
        if (arr[i]!=-1 && arr[i]<ans){
            ans = arr[i];
        }
    }
    cout<<ans<<endl;
    
    return;
}

signed main(){
  FASTIO
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    TESTCASES()
        solve();
    return 0;
}
