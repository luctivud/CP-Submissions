#include <bits/stdc++.h>
// #pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;

#define gc getchar_unlocked
void scanint(int &x) {
    register int c = gc();
    x = 0;
    bool neg = 0;
    for (; ((c < 48 || c > 57) && c != '-'); c = gc());
    if (c == '-') {neg = 1; c = gc();}
    for (; c > 47 && c < 58; c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
    if (neg) x = -x;
}

void scanLong(lld &x) {
    register lld c = gc();
    x = 0;
    bool neg = 0;
    for (; ((c < 48 || c > 57) && c != '-'); c = gc());
    if (c == '-') {neg = 1; c = gc();}
    for (; c > 47 && c < 58; c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
    if (neg) x = -x;
}

#define pc(x) putchar_unlocked(x);

inline void writeInt (int n) {
    int N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); pc('\n'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev << 3) + (rev << 1) + N % 10; N /= 10;} //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
    pc ('\n');
}


inline void writeLong (lld n) {
    lld N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); pc('\n'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev << 3) + (rev << 1) + N % 10; N /= 10;} //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
    pc ('\n');
}


// lld nc2(lld n) {
//     if (n < 2ll) return 0ll;
//     lld a = n & 1 ? n : n >> 1;
//     --n;
//     lld b = n & 1 ? n : n >> 1;
//     return (lld)a * (lld)b;
// }

lld nc2(lld n) {
    if (n < 2ll) return 0ll;
    return (n * (n-1)) / 2;   
}


signed main() {

    // ios_base::sync_with_stdio(false); cin.tie(0);
    // cout.precision(10); cout << fixed;

#ifdef LUCTIVUD
    freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
    freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
#endif

    int t;

    scanint(t);
    // cin >> t;

    while (t--) {
        lld n, m;
        scanLong(n); scanLong(m);
        // cin >> n >> m;
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

        // cout << (ans) << "\n";
        writeLong(ans);
    }

    return 0;
}
