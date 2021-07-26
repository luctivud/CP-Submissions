/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*:::::::::::::J A I  S H R E E  R A M::::::::::::::::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/

#include <bits/stdc++.h>
using namespace std;
#ifdef LUCTIVUD
#include <buggyBaby.hpp>
pretty:: PrettyPrinter NonIterable;
#define cerr cout
#else
#define _____error_____(...)
#endif
#pragma GCC optimize "trapv"


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









/*:::::::::::::::::::::/UTILS:::::::::::::::::::::::::*/
/*::::::::::::::::::::::LOGIC:::::::::::::::::::::::::*/

class Solution {
    static const int maxN = int(1e5) + 2;
public:
    Solution() {
    }
public:
    void SolveEachTest(int _TestCase) {
        long long n; cin >> n;
        vector<pair<long long, long long>> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i].second;
            arr[i].first = i;
        }
        vector<pair<long long, long long>> brr{arr};
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {return a.second > b.second ;});
        long long TokyoScore = 0ll, RioScore = 0ll;
        set<pair<long long, long long>> whatSheWants;
        for (int i = 0; i < (n + 1) / 2; i++) {
            whatSheWants.insert(arr[i]);
        }
        long long donePos = (n + 1) / 2;
        vector<bool> visited(n);
        long long rioPosition = 0;
        while (rioPosition < n) {
            long long wantPos = (*whatSheWants.begin()).first;
            long long wantScore = (*whatSheWants.begin()).second;
            while (rioPosition < n and (rioPosition == wantPos or visited[rioPosition])) {
                rioPosition++;
            }
            if (rioPosition >= n) break;

            if (whatSheWants.find(brr[rioPosition]) == whatSheWants.end()) {
                TokyoScore += wantScore;
                whatSheWants.erase(whatSheWants.begin());
                RioScore += brr[rioPosition].second;
                visited[rioPosition] = 1;
                visited[wantPos] = 1;
            } else {
                if (wantScore < brr[rioPosition].second) {
                    swap(wantScore, brr[rioPosition].second);
                }
                TokyoScore += wantScore;
                whatSheWants.erase(whatSheWants.begin());
                RioScore += brr[rioPosition].second;
                whatSheWants.erase(whatSheWants.begin());
                visited[rioPosition] = 1;
                visited[wantPos] = 1;
                whatSheWants.insert(arr[donePos++]);
            }
        }
        if (whatSheWants.size()) {
            TokyoScore += (*whatSheWants.begin()).first;
        }
        cout << TokyoScore << " " << RioScore << "\n";
    }

public:
    void ResetTestCase() {
        cout << "\n";
    }
};



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/
/*::::::::::::::::::::::INVOC:::::::::::::::::::::::::*/
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // cout.precision(10); cout << fixed;
#ifdef LUCTIVUD
    // const auto start_time = std::chrono::high_resolution_clock::now();
    freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
    freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
#endif


    int _T0T4 = 1;
    // cin >> _T0T4;

    Solution Aurora;
    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        Aurora.SolveEachTest(_TestCase);
        Aurora.ResetTestCase();
    }


#ifdef LUCTIVUD
    // auto end_time = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> diff = end_time - start_time;
    // cerr << "Finished in : " << diff.count() << "\n";
#endif

    return 0;
}

/*:::::::::::::::::::::/INVOC:::::::::::::::::::::::::*/
/*  ~~
Author   :  Udit "luctivud" Gupta
linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
*/

