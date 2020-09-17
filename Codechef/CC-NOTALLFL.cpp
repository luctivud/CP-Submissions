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

// #include <bits/stdc++.h>
/* *******   All Required Header Files ********/
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
    llu n,k; cin>>n>>k;
    int boo[k+1] = {0};
    int arr[n+1] = {0};
    loop(i,1,n+1,1) cin>>arr[i];
    ll c = 0;
    ll count = 0;
    ll mx = -1;
    loop(i,1,n+1,1){
        count+=1;
        if (boo[arr[i]] == 0){
            c+=1;
            boo[arr[i]] = 1;
            if (c==k){
                mx = max(mx,count-1);
                c=0;
                count = 0;
                mems(boo,0);
                i--;
            }
        }
    }
    cout<<max(mx,count)<<endl;
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
