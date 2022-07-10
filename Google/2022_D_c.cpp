/*          J  A  I   S  H  R  E  E   R  A  M          */
#ifdef LUCTIVUD
#include <mydebug.h>
pprint:: PrettyPrinter NonIterable;
#define cerr cout
#else
#include <bits/stdc++.h>
using namespace std;
#define _____error_____(...)
#endif


#pragma GCC optimize("O3,unroll-loops,trapv")
// #pragma GCC target("avx,avx2,fma,sse,sse2,sse3,sse4,popcnt,lzcnt")
// #pragma GCC optimize "trapv"



typedef long long lld; typedef unsigned long long llu;

#define  forn(I7, E4) for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define forn1(I7, E4) for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        len(v) ((int)((v).size()))
#define        all(x) (x).begin(), (x).end()
#define       rall(x) (x).rbegin(), (x).rend()
#define            f1 first
#define            s2 second


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};





const lld MOD = int(1e9) + 7;
const lld &mod = MOD;

const long double EPS = 1e-6;

const lld inf = 2e18;










/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/



lld solve(lld ind, lld currPos, vector<vector<lld>> &dp, vector<lld> &chrs, vector<lld> &keyb, vector<set<lld>> &posNum) {
    // _____error_____(ind, currPos);
    if (ind+1 == (lld)chrs.size()) {
        return 0;
    }
    lld &res = dp[ind][currPos];
    if (res != -1) {
        return res;
    }
    res = inf;
    ind += 1;
    auto nextInd = posNum[chrs[ind]].lower_bound(currPos);
    if (nextInd != posNum[chrs[ind]].end() and *nextInd == currPos) {
        // _____error_____(ind, *nextInd);
        res = min(res, solve(ind, currPos, dp, chrs, keyb, posNum));
    } else {
        if (nextInd != posNum[chrs[ind]].end())
            // _____error_____(*nextInd);
            res = min(res, llabs(currPos - *nextInd) + solve(ind, *nextInd, dp, chrs, keyb, posNum));
        if (nextInd != posNum[chrs[ind]].begin()) {
            auto prevInd = prev(nextInd);
            res = min(res, llabs(currPos - *prevInd) + solve(ind, *prevInd, dp, chrs, keyb, posNum));
        }
    }
    return res;
}




void solveEachTest(int _TestCase) {
    cout << "Case #" << _TestCase << ": ";
    lld n; cin >> n;
    vector<lld> chrs(n); forn(i, n) cin >> chrs[i];

    vector<set<lld>> posNum(2502);

    lld m; cin >> m;
    vector<lld> keyb(m); forn(i, m) cin >> keyb[i], posNum[keyb[i]].insert(i);

    // set<array<lld, 3>> times;
    // _____error_____(chrs);
    // _____error_____(keyb);
    // _____error_____(posNum);

    lld ans = inf;
    vector<vector<lld>> dp(n+1, vector<lld> (m+1, -1));
    forn(i, m) {
        
        if (keyb[i] == chrs[0]) {
            // times.insert({0, 0, i});
            ans = min(ans, solve(0, i, dp, chrs, keyb, posNum));
        }
    }



    // while (times.size()) {
    //     // _____error_____(times, ans);
    //     auto [t, ind, currPos] = *times.begin();
    //     times.erase(times.begin());
    //     if (t > ans) break;
    //     if (ind == n - 1) {
    //         ans = min(ans, t);
    //         continue;
    //     }
    //     ind += 1;
        // auto nextInd = posNum[chrs[ind]].lower_bound(currPos);
        // if (nextInd != posNum[chrs[ind]].end() and *nextInd == currPos) {
        //     times.insert({t, ind, currPos});
        // } else {
        //     if (nextInd != posNum[chrs[ind]].end())
        //         times.insert({t + llabs(currPos - *nextInd), ind, *nextInd});
        //     if (nextInd != posNum[chrs[ind]].begin()) {
        //         auto prevInd = prev(nextInd);
        //         times.insert({t + llabs(currPos - *prevInd), ind, *prevInd});
        //     }
        // }
    // }

    cout << ans;


    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    cin.tie(0)->sync_with_stdio(0);
    cout.precision(10); cout << fixed;

#ifdef LUCTIVUD
    // const auto start_time = std::chrono::high_resolution_clock::now();
    freopen("/home/udit/CPPrc/zinput.txt", "r", stdin);
    freopen("/home/udit/CPPrc/zoutput.txt", "w", stdout);
#endif


    int __NTestCases = 1;
    cin >> __NTestCases;

    for (int _TestCase = 1; _TestCase <= __NTestCases; _TestCase++) {
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
    .?.?.?.
*/
