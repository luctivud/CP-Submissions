//  J A I  S H R E E  R A M  //

#include <bits/stdc++.h>

#pragma GCC optimize "trapv"
// #pragma GCC optimize ("Ofast")
// // #pragma GCC target ("fpmath=sse,sse2")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize ("-ffloat-store")


using namespace std;

typedef long long int lld;
typedef unsigned long long int llu;

#define        forn(I7, E4)    for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define       forn1(I7, E4)    for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  f1    first
#define                  s2    second

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type >
ostream & operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cout << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << H << ", "; dbg_out(T...);}
#define _____error_____(...) cout << #__VA_ARGS__ << " : ", dbg_out(__VA_ARGS__)

const lld d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const lld d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};


const long double EPS = 1e-6;
lld TempVar, mod, MOD;


/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/





/* This part should be outside the main in global paradigm. */

const lld MAXN = (lld)(1e6) + 1ll; // Maximum sieve upto
vector<bool> isPrime(MAXN, true); // Temp vector for sieve result
vector<lld> prime_numbers; // vector of primes

void sieve() {
	isPrime[0] = isPrime[1] = false;
	prime_numbers.push_back(2);
	for (lld i=4; i< MAXN; i+=2)
		isPrime[i] = false;
	for (lld i = 3; i < MAXN; i+=2) {
		if (isPrime[i]) {
			prime_numbers.push_back(i); // remove if not necessary
			for (lld j = 2 * i; j < MAXN; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

/* This should be called inside main. */
// sieve();	// function call in main



/* This should be called inside main. */
	

bool checkIfN1(lld num) {
	for (auto p : prime_numbers) {
		if (p > num) {
			break;
		}
		if (num % p == 0 and (p-1) % 4) {
			return false;
		} else {
			while (num % p == 0) {
				num /= p;
			}
		}
	}
	return ((num - 1) % 4 == 0);
	return true;
}






void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n; 
    cin >> n;
    // n = _TestCase;

    lld e = 0ll;

    while (n % 2 == 0) {
    	e++;
    	n /= 2;
    }

    assert(n & 1);

    lld n1 = 1;

    for (lld i = 1; i * i <= n; i += 2) {
    	if (n % i) continue;
    	lld num1 = i, num2 = n / i;
    	if (checkIfN1(num2)) {
    		n1 = max(n1, num2);
    	} else if (checkIfN1(num1)) {
    		n1 = max(n1, num1);
    	}
    }

    // _____error_____(n1);

    map<lld,lld> d1, d2;

    lld ind = 1ll;

    while (n > 1 and ind < (lld)prime_numbers.size() and prime_numbers[ind] <= n) {
    	while (n % prime_numbers[ind] == 0) {
    		n /= prime_numbers[ind];
    		d1[prime_numbers[ind]] += 1;
    	}
    	ind++;
    }
    if (n != 1) {
    	d1[n] += 1;
    }
    ind = 1ll;

    while (n1 > 1 and ind < (lld)prime_numbers.size() and prime_numbers[ind] <= n1) {
    	while (n1 % prime_numbers[ind] == 0) {
    		n1 /= prime_numbers[ind];
    		d2[prime_numbers[ind]] += 1;
    	}
    	ind++;
    }

    if (n1 != 1) {
    	d2[n1] += 1;
    }

    // _____error_____(d1, d2);

    lld zeta1 = 1ll, zeta2 = 1ll;

    for (auto [ke, va]: d1) {
    	zeta1 *= (2 * va + 1);
    }

    for (auto [ke, va]: d2) {
    	zeta2 *= (2 * va + 1);
    }

    // _____error_____(zeta1, zeta2);

    lld peta = 0ll;

    peta = ((zeta2 + zeta1) >> 1) - 1;

    assert((zeta2 + zeta1) % 2 == 0);

    if (e == 0) e = 1;

    cout << peta + (e - 1) * zeta1;

    
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


    MOD = mod = lld(1e9) + 7ll;
    lld _T0T4 = 1;
    cin >> _T0T4; 

    sieve();

    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
        cout << "\n"; 
    }


    #ifdef LUCTIVUD
      // auto end_time = std::chrono::high_resolution_clock::now();
      // std::chrono::duration<double> diff = end_time - start_time;
      // cerr << "Finished in : " << diff.count() << "\n";
    #endif

    return 0; 
}


/*  ~~
Author   :  Udit "luctivud" Gupta 
linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
*/
