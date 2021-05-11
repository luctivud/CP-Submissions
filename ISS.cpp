// ************************.- J A I  S H R E E  R A M -.*************************


/* 
      ::: ---------- ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

          Author   :  Udit "luctivud" Gupta 

          linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
          github   :  https://github.com/luctivud

      :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ---------- :::
*/


#include <bits/stdc++.h>


// #pragma GCC optimize "trapv"
// #pragma GCC optimize ("Ofast")
// // #pragma GCC target ("fpmath=sse,sse2")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize ("-ffloat-store")


using namespace std;


typedef long long int lld;
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


const auto start_time = std::chrono::high_resolution_clock::now();

signed _LIGHT_IO() {

    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    return 0; 
}


signed _LUCTIV_CRONO() {

    #ifdef LUCTIVUD
      auto end_time = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> diff = end_time - start_time;
      cerr << "Finished in : " << diff.count() << "\n";
    #endif

  return 0; 
}



const lld MOD = lld(1e9) + 7ll;
const lld mod = MOD;

lld TempVar;

const long double EPS = 1e-6;

/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/




/* This part should be outside the main in global paradigm. */

const long long MAXN = (lld)(1e7) + 1ll; // MAXN Size

vector<long long >isPrime(MAXN , true); // checkIfPrime
vector<long long >prime_numbers; // List of prime numbers
vector<long long >smallest_prime_factor(MAXN); // smallest_prime_factor of a number


void manipulated_seive() {
	isPrime[0] = isPrime[1] = false ;
	
	prime_numbers.push_back(2);
	smallest_prime_factor[2] = 2ll;

	for (long long int i=4; i < MAXN ; i+=2) {
		isPrime[i] = false;
		smallest_prime_factor[i] = 2ll;
	}

	for (long long int i = 3; i < MAXN ; i+=2) {
		if (isPrime[i]) {
			prime_numbers.push_back(i);
			smallest_prime_factor[i] = i;
		}

		for (long long int j = 0; j < (int)prime_numbers.size() && i * prime_numbers[j] < MAXN && prime_numbers[j] <= smallest_prime_factor[i]; j++) {
			isPrime[i * prime_numbers[j]] = false;
			smallest_prime_factor[i * prime_numbers[j]] = prime_numbers[j] ;
		}
	}
}







lld power(lld x, lld y) {
	lld res = 1;

	if (x == 0) return 0;

	while (y > 0)  {
		if (y & 1)
			res = (res * x);

		y = y >> 1; 
		x = (x * x);
	}
	return res;
}


void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld k; cin >> k;

    // cout << int(1e6);

    k = 4*k+1;
    // k = 4 *_TestCase + 1;
    lld K = k;

    map<lld, lld> factors;

    while (k > 1) {
    	lld smol = smallest_prime_factor[k];
    	while (k % smol == 0) {
    		k /= smol;
    		factors[smol] += 1;
    	}
    }

    lld ans = 1ll;
    for (auto [ke, va] : factors) {
    	ans *= ((va + 1) * power(ke, va) - va * power(ke, va-1));
    }


    lld remain = (ans - K) / 2;

    // cout << ans;

    // cout << " " << remain << " 1 " ;

    cout << ans - remain -1;

    cout << "\n"; 
    return;
}


signed main() {
    _LIGHT_IO(); int _T0T4 = 1;
    cin >> _T0T4; 

    /* This should be called inside main. */
	manipulated_seive();


    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
    }

    PLEASE_AC _LUCTIV_CRONO(); 
}

/*        0.2s   Ryoki Tenkai:  
                                  Jihei Endonka     */
