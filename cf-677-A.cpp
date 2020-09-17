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

void solve(){
  llu n, k;
  cin>>n>>k;
  llu sing =0, doub = 0;
  for (llu i=0; i<n; i++){
    llu x; cin>>x;
    if (x>k) doub+=1;
    else sing += 1;
  }
  cout<<(doub*2)+sing<<endl;
  return;
}

signed main(){
  FASTIO
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    // TESTCASES()
        solve();
    return 0;
}
