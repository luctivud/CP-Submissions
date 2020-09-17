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
using llu = long long int;
// typedef long long int ll;
typedef long double ldo;
#define MOD                                 1000000007
#define FASTIO                              ios_base::sync_with_stdio(false);
#define TESTCASES()                         llu TestCases; cin>>TestCases; while(TestCases--)
#define mp                                  make_pair
#define pb                                  push_back
#define mems(arr,val)                       memset((arr), val, sizeof((arr)))
#define forf(iter, start, end, incr)        for (llu iter=start ; i<end ; i+=incr)
#define forr(iter, start, end, decr)        for (llu iter=start ; i>=end ; i-=decr)
#define FOREACH(it, ___vect)                for (auto it = ___vect.begin(); it != ___vect.end(); it++)

struct Point { 
    llu x; 
    llu y; 
}; 

bool onSegment(Point p, Point q, Point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
 
    return false; 
} 
 
llu orientation(Point p, Point q, Point r) { 
    llu val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
    if (val == 0) return 0; 
    return (val > 0)? 1: 2; 
} 
  
bool doIntersect(Point p1, Point q1, Point p2, Point q2) { 
    llu o1 = orientation(p1, q1, p2); 
    llu o2 = orientation(p1, q1, q2); 
    llu o3 = orientation(p2, q2, p1); 
    llu o4 = orientation(p2, q2, q1); 
 
    if (o1 != o2 && o3 != o4) 
        return true; 
 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
 
    return false; // Doesn't fall in any of the above cases 
}  
void solve(){
    llu n , q;
    cin>>n>>q;
    // cout<<n;
    llu a[n];
    for(llu i=0; i<n; i++) cin>>a[i];
    Point points[n-1];
    for(llu i=0; i<n; i++){
        points[i] = {i+1, a[i]};
    }
    for(llu k=0;k<q;k+=1){
        llu x1,x2,y0;
        cin>>x1>>x2>>y0;
        Point p2 = {x1, y0}, q2 = {x2, y0}; 
        llu count =0;
        for(llu j=0;j<n-1;j+=1){
            Point p1 = points[j], q1 = points[j+1]; 
            bool flag = true;
            if (p1.x == q2.x && p1.y == q2.y) flag = false;
            if (p2.x == q1.x && p2.y == q1.y) flag = false;
            if (flag && doIntersect(p1, q1, p2, q2)){
                // printf("%lld %lld  %lld %lld\n",p1.x,p1.y,q1.x,q1.y);
                // printf("%lld %lld  %lld %lld\n",p2.x,p2.y,q2.x,q2.y);
                count+=1;
            }
            // cout<<i<<j;
        }
        cout<<count<<endl;
    }
  
    return;
}

signed main(){
//   FASTIO
//   #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//   #endif
    TESTCASES()
        solve();
    return 0;
}