

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


/* This should be called inside main. */
	manipulated_seive();

