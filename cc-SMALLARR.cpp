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

#include <bits/stdc++.h>

using namespace std;
using llu = unsigned long long int;
typedef long long int ll;
typedef long double ldo;
#define MODPRIME                            1000000007
#define FASTINPUTOUTPUTLIKELIGHT()          ios_base::sync_with_stdio(false);
#define TESTCASES()                         llu TestCases; cin>>TestCases; while(TestCases--)
#define mp                                  make_pair
#define pb                                  push_back
#define mems(arr,val)                       memset((arr), val, sizeof((arr)))
#define FOREACH(it, ___vect)                for (auto it = ___vect.begin(); it != ___vect.end(); it++)
#define endl                                "\n"

void solve(){
    ll n, x; cin>>n>>x;
    ll arr[n];
    for(ll i=0; i<n; ++i) cin>>arr[i];
    ll startIndex=0, endIndex = 0;
    ll sum = -99999999;
    for (ll i=0; i<n; ++i){
        ll temp = 0;
        for (ll j=i; j<n; j++){
            temp += arr[j];
            if (temp>sum){
                sum = temp;
                startIndex = i;
                endIndex = j;
            }
        }
    }
    ldo ans = 0;
    for (ll i=0; i<n; ++i){
        if (i>=startIndex && i<=endIndex){
            ans += (ldo)arr[i]/x;
        } else {
            ans += (ldo)arr[i];
        }
    }
    cout<<ans<<endl;
    return;
}

signed main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
    FASTINPUTOUTPUTLIKELIGHT()
    // TESTCASES()
        solve();
    return 0;
}

/* *******   All Required Header Files ********/
// REMEMBER THEY EXIST //
// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <sstream>
// #include <queue>
// #include <deque>
// #include <bitset>
// #include <iterator>
// #include <list>
// #include <stack>
// #include <map>
// #include <set>
// #include <functional>
// #include <numeric>
// #include <utility>
// #include <limits>
// #include <time.h>
// #include <math.h>
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <assert.h>
/********   //All Required Header Files ********/