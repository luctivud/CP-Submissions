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
        forn(i, n) {
            cin >> arr[i];
        }
        if (n == 1) {
            cout << "0\n";
            return;
        }
        if (n == 2) {
            if (arr[0] == arr[1]) {
                cout << "-1\n";
            } else {
                cout << "0\n";
            }
            return;
        }
        if (n == 3) {
            if (((arr[0] ^ arr[1]) > 0) and ((arr[1] ^ arr[2]) > 0) and (arr[0] ^ arr[1] ^ arr[2]) == arr[1]) {
                cout << "0\n";
            } else if (arr[1] == 0 and arr[0] != 0){
                cout << "1\n";
                cout << "1 2 3\n";
            } else if (arr[1] == 0 and arr[2] != 0){
                cout << "1\n";
                cout << "3 2 1\n";
            // } else if (arr[0] == 0 and arr[1] != 0) {
            //     cout << "1\n";
            //     cout << "1 2 3\n";
            // } else if (arr[0] == 0 and arr[2] != 0) {
            //     cout << "-1\n";
            //     // cout << "1 3 2\n";
            // } else if (arr[2] == 0 and arr[1] != 0) {
            //     cout << "1\n";
            //     cout << "3 2 1\n";
            // } else if (arr[2] == 0 and arr[0] != 0) {
            //     cout << "-1\n";
            //     // cout << "3 2 1\n";
            } else {
                cout << "-1\n";
            }
            return;
        }

        lld pos = -1;
        forn(i, n) {
            if (arr[i] != 0) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            cout << pos << "\n";
            return;
        }
        vector<array<lld, 3>> opBete;
        set<lld> doneFor;
        opBete.push_back({(pos+0) % n, (pos+1) % n, (pos+2) % n});
        opBete.push_back({(pos+0) % n, (pos+1) % n, (pos+3) % n});
        opBete.push_back({(pos+2) % n, (pos+3) % n, (pos+1) % n});
        opBete.push_back({(pos+0) % n, (pos+1) % n, (pos+2) % n});
        opBete.push_back({(pos+0) % n, (pos+2) % n, (pos+3) % n});
        doneFor.insert((pos + 0) % n);
        doneFor.insert((pos + 1) % n);
        // doneFor.insert((pos + 2) % n);
        // doneFor.insert((pos + 3) % n);
        // _____error_____(pos);
        forn(i, n) {
            if (doneFor.find(i) != doneFor.end()) continue;
            // _____error_____(i);
            if ((i & 1) == (pos & 1)) {
                opBete.push_back({(pos+0) % n, (pos+1) % n, i});
            } else {
                opBete.push_back({(pos+0) % n, (pos+2) % n, i});
            }
        }
        // _____error_____(arr);

        cout << opBete.size() << "\n";
        for (auto &[a, b, c] : opBete) {
            arr[c] = arr[a] ^ arr[b];
            // _____error_____(arr[a], arr[b], arr[c]);
            cout << a+1 << " " << b+1 << " " << c+1 << "\n";
        }
        _____error_____(arr);
    }

public:
    void ResetTestCase() {
        // cout << "\n";
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

