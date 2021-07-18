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
        // cout << "Case #" << _TestCase << ":";
        lld n; cin >> n;
        vector<lld> arr(n);
        vector<lld> ans(n, -1);
        set<lld> visited, notVisited;
        forn(i, n) {
            notVisited.insert(i);
        }
        forn(i, n) {
            cin >> arr[i];
            --arr[i];
            if (visited.find(arr[i]) == visited.end()) {
                visited.insert(arr[i]);
                notVisited.erase(arr[i]);
                ans[i] = arr[i];
            }
        }
        if (notVisited.size() == 1 and ans[*(notVisited.begin())] == -1) {
            ans[*(notVisited.begin())] = arr[*(notVisited.begin())];
            forn(i, n) {
                if (ans[i] == arr[*(notVisited.begin())]) {
                    ans[i] = *(notVisited.begin());
                    break;
                }
            }
            notVisited.erase(notVisited.begin());
        }

        vector<lld> notVisitedVector;
        forn(i, n) {
            if (ans[i] == -1 and notVisited.find(i) != notVisited.end()) {
                notVisited.erase(i);
                notVisitedVector.push_back(i);
            }
        }
        _____error_____(notVisitedVector);
        lld sz = len(notVisitedVector);
        if (sz == 1) {
            ////
            ans[notVisitedVector[0]] = *notVisited.begin();
            notVisited.erase(notVisited.begin());
            notVisited.insert(notVisitedVector[0]);
        } else {
            forn(i, sz) {
                // _____error_____(i+1, notVisitedVector[(i+1) % sz]);
                ans[notVisitedVector[(i+1) % sz]] = notVisitedVector[i];
            }
        }

        forn(i, n) {
            if (ans[i] == -1) {
                ans[i] = *notVisited.begin();
                notVisited.erase(notVisited.begin());
            }
        }

        // for (auto i : notVisited) {
        //     notVisitedVector.push_back(i);
        // }
        // _____error_____(notVisited);



        cout << visited.size() << "\n";
        forn(i, n) {
            cout << ++ans[i] << " ";
        }
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

