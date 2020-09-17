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
const ll MODPRIME {1000000007};
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


signed main(){
    bool isPrime[1000000007];
    mems(isPrime, true);
    FASTINPUTOUTPUTLIKELIGHT()
    TESTCASES(){
        llu n; cin>>n;
        llu ans = 0;
        llu i=2;
        while(i*i*i<=n){
            if (isPrime[i]) {
                // cout<< i << " ";
                llu divi = i;
                while(true){
                    divi *= i;
                    if (divi < 1000000006) isPrime[divi]=false;
                    if (divi == 0) break;
                    llu quot = n/divi;
                    llu res = (quot * divi) % MODPRIME;
                    ans = (ans + res) % MODPRIME;
                    if (quot <= 1){
                        break;
                    }
                }
            }
            i+=1;
        }
        // i = sqrt((float)n/2)+1;
        // llu sqrtn = sqrt(n);
        // while (i<=sqrtn) {
        //     if (isPrime[i]) {
        //         // cout<< i << " ";
        //         llu divi = i * i;
        //         if (divi != 0) {
        //             llu quot = n/divi;
        //             if (divi < 1000000006) isPrime[divi]=false;
        //             llu res = (quot * divi) % MODPRIME;
        //             // cout << res << "-" << i << " ";
        //             ans = (ans + res) % MODPRIME;
        //         }
        //     }
        //     i+=1;
        // }
        llu cuberoot = cbrt(n);
        llu x, y, res1, res2;
        llu k = 2;
        while (sqrt(n/k)>cuberoot){
        x = sqrt(n/k)-1;
        y = sqrt(n/(k-1));
        res1 = (((y) * (y+1) * ((2*y)+1))/6)% MODPRIME;
        res2 = (((x) * (x+1) * ((2*x)+1))/6)% MODPRIME;
        ans += ((k-1)*(res1-res2))% MODPRIME;
        k+=1;
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
12
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
41
2855
292
2177
241
15408
62667
93
1
41
---
1
1000000000000000000
1000000000000000000. 18
*/