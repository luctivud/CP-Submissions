/*  Created by: @luctivud  at 2020-07-10 08:53:02  */

#include <bits/stdc++.h>
using namespace std;

const long long int UGLYMOD {1000000007};
const long long int SEXYMOD {998244353};
const long long int MAXN = 1e6 + 1LL;

typedef long long int lld;

#define                 GREED_FOR_SPEED   ios_base::sync_with_stdio(false); cin.tie(0)
#define           TESTCASES_ARE_THERE()   long long int Test; cin>>Test; while(Test--)
#define                   mems(arr,val)   memset((arr), val, sizeof((arr)))
#define   FORFWD(itr, start, end, step)   for(lld itr = start; itr < end; itr += step)
#define   FORBWD(itr, start, end, step)   for(lld itr = start; itr > end; itr -= step)
#define                            endl   "\n"
#define            FOREACH(___vec, itr)   for(auto itr = ___vec.begin(); itr != ___vec.end(); itr++)
#define                   INPUT(___vec)   for(auto &___vec___itr : ___vec) cin >> ___vec___itr
#define                              PI   3.1415926535897932384626433832795
#define                            INFF   1000000000000000005LL;
#define                    ALL(___vect)   ___vect.begin(), ___vect.end()
#define              LEN(___vecx, Type)   (Type) ___vecx.size()


template<typename T> void scan(T &x) { 
    x = 0; bool neg = 0; 
    register T c = getchar();
    if (c == '-') neg = 1, c = getchar();
    while ((c < 48) || (c > 57)) c = getchar();
    for ( ; c < 48||c > 57 ; c = getchar());
    for ( ; c > 47 && c < 58; c = getchar() ) x= (x << 3) + ( x << 1 ) + ( c & 15 );
    if (neg) x *= -1;
}


void printYesNo(bool Expr, int YNType = 1) { 
    if (YNType == 1) puts(Expr ? "YES" : "NO");
    else if (YNType == 2) puts(Expr ? "Yes" : "No");
    else if (YNType == 3) puts(Expr ? "yes" : "no");
}


void solveEach() {
    int n; scan(n);
    int pos = 0, neg = 0;
    FORFWD(i, 0, n, 1) {
        int temp; scan(temp);
        if(temp < 0) neg += (-temp);
        else pos += temp;
    }
    cout << pos + neg << endl;
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
(I Own the code if no link is provided here or I may have missed mentioning it)ch|=spacelo &=_up change case
*/