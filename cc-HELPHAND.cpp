
#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;
typedef unsigned long long int llu;

#define         TESTCASES()    cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define         _input(V3C)    for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define   mems(A77AY, V4LU)    memset((A77AY), (V4LU), sizeof((A77AY)))
#define    CH3K(I7, E4, S7)    (((S7)<0) ? (I7)>(E4) : (I7)<(E4))
#define   for4(I7,S4,E4,S7)    for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
#define              all(x)    (x).begin(), (x).end()
#define              deb(x)    cout << #x << "=" << (x) << "\n";


/* This part should be outside the main in global paradigm. */

// const lld MAXN = (lld)(1e6) + 1ll; // Maximum sieve upto
// vector<bool> isPrime(MAXN, true); // Temp vector for sieve result
// vector<lld> prime_numbers; // vector of primes

// void sieve() {
// 	isPrime[0] = isPrime[1] = false;
// 	prime_numbers.push_back(2);
// 	for (lld i=4; i< MAXN; i+=2)
// 		isPrime[i] = false;
// 	for (lld i = 3; i < MAXN; i+=2) {
// 		if (isPrime[i]) {
// 			prime_numbers.push_back(i); // remove if not necessary
// 			for (lld j = 2 * i; j < MAXN; j += i) {
// 				isPrime[j] = false;
// 			}
// 		}
// 	}
// }


// vector<lld> ans = {0, 1, 2};

// void solve() {

// }



/* This part should be outside the main in global paradigm. */

const long long MAXN = (lld)(1e6) + 1ll; // MAXN Size

vector<long long >isPrime(MAXN , true); // checkIfPrime
vector<long long >prime_numbers; // List of prime numbers
vector<long long >smallest_prime_factor(MAXN); // smallest_prime_factor of a number


void manipulated_seive() {
	isPrime[0] = isPrime[1] = false ;

	prime_numbers.push_back(2);
	smallest_prime_factor[2] = 2ll;

	for (long long int i = 4; i < MAXN ; i += 2) {
		isPrime[i] = false;
		smallest_prime_factor[i] = 2ll;
	}

	for (long long int i = 3; i < MAXN ; i += 2) {
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


/* This should be called inside main. */





vector<lld> ans = {0, 0, 1, 2, 3};

void precom() {
	// map<int, int> prime_facs;
	for4(i, 5ll, MAXN, 1ll) {
		if (isPrime[i]) {
			ans.push_back(ans[i - 1] + 2);
		} else {
			ans.push_back(ans[i - 1] + 1);
		}
	}
}



void solveEachTest(lld T35TC453N = 1) {

	lld n; cin >> n;
	cout << ans[n];
	cout << "\n";

	return;
}


signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.precision(10);
	/* This should be called inside main. */
	manipulated_seive();
	// sieve();	// function call in main
	precom();

	lld T3X0 = 0, T353 = 1;

	TESTCASES()
	solveEachTest(T353 - T3X0);
	return 0;
}
// Random Thought :  null