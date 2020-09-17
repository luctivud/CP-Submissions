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
#define FOREACH(it, ___vect)                for (auto it = ___vect.begin(); it != ___vect.end(); it++)
#define endl                                "\n"

void solve(){
    ll n, k ;
    cin>>n>>k;
    ll a[n+1] = {0};
    ll count =0;
    string temp;
    getline(cin, temp);
    for (ll i=0; i<k; i++){
        string s;
        getline(cin, s);
        ll start = 6; ll val =0;
        if (s[5] == ' '){
            while(start<s.size()){
                val = val*10 + (s[start]-'0');
                start += 1;
            }
            if (a[val] == 0){ a[val] = 1; count+=1; }
            else { a[val] = 0; count -= 1; }
        } else {
            mems(a,0);
            count = 0;
        }
        cout<<count<<endl;
    }
    return;
}

signed main(){
  FASTIO
  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt","r",stdin);
  //   freopen("output.txt","w",stdout);
  // #endif
    // TESTCASES()
        solve();
    return 0;
}
