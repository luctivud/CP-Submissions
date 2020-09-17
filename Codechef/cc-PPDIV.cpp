/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
   '          .       ,     神 | 光      .     '        .      , 
     .      '        Udit Gupta @luctivud         ,              
  ,    '   ELDIOS | LIGHT | GREED | CIPHER | XAYN | KIRA '    .  
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                **      **  *******  * *  ******
                **      **  **   **  ***    **
                **      **  **    *  * *    **
                ******* **  *******  * *    **
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~| WORSHIPPER OF GREED |~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include <bits/stdc++.h>
using namespace std;
using llu = unsigned long long int;
typedef long long int ll;
typedef long double ldo;
#define MODPRIME 1000000007
#define FASTINPUTOUTPUTLIKELIGHT()          ios_base::sync_with_stdio(false);
#define TESTCASES()                         ll TestCases; cin>>TestCases; while(TestCases--)
#define mp                                  make_pair
#define pb                                  push_back
#define mems(arr,val)                       memset((arr), val, sizeof((arr)))
#define FOREACH(it, ___vect)                for (auto it = ___vect.begin(); it != ___vect.end(); it++)
#define endl                                "\n"

// ////////////////////////////////////////////////////////////////////////////////////////////

#define getx                                getchar_unlocked
#define putx                                putchar_unlocked
#define in(n)                               scanf("%d",&n)s
#define inl(n)                              scanf("%lld",&n)
#define out(n)                              printf("%d",n);
#define outl(n)                             printf("%lld",n);


inline int getint(){  // this getint() is even faster than scanf !!!!!
    // Use it as:
    // int x = getint();s
    char _c;
    int _x=0;
    _c=getx();
    while (_c<=' ') _c=getx();
    while (_c>='0'){ _x=10*_x+(_c-'0'); _c=getx();}
    return _x;
}
inline long long int getllint(){  // this getint() is even faster than scanf !!!!!
    // Use it as:
    // int x = getint();s
    char _c;
    long long int _x=0;
    _c=getx();
    while (_c<=' ') _c=getx();
    while (_c>='0'){ _x=10*_x+(_c-'0'); _c=getx();}
    return _x;
}

// ///////////////////////////////////////////////////////////////////////////////////////////////

vector<char> is_prime(1000001, true);
void seive(){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= 1000001; i++) {
        if (is_prime[i] && (long long)i * i <= 1000001) {
            for (int j = i * i; j <= 1000001; j += i)
                is_prime[j] = false;
        }
    }
}

signed main(){
    // llu dp[1000007] = {0};
    seive();
    FASTINPUTOUTPUTLIKELIGHT()
    TESTCASES(){
        llu n; cin>>n;
        llu ans = 0;
        llu squareroot = sqrt(n);
        // unordered_set <llu> alreadyComputed;
        llu cuberoot = cbrt(n);
        cout << cuberoot << " - " << squareroot << " | ";
        for (llu i = 2; i<=cuberoot; i++){
            if (is_prime[i]) {
                llu divi = i;
                while(true){
                    divi *= i;
                    llu quot = n/divi;
                    llu res = (quot * divi) % MODPRIME;
                    cout << res << " ";
                    ans = (ans + res) % MODPRIME;
                    if (quot <= 1){
                        break;
                    }
                }
            }
        }
        for (llu i = cuberoot+1; i<=squareroot; i++){
                if (is_prime[i]){
                    llu divi = i * i;
                    llu quot = n / divi;
                    // llu res = (divi * quot) % MODPRIME;
                    llu res = (i * i) % MODPRIME;
                    cout << res << " ";
                    ans = (ans + res) % MODPRIME;
                }
                if (i == squareroot) ans = (ans + ((i * i) % MODPRIME)) % MODPRIME;
        }
        if (n == 1) ans = 0;
        // cout<<cuberoot<<" "<<squareroot<<endl;
        cout << (ans + n) % MODPRIME <<endl; 
    }
    return 0;
}
/*
    THE LOGIC AND APPROACH WAS DEVELOPED BY ME @luctivud.
    SOME PARTS OF THE CODE HAS BEEN TAKEN FROM WEBSITES LIKE::
        geeksforgeeks.org
        codeforces
    (I Own the code if no link is provided here or I may have missed mentioning it)
    PLEASE DO NOT PLAGIARISE.
10
65
190
36
144
34
565
1454
23
1
12
    corect ans  
637
2855
292
2177
241
15408
62667
93
1
41
*/