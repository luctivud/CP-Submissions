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

const long long MAXN = (lld)(4e6) + 2ll; // MAXN Size

vector<long long >isPrime(MAXN , true); // checkIfPrime
vector<long long >prime_numbers; // List of prime numbers
vector<long long >smallest_prime_factor(MAXN); // smallest_prime_factor of a number
vector<lld> phi(MAXN);

void manipulated_seive() {
	isPrime[0] = isPrime[1] = false ;
	
	prime_numbers.push_back(2);
	smallest_prime_factor[2] = 2ll;
	// phi[2] = 1;

	for (long long int i=4; i < MAXN ; i+=2) {
		isPrime[i] = false;
		smallest_prime_factor[i] = 2ll;
		// phi[i] *= (2 - 1);
		// phi[i] /= 2;
	}

	for (long long int i = 3; i < MAXN ; i+=2) {
		if (isPrime[i]) {
			prime_numbers.push_back(i);
			smallest_prime_factor[i] = i;
			// phi[i] = i-1;
		}

		for (long long int j = 0; j < (int)prime_numbers.size() && i * prime_numbers[j] < MAXN && prime_numbers[j] <= smallest_prime_factor[i]; j++) {
			isPrime[i * prime_numbers[j]] = false;
			smallest_prime_factor[i * prime_numbers[j]] = prime_numbers[j] ;
			// error(i*prime_numbers[j], prime_numbers[j]);
			// phi[i * prime_numbers[j]] *= (prime_numbers[j] - 1);
			// phi[i * prime_numbers[j]] /= (prime_numbers[j]);
			// if (i*prime_numbers[j] == 33) {
			// 	error(phi[i*prime_numbers[j]], prime_numbers[j]);
			// }
		}
	}
}


/* This should be called inside main. */
	






void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    // forn1(i, 16) cout << phi[i] << " ";
    lld k = _TestCase;
    // cin >> k;
    k = 4*k+1;
    lld ans = 0ll;

    lld ind = 1;
    while (ind * ind <= k) {
    	if (k % ind == 0) {
    		ans += (ind - ind / 2) * phi[k / ind];
    		// error((ind - ind / 2), phi[k / ind]);
    		if (k / ind != ind) {
    			lld ind2 = k / ind;
    			ans += (ind2 - ind2 / 2) * phi[ind];
    			// error((ind2 - ind2 / 2), phi[ind]);
    		}
    	}
    	ind += 2;
    }

    cout << ans - 1;

    cout << "\n"; 
    return;
}


signed main() {
    _LIGHT_IO(); int _T0T4 = 1;
    cin >> _T0T4; 

    iota(phi.begin(), phi.end(), 0ll);

    // manipulated_seive();  

    for(lld i = 2; i <= MAXN; i++) {
    	if (phi[i] == i) {
    		for (lld j = i; j <= MAXN; j += i) {
    			phi[j] -= phi[j] / i;
    		}
    	}
    }

    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
    }

    PLEASE_AC _LUCTIV_CRONO(); 
}

/*        0.2s   Ryoki Tenkai:  
                                  Jihei Endonka     */
