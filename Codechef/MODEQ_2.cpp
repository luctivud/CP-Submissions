// ************************.- J A I  S H R E E  R A M -.*************************


/* 
      ::: ---------- ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

          Author   :  Udit "luctivud" Gupta 

          linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
          github   :  https://github.com/luctivud

      :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ---------- :::
*/


#include <bits/stdc++.h>


#pragma GCC optimize "trapv"
#pragma GCC optimize ("Ofast")
// #pragma GCC target ("fpmath=sse,sse2")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")


using namespace std;


typedef long long int lld;
// #define lld int
typedef unsigned long long int llu;


#define   mems(A77AY, V4LU)    memset((A77AY), (V4LU), sizeof((A77AY)))
#define    CH3K(I7, E4, S7)    (((S7)>0) ? (I7)<(E4) : (I7)>(E4))
#define   for4(I7,S4,E4,S7)    for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
#define        forn(I7, E4)    for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define       forn1(I7, E4)    for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        EACH(I7, A7)    for (auto& I7: A7)
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  pb    push_back
#define                  f1    first
#define                  s2    second
#define           PLEASE_AC    return



#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); huehue(_it, args); cout << "\n";}

void huehue(istream_iterator<string> it) {}
template<typename T, typename... Args>
void huehue(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << ", ";
    huehue(++it, args...);
}

const lld d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const lld d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};






const lld MOD = lld(1e9) + 7ll;
const lld mod = MOD;

lld TempVar;

const long double EPS = 1e-6;

/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/

// #define gc getchar_unlocked
// void scanint(lld &x)
// {
//     register lld c = gc();
//     x = 0;
//     int neg = 0;
//     for(;((c<48 || c>57) && c != '-');c = gc());
//     if(c=='-') {neg=1;c=gc();}
//     for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
//     if(neg) x=-x;
// }

// #define pc(x) putchar_unlocked(x);

// inline void writeInt (lld n) {
//     lld N = n, rev, count = 0;
//     rev = N;
//     if (N == 0) { pc('0'); pc('\n'); return ;}
//     while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
//     rev = 0;
//     while (N != 0) { rev = (rev<<3ll) + (rev<<1ll) + N % 10; N /= 10;}  //store reverse of N in rev
//     while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
//     while (count--) pc('0');
//     pc ('\n');
// }


lld seiki(lld n) {
    return (n * (n+1)) / 2;
}

lld nc2(lld n) {
    if (n < 2ll) return 0ll;
    return (n * (n-1)) / 2;   
}






void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n, m;
        // scanint(n); scanint(m);
    cin >> n >> m;
    // writeInt(n);
    lld ans = n - 1;

    lld countMod[m + 1] = {0};

    for (int i = 2; i <= n; i++) {
        countMod[(m % i)] += 1;
    }

    for (int i = 0; i <= m; i++) {
        ans += nc2(countMod[i]);
    }

    // probably TLE here ----->
    for (int i = 2ll; i <= min(n, m); i++) {
        lld ThisMod = m % i;
        for (lld j = ThisMod + i; j <= min(n, m); j += i) {
            ans += countMod[j];
        }
    }

    cout << (ans) << "\n";
    
    return;
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    #ifdef LUCTIVUD
      // const auto start_time = std::chrono::high_resolution_clock::now();
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    lld _T0T4 = 1;
    cin >> _T0T4; 
    // scanint(_T0T4);

    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
    }

    #ifdef LUCTIVUD
      // auto end_time = std::chrono::high_resolution_clock::now();
      // std::chrono::duration<double> diff = end_time - start_time;
      // cerr << "Finished in : " << diff.count() << "\n";
    #endif

    return 0; 
}

/*        0.2s   Ryoki Tenkai:  
                                  Jihei Endonka     */


// vector<bool> visited(n+1, false);

//     for (lld i = min(n, m); i > 1; i--) {
//         lld zeta = i * (m / i);
//         lld res1 = 0ll, res2 = 0ll;
//         for (lld j = 2; j * j <= zeta; j++) {
//             if (visited[i]) continue;
//             if (zeta % j == 0) {
//                 lld zeta2 = j * (m / j);
//                 if (zeta2 == zeta) {
//                     visited[j] = true;
//                     res1 += 1;
//                 } else {
//                     res2 += 1;
//                 }
//                 if (j * j != zeta and m/j <= n) {
//                     zeta2 = (zeta / j) * ((m * j) / zeta);
//                     if (zeta2 == zeta) {
//                         visited[m / j] = true;
//                         res1 += 1;
//                     } else {
//                         res2 += 1;
//                     }
//                 }
//             }
//             // error(i, res1, res2);
//             ans += nc2(res1);
//             ans += res2;
//         }
//     }

//     ans += n-1;
