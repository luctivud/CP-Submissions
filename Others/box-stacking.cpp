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
typedef unsigned long long int llu;


#define   mems(A77AY, V4LU)    memset((A77AY), (V4LU), sizeof((A77AY)))
#define    CH3K(I7, E4, S7)    (((S7)>0) ? (I7)<(E4) : (I7)>(E4))
#define   for4(I7,S4,E4,S7)    for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
#define        forn(I7, E4)    for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define       forn1(I7, E4)    for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  f1    first
#define                  s2    second



#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); huehue(_it, args); cout << "\n";}

void huehue(istream_iterator<string> it) {}
template<typename T, typename... Args>
void huehue(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << ", ";
    huehue(++it, args...);
}

const lld d4i[4] = { -1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const lld d8i[8] = { -1, -1, 0, 1, 1, 1, 0, -1}, d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};


const lld MOD = lld(1e9) + 7ll;
const lld mod = MOD;

lld TempVar;

const long double EPS = 1e-6;

/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/

int maxHeight(int height[], int width[], int length[], int n) {
    vector<tuple<int, int, int>> series;
    for (int i = 0; i < n; i++) {
        series.emplace_back(height[i], min(length[i], width[i]), max(length[i], width[i]));
        series.emplace_back(width[i], min(length[i], height[i]), max(length[i], height[i]));
        series.emplace_back(length[i], min(height[i], width[i]), max(height[i], width[i]));
    }
    sort(series.begin(), series.end(), [](auto & a, auto & b) {
        return (get<2>(a) * get<1>(a)) > (get<2>(b) * get<1>(b));
    });
    n = (int)series.size();
    int dp[n] = {0};
    for(int i=0; i< n; i++) {
        dp[i] = get<0>(series[i]);
    }

    for (int i = 1; i < n; i++) {
        // int currWidth = (get<0>(series[i]) * get<1>(series[i]));
        for (int j = 0; j < i; j++) {
            // int prevWidth = (get<0>(series[j]) * get<1>(series[j]));
            if (get<1>(series[j]) > get<1>(series[i]) and get<2>(series[j]) > get<2>(series[i])) {
                dp[i] = max(dp[i], dp[j] + get<0>(series[i]));
            // } else {
            //     dp[i] = max(dp[i], dp[j]);
            }
        }
        // error(i, dp[i], get<2>(series[i]));
    }
    return *max_element(dp, dp+n);
}




void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    int n; cin >> n;
    int height[n], width[n], length[n];
    forn(i, n) cin >> height[i] >> width[i] >> length[i];
    cout << maxHeight(height, width, length, n);


    // cout << "\n";
    return;
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // cout.precision(10); cout << fixed;
#ifdef LUCTIVUD
    // const auto start_time = std::chrono::high_resolution_clock::now();
    freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
    freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
#endif


    lld _T0T4 = 1;
    // cin >> _T0T4;

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
