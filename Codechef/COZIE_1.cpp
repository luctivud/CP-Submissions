/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*:::::::::::::J A I  S H R E E  R A M::::::::::::::::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/

#include <bits/stdc++.h>
using namespace std;

/*:::::::::::::::::::SNIPS::::::::::::::::::::::::::::*/

typedef long long lld; typedef unsigned long long llu;

#define  forn(I7, E4) for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define forn1(I7, E4) for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        len(v) ((int)((v).size()))
#define        all(x) (x).begin(), (x).end()
#define       rall(x) (x).rbegin(), (x).rend()
#define            f1 first
#define            s2 second

/*::::::::::::::::::/SNIPS::::::::::::::::::::::::::::*/
/*:::::::::::::::::::UTILS::::::::::::::::::::::::::::*/

const long double EPS = 1e-6;
lld MOD = int(1e9) + 7;
lld &mod = MOD;




// find totient Value complexity O(sqrt(N))
int getPhiVal(int n0n) {
    int result = n0n;
    for (int i = 2; i * i <= n0n; i++) {
        if (n0n % i == 0) {
            while (n0n % i == 0)
                n0n /= i;
            result -= result / i;
        }
    }
    if (n0n > 1)
        result -= result / n0n;
    return result;
}




int isPrime(int n) {
    if(n == 0 || n == 1)
        return false;
    for(lld i=2; i*i<=n; i++)
        if(n%i == 0)
            return false;
    return true;
}





/*:::::::::::::::::::::/UTILS:::::::::::::::::::::::::*/
/*::::::::::::::::::::::LOGIC:::::::::::::::::::::::::*/

/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/
/*::::::::::::::::::::::INVOC:::::::::::::::::::::::::*/
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // cout.precision(10); cout << fixed

        int t=1, n, val;
        cin>>n>>t;

        vector<int> pri;
        pri.push_back(0);
        for(int i=1; i<=n; i++) {
            cin>>val;

            int res = getPhiVal(val);

            if(isPrime(res)) {
                pri.push_back(1);
            } else {
                pri.push_back(0);
            }
        }

        for(int i=2; i<=n; i++)
            pri[i] += pri[i-1];

        while(t--)
        {
            int l, r;
            cin>>l>>r;
            cout<<pri[r] - pri[l-1]<<"\n";
        }
        // int N, Q; cin >> N >> Q;
        // // vector<lld> arr(N);
        // lld arr[N+1] = {0};
        // for (int i = 1; i <= N; i++) {
        //     cin >> arr[i];
        //     int res = getPhiVal(arr[i]);
        //     // _____error_____(arr[i]);
        //     res = lld(isPrime(res));
        //     if (res == 1) {
        //         arr[i] = 1;
        //     } else {
        //         arr[i] = 0;
        //     }
        //     if (i > 1) {
        //         arr[i] += arr[i - 1];
        //     }
        // }
        // // _____error_____(arr);
        // for (int i = 0; i < Q; i++) {
        //     int l, r; cin >> l >> r;
        //     // --l, --r;
        //     lld ans = arr[r];
        //     ans -= arr[l - 1];
        //     cout << ans << "\n";
        // }
        // cout << "\n"; 
    // }

    return 0; 
}


/*:::::::::::::::::::::/INVOC:::::::::::::::::::::::::*/
/*  ~~
Author   :  Udit "luctivud" Gupta 
linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
*/
