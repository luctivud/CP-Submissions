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
    long double inf = 1e16;
public:
    Solution() {
    }
public:
    void SolveEachTest(int _TestCase) {
        // cout << "Case #" << _TestCase << ":";
        lld W, H; cin >> W >> H;
        lld x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
        lld w, h; cin >> w >> h;

        lld height_t1 = y2 - y1, width_t1 = x2 - x1;
        lld A_x = x1, A_y = y1, 
            B_x = x2, B_y = y1, 
            C_x = x2, C_y = y2,  // D    C
            D_x = x1, D_y = y2;  // A    B

        long double ans = inf;

        lld init_t2_x = 0, init_t2_y = 0, final_t2_x = 0, final_t2_y = 0;

        lld newTablePos_x = 0, newTablePos_y = 0;

        init_t2_x = 0ll, init_t2_y = 0ll;
        final_t2_x = (init_t2_x + w), final_t2_y = (init_t2_y + h);
        // newTablePos_x = max(A_x, final_t2_x), 
        newTablePos_x = A_x;
        newTablePos_y = max(A_y, final_t2_y);
        if ((newTablePos_x + width_t1 <= W) and (newTablePos_y + height_t1 <= H)) {
            ans = min(ans, moved(newTablePos_x, newTablePos_y, A_x, A_y));
            // _____error_____(ans);
        }


        init_t2_x = W, init_t2_y = 0ll;
        final_t2_x = (init_t2_x - w), final_t2_y = (init_t2_y + h);
        newTablePos_x = min(B_x, final_t2_x);
        // newTablePos_y = max(B_y, final_t2_y);
        newTablePos_y = B_y;
        // _____error_____(newTablePos_x, newTablePos_y);
        if (newTablePos_x - width_t1 >= 0ll and newTablePos_y + height_t1 <= H) {
            ans = min(ans, moved(newTablePos_x, newTablePos_y, B_x, B_y));
        }

        init_t2_x = W, init_t2_y = H;
        final_t2_x = (init_t2_x - w), final_t2_y = (init_t2_y - h);
        // newTablePos_x = min(C_x, final_t2_x);
        newTablePos_x = C_x;
        newTablePos_y = min(C_y, final_t2_y);
        if (newTablePos_x - width_t1 >= 0ll and newTablePos_y - height_t1 >= 0ll) {
            ans = min(ans, moved(newTablePos_x, newTablePos_y, C_x, C_y));
        }

        init_t2_x = 0ll, init_t2_y = H;
        final_t2_x = (init_t2_x + w), final_t2_y = (init_t2_y - h);
        newTablePos_x = max(D_x, final_t2_x);
        //, newTablePos_y = min(D_y, final_t2_y);
        newTablePos_y = D_y;
        if (newTablePos_x + width_t1 <= W and newTablePos_y - height_t1 >= 0ll) {
            ans = min(ans, moved(newTablePos_x, newTablePos_y, D_x, D_y));
        }


        if (abs(ans - inf) < EPS) {
            cout << "-1";
            return;
        }
        cout << ans;
    }

public:
    void ResetTestCase() {
        cout << "\n";
    }

    long double moved(lld a, lld b, lld c, lld d) {
        return (long double) sqrt((long double)(a - c) * (a - c) + (b - d) * (b - d));
    }
};



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/
/*::::::::::::::::::::::INVOC:::::::::::::::::::::::::*/
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;
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

