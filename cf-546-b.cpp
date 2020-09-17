/*  Created by: @luctivud  at 2020-07-10 12:16:05  */

#include <bits/stdc++.h>
using namespace std;

const long long int UGLYMOD {1000000007};
const long long int SEXYMOD {998244353};
const long long int MAXN = 1e6 + 1LL;

typedef string STR;
typedef long long int lld;
typedef vector<int> v_int;
typedef vector<lld> v_lld;
typedef pair<int, int> p_int;
typedef pair<lld, lld> p_lld;


#define                 GREED_FOR_SPEED   ios_base::sync_with_stdio(false); cin.tie(0)
#define           TESTCASES_ARE_THERE()   lld Test; _scan(Test); while(Test--)
#define                   mems(arr,val)   memset((arr), val, sizeof((arr)))
#define   FORFWD(itr, start, end, step)   for(lld itr = start; itr < end; itr += step)
#define   FORBWD(itr, start, end, step)   for(lld itr = start; itr > end; itr -= step)
#define                            endl   "\n"
#define            FOREACH(___vec, itr)   for(auto itr = ___vec.begin(); itr != ___vec.end(); itr++)
#define                   INPUT(___vec)   for(auto &___vec___itr : ___vec) _scan(___vec___itr)
#define                              PI   3.1415926535897932384626433832795
#define                            INFF   1000000000000000005LL;
#define                    ALL(___vect)   ___vect.begin(), ___vect.end()
#define              LEN(___vecx, Type)   (Type) ___vecx.size()
#define                          un_map   unordered_map
#define                          un_set   unordered_set


template<typename T> void _scan(T &x) { 
    x = 0; bool neg = 0; 
    register T c = getchar();
    if (c == '-') neg = 1, c = getchar();
    while ((c < 48) || (c > 57)) c = getchar();
    for ( ; c < 48||c > 57 ; c = getchar());
    for ( ; c > 47 && c < 58; c = getchar() ) x= (x << 3) + ( x << 1 ) + ( c & 15 );
    if (neg) x *= -1;
}


void printYesNo(bool Expr, int YNType = 1, string FirstChoice = "Ud", string SecondChoice = "Ud") { 
    if (YNType == 1) puts(Expr ? "YES" : "NO");
    else if (YNType == 2) puts(Expr ? "Yes" : "No");
    else if (YNType == 3) puts(Expr ? "yes" : "no");
    else if (YNType == 4) cout << (Expr ? FirstChoice : SecondChoice);
}


void solveEach() {
    int n; _scan(n);
    v_int arr(n); map<int, int> count;
    INPUT(arr);
    sort(ALL(arr));
    int ans = 0;
    FOREACH(arr, i) count[*i]++;
    FORFWD(i, 0, 2*n, 1) {
        if (count[i] > 1) {
            int dif = count[i] - 1;
            count[i+1] += dif;
            ans += dif;
        }
    }
    cout << ans;
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