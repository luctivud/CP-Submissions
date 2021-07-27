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
        // lld res = (1ll << 11) - 1ll;
        // cout << bitset<11>{res};
        lld n; cin >> n;
        vector<char> bits(10, '?');
        forn(xx, n) {
            char oper; cin >> oper;
            lld num; cin >> num;
            bitset<10> bitNum {(unsigned)num};
            forn(i, 10) {
                bool bitOfNum = (bitNum[i] == 1); char bitOfBeby = bits[i];
                if (oper == '&') {
                    // one 0 enou
                    if (bitOfNum == 0 or bitOfBeby == '0') {
                        bits[i] = '0';
                    }
                } else if (oper == '|') {
                    // 1 0 = 1, 0 1 = 1;
                    if (bitOfNum == 1 or bitOfBeby == '1') {
                        bits[i] = '1';
                    }
                } else {
                    // flip bitch
                    if (bitOfNum == 1) {
                        if (bitOfBeby == '0') {
                            bits[i] = '1';
                        } else if (bitOfBeby == '1') {
                            bits[i] = '0';
                        } else if (bitOfBeby == '?') {
                            bits[i] = '$';
                        } else {
                            bits[i] = '?';
                        }
                    } else {

                    }
                    // if (!((bitOfNum == 1) ^ (bitOfBeby == '1')) and bitOfBeby != '?' and bitOfBeby != '$') {
                    //     bits[i] = '0';
                    // } else if () {

                    // }
                }
            }
            // _____error_____(bits);
        }

        _____error_____(bits);
        bitset<10> res{0};
        vector<tuple<char, lld>> ans;

        res = 0;
        forn(i, 10) {
            if (bits[i] != '0') {
                res[i] = 1;
            }
        }
        lld resVal = res.to_ulong();
        if (resVal != 1023) {
            ans.push_back({'&', resVal});
        }

        // _____error_____(res);
        res = 0;
        forn(i, 10) {
            if (bits[i] == '1') {
                res[i] = 1;
            }
        }
        resVal = res.to_ulong();
        if (resVal != 0) {
            ans.push_back({'|', resVal});
        }


        res = 0;
        forn(i, 10) {
            if (bits[i] == '$') {
                res[i] = 1;
            }
        }
        resVal = res.to_ulong();
        if (resVal != 0) {
            ans.push_back({'^', resVal});
        }


        cout << ans.size() << "\n";
        for (auto [oper, num] : ans) {
            cout << oper << " " << num << "\n";
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

// vector<tuple<char, lld, lld>> arr(n);
//         map<lld, vector<lld>> graph;
//         forn(i, n) {
//             char op; lld num; cin >> op >> num;
//             arr[i] = {op, num, i};
//             lld nxt = 0ll;
//             if (op == '&') {
//                 nxt = res & num;
//             } else if (op == '|') {
//                 nxt = res | num;
//             } else {
//                 nxt = res ^ num;
//             }
//             _____error_____(nxt, res, op, num);
//             if (nxt != res) {
//                 graph[res].push_back(i);
//             }
//             res = nxt;
//         }

//         _____error_____(graph);
