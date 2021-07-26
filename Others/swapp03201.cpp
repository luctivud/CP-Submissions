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
    int solution(vector<int> A) {
        int count = 0;
        int n = (int)A.size();
        vector<int> arr{A}, arrt;
        bool check = false;
        for (int j = 0; j < n - 2 ; j++) {
            if ((arr[j] - arr[j+1] > 0) && (arr[j + 1] - arr[j + 2] < 0)) {
                check = true;
            } else if ((arr[j] - arr[j+1] < 0) && (arr[j+1] - arr[j+2] > 0)) {
                check = true;
            } else {
                check = false;
                break;
            }
        }
        if (check) {
            return 0;
        }

        vector<int> ab;

        for (int i = 0; i <n; i++) {
            ab.clear();
            for (int j : arr) {
                ab.push_back(j);
            }
            auto it = ab.begin();
            while (it != ab.end() and *it != i) {
                it++;
            }
            if (it != ab.end() and *it == i) {
                ab.erase(it);
            }
            int f = 0;
            bool okay = false;
            while (f < n - 3) {
                if (!okay && f != 0) {
                    break;
                }
                if ((ab[f] - ab[f+1] > 0) && (ab[f+1] - ab[f+2] < 0)) {
                    okay = true;
                } else if ((ab[f] - ab[f+1] < 0) && (ab[f+1] - ab[f+2] > 0)) {
                    okay = true;
                } else {
                    okay = false;
                }
                f++;
            }
            if (okay) {
                count++;
            }
        }
        if (count == 0)
            count = -1;

        return count;
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
    cin >> _T0T4;

    Solution Aurora;
    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        int n; cin >> n;
        vector<int> arr(n);
        forn(i, n) {
            cin >> arr[i];
        }
        cout << Aurora.solution(arr);
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

