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

lld BIG_E;
const lld maxn = 1 << 18;
lld tree[maxn];

/*:::::::::::::::::::::/UTILS:::::::::::::::::::::::::*/
/*::::::::::::::::::::::LOGIC:::::::::::::::::::::::::*/

lld getValAtPos(lld pos) {
    if (pos >= BIG_E) {
        return 1ll;
    } else {
        return tree[pos];
    }
}

void buildTree(lld N, string &s) {
    for (lld pos = N - 1; pos > 0; pos--) {
        if (s[pos] == '1') {
            tree[pos] = getValAtPos(2*pos);
        } else if (s[pos] == '0') {
            tree[pos] = getValAtPos(2*pos+1);
        } else {
            tree[pos] = getValAtPos(2*pos) + getValAtPos(2*pos+1);
        }
    }
}


lld getAns(lld pos, string &s) {
    while (pos > 0) {
        if (s[pos] == '1') {
            tree[pos] = getValAtPos(2*pos);
        } else if (s[pos] == '0') {
            tree[pos] = getValAtPos(2*pos+1);
        } else {
            tree[pos] = getValAtPos(2*pos) + getValAtPos(2*pos+1);
        }
        // if (tree[pos] == 1) break;
        pos >>= 1;
    }
    // _____error_____(tree);
    return tree[1];
}



void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld k; cin >> k;
    string s; cin >> s;
    s.push_back('$');
    reverse(all(s));
    BIG_E = 1ll << k;
    

    lld Q; cin >> Q;

    // _____error_____(len(tree));

    // _____error_____(getAns(BIG_E / 2, tree, s));

    // forgot to build tree lol
    buildTree(BIG_E, s);

    forn(qq, Q) {
        lld pos; char c;
        cin >> pos >> c;
        pos = BIG_E - pos;
        s[pos] = c;
        // _____error_____(s);
        cout << getAns(pos, s) << "\n";
    }   

    return;
}



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


    MOD = mod = lld(1e9) + 7ll;
    int _T0T4 = 1;
    // cin >> _T0T4; 

    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
        // cout << "\n"; 
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
