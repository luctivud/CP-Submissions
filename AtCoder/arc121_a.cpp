//  J A I  S H R E E  R A M  //

#include <bits/stdc++.h>

#pragma GCC optimize "trapv"
// #pragma GCC optimize ("Ofast")
// // #pragma GCC target ("fpmath=sse,sse2")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize ("-ffloat-store")


using namespace std;

typedef long long int lld;
typedef unsigned long long int llu;

#define        forn(I7, E4)    for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define       forn1(I7, E4)    for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  f1    first
#define                  s2    second

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type >
ostream & operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cout << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << H << ", "; dbg_out(T...);}
#define _____error_____(...) cout << #__VA_ARGS__ << " : ", dbg_out(__VA_ARGS__)

const lld d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const lld d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};


const long double EPS = 1e-6;
lld TempVar, mod, MOD;


/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/






void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n; cin >> n;
    vector<array<lld, 3ll>> arr(n);
    forn(i, n) {
    	cin >> arr[i][0] >> arr[i][1];
    	arr[i][2] = i;
    }

    map<pair<lld, lld>, lld> nums;

    sort(all(arr), [](auto &a, auto &b) {
    	return a[0] < b[0];
    });


    nums[{min(arr[0][2], arr[n-1][2]), max(arr[0][2], arr[n-1][2])}] = 
    max(llabs(arr[0][0] - arr[n-1][0]), 
    	nums[{min(arr[0][2], arr[n-1][2]), max(arr[0][2], arr[n-1][2])}]);


    nums[{min(arr[0][2], arr[n-2][2]), max(arr[0][2], arr[n-2][2])}] = 
    max(llabs(arr[0][0] - arr[n-2][0]), 
    	nums[{min(arr[0][2], arr[n-2][2]), max(arr[0][2], arr[n-2][2])}]);

    nums[{min(arr[1][2], arr[n-1][2]), max(arr[1][2], arr[n-1][2])}] = 
    max(llabs(arr[1][0] - arr[n-1][0]), 
    	nums[{min(arr[1][2], arr[n-1][2]), max(arr[1][2], arr[n-1][2])}]);


    sort(all(arr), [](auto &a, auto &b) {
    	return a[1] < b[1];
    });

    nums[{min(arr[0][2], arr[n-1][2]), max(arr[0][2], arr[n-1][2])}] = 
    max(llabs(arr[0][1] - arr[n-1][1]), 
    	nums[{min(arr[0][2], arr[n-1][2]), max(arr[0][2], arr[n-1][2])}]);


    nums[{min(arr[0][2], arr[n-2][2]), max(arr[0][2], arr[n-2][2])}] = 
    max(llabs(arr[0][1] - arr[n-2][1]), 
    	nums[{min(arr[0][2], arr[n-2][2]), max(arr[0][2], arr[n-2][2])}]);

    nums[{min(arr[1][2], arr[n-1][2]), max(arr[1][2], arr[n-1][2])}] = 
    max(llabs(arr[1][1] - arr[n-1][1]), 
    	nums[{min(arr[1][2], arr[n-1][2]), max(arr[1][2], arr[n-1][2])}]);

    vector<lld> res;

    for (auto [ke, va] : nums) {
    	res.push_back(va);
    }

    sort(rall(res));
    cout << res[1];

    // lld ans = 0ll;


    // ans = max({
    // 	ans, 
    // 	llabs(arr[0][0] - arr[n-2][0]),
    // 	llabs(arr[1][0] - arr[n-1][0])
    // });

    // sort(all(arr), [](auto &a, auto &b) {
    // 	return a.s2 < b.s2;
    // });

    // ans = max({
    // 	ans, 
    // 	llabs(arr[0].s2 - arr[n-2].s2),
    // 	llabs(arr[1].s2 - arr[n-1].s2)
    // });
    // cout << ans;

    // vector<lld> res;

    // forn(i, n-1) {
    // 	res.push_back(max(llabs(arr[i+1].f1 - arr[i].f1), llabs(arr[i+1].s2 - arr[i].s2)));
    // }

    // sort(rall(res));

    // _____error_____(arr);
    // _____error_____(res);

    // cout << res[1];

    
    return;
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // cout.precision(10); cout << fixed;
    #ifdef LUCTIVUD
      // const auto start_time = std::chrono::high_resolution_clock::now();
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif


    MOD = mod = lld(1e9) + 7ll;
    lld _T0T4 = 1;
    // cin >> _T0T4; 

    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
        cout << "\n"; 
    }


    #ifdef LUCTIVUD
      // auto end_time = std::chrono::high_resolution_clock::now();
      // std::chrono::duration<double> diff = end_time - start_time;
      // cerr << "Finished in : " << diff.count() << "\n";
    #endif

    return 0; 
}


/*  ~~
Author   :  Udit "luctivud" Gupta 
linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
*/
