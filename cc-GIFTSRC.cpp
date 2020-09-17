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

using   namespace   std;
using   llu = unsigned long long int;
typedef       long long int     ll;
typedef       long double       ldo;
const   ll    MODPRIME          {1000000007} ;
#define FASTINPUTOUTPUTLIKELIGHT()          ios_base::sync_with_stdio(false);
#define TESTCASES()                         ll TestCases; cin>>TestCases; while(TestCases--)
#define mp                                  make_pair
#define pb                                  push_back
#define mems(arr,val)                       memset((arr), val, sizeof((arr)))
#define FOREACH(it, ___vect)                for (auto it = ___vect.begin(); it != ___vect.end(); it++)
#define endl                                "\n"

void solve();

signed main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
    FASTINPUTOUTPUTLIKELIGHT()
    TESTCASES()
        solve();
    return 0;
}
void solve(){
    ll n; cin>>n;
    string s; cin>>s;
    ll x =0; ll y= 0;
    ll prev = -1; ll nxt;
    for (ll i=0; i<n; ++i){
        if (s[i] == 'U' || s[i] == 'D'){
            nxt = 1;
        } else {
            nxt = 0;
        }
        if (nxt != prev){
            prev = nxt;
            if(nxt){
                if (s[i] == 'U') y+=1;
                else y-=1;
            } else{
                if(s[i] == 'R') x+=1;
                else x-=1;
            }
        } else {
            continue;
        }
    }
    cout<<x<<" "<<y<<endl ;
    return;
}