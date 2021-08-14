// ------------------------------------------------------------------- //
/*

      Author :  Udit "luctivud" Gupta
    Linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
      Github :  https://github.com/luctivud

*/
// ------------------------------------------------------------------- //



/*          J  A  I   S  H  R  E  E   R  A  M          */



#include <bits/stdc++.h>
using namespace std;

#ifdef LUCTIVUD
    #include <buggyBaby.hpp>
    pretty:: PrettyPrinter NonIterable;
    #define cerr cout
#else
    #define _____error_____(...)
#endif

// #pragma GCC optimize("O3,unroll-loops,trapv")
// #pragma GCC target("avx,avx2,fma,sse,sse2,sse3,sse4,popcnt,lzcnt")
// #pragma GCC optimize "trapv"






/*  Snips   */


typedef long long lld; typedef unsigned long long llu;

#define  forn(I7, E4) for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define forn1(I7, E4) for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        len(v) ((int)((v).size()))
#define        all(x) (x).begin(), (x).end()
#define       rall(x) (x).rbegin(), (x).rend()
#define            f1 first
#define            s2 second



/*  Utils   */


const lld MOD = int(1e9) + 7;
const lld &mod = MOD;

const long double EPS = 1e-6;

const lld inf = 2e18;


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};



signed pleaseAC(void) {

#ifdef LUCTIVUD
    // auto end_time = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> diff = end_time - start_time;
    // cerr << "Finished in : " << diff.count() << "\n";
#endif

    return 0;
}


void IAmJustice(void) {
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

#ifdef LUCTIVUD
    // const auto start_time = std::chrono::high_resolution_clock::now();
    freopen("/home/luctivud/CPPractice/IO/Zinput.txt", "r", stdin);
    freopen("/home/luctivud/CPPractice/IO/Zoutput.txt", "w", stdout);
#endif

    return;
}








// Fast Read Write 

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









/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/





void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n, m; //cin >> n >> m;
    scanLong(n);
    scanLong(m);
    // vector<vector<lld>> matr(n, vector<lld>(m));
    lld matr[n][m];
    forn(i, n) forn(j, m) scanLong(matr[i][j]);// cin >> matr[i][j];

    lld ansX = 1, ansY = 1;

    lld posOfMask[(1ll << 8) + 2];
    lld lo = 0, hi = lld(1e9)+2;
    while (lo <= hi) {
        lld mid = lo + (hi - lo) / 2;
        // map<lld, lld> posOfMask;
        // unordered_map<lld, lld, custom_hash> posOfMask;
        // vector<lld> posOfMask(1ll << 9, -1ll);
        memset(posOfMask, -1, sizeof(posOfMask));
        vector<lld> nums;
        forn(i, n) {
            bitset<8> num_bit;
            forn(j, m) {
                if (matr[i][j] >= mid) {
                    num_bit[j] = 1;
                }
            }
            if (posOfMask[num_bit.to_ulong()] == -1) {
                posOfMask[num_bit.to_ulong()] = i;
                nums.push_back(num_bit.to_ulong());
            }
        }
        // for (auto [ke, va] : posOfMask) {
        //     nums.push_back(ke);
        // }

        // _____error_____(nums);

        lld sz = len(nums);
        lld fullMoon = (1ll << m) - 1;
        bool okMoon = false;
        for (lld i = 0; i < sz; i++) {
            for (lld j = i; j < sz; j++) {
                // _____error_____((nums[i] | nums[j]), fullMoon);
                if ((nums[i] | nums[j]) >= fullMoon) {
                    // _____error_____(mid, nums[i], nums[j]);
                    ansY = posOfMask[nums[j]] + 1;
                    ansX = posOfMask[nums[i]] + 1;
                    okMoon = true;
                    break;
                }
            }
        }
        if (okMoon) {
            // _____error_____(mid);
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ansX << " " << ansY;

    
    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    IAmJustice();

    int _T0T4 = 1;
    // cin >> _T0T4; 
    
    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
        cout << "\n";
    }

    return pleaseAC(); 
}




/*  ~~
    I ponder of something great
    My lungs will fill and then deflate
    They fill with fire, exhale desire
    I know it's dire my time today

    I have these thoughts, so often I ought
    To replace that slot with what I once bought
    'Cause somebody stole my car radio
    And now I just sit in silence

    Sometimes quiet is violent
    I find it hard to hide it
    My pride is no longer inside
    It's on my sleeve
    My skin will scream reminding me of
    Who I killed inside my dream
    I hate this car that I'm driving
    There's no hiding for me
    I'm forced to deal with what I feel
    There is no distraction to mask what is real
    I could pull the steering wheel

*/
