#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;

const lld U_MOD = 1000000007ll;

lld power(lld x, lld y, lld p) {
	lld res = 1;
	x = x % p;
	while (y > 0) {
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}


// lld modInverse(lld n, int p) {
//     return power(n, p - 2, p);
// }


// lld nCrModPFermat(lld n, lld r, lld p) {
//     if (r == 0) return 1;
//     lld fac[n + 1];
//     fac[0] = 1;
//     for (int i = 1; i <= n; i++)
//         fac[i] = (fac[i - 1] * i) % p;
//     return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
// }

// ! Computing modulus section --------------------------------------------------------------------------

const int N = 500;

lld factorialNumInverse[N + 1];
lld naturalNumInverse[N + 1];
lld fact[N + 1];

void InverseofNumber(lld p) {
	naturalNumInverse[0] = naturalNumInverse[1] = 1;
	for (int i = 2; i <= N; i++)
		naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}

void InverseofFactorial(lld p) {
	factorialNumInverse[0] = factorialNumInverse[1] = 1;
	for (int i = 2; i <= N; i++)
		factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}

void factorial(lld p) {
	fact[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = (fact[i - 1] * i) % p;
	}
}


lld Binomial(lld N, lld R, lld p) {
	lld ans = ((fact[N] * factorialNumInverse[R]) % p * factorialNumInverse[N - R]) % p;
	return ans;
}

// x Computing modulus section --------------------------------------------------------------------------

// ! Precompute power of twoss --------------------------------------------------------------------------

vector<lld> power_of_twos;

void precomputePowerOfTwo(lld sz, lld p) {
	lld hairu = 1ll;

	for (lld i = 0ll; i < sz + 1ll; i++) {
		power_of_twos.push_back(hairu);
		hairu *= 2ll;
		hairu %= p;
	}

	return;
}


// x Precompute power of twoss --------------------------------------------------------------------------

// ! Precompute permutations used -----------------------------------------------------------------------

lld permutsum[5000][5000] = {0};

void precalculatePerm(lld n, lld U_MOD) {
	if (permutsum[n][0] == 1) return;
	permutsum[n][0] = 1ll;
	for (lld i = 1; i <= n; i++) {
		permutsum[n][i] = (permutsum[n][i - 1] + Binomial(n, i, U_MOD)) % U_MOD;
	}
	return;
}


lld get_perm_prefix_sum(lld n, lld k) {
	if (permutsum[n][k] == 0) {
		precalculatePerm(n, U_MOD);
	}

	return permutsum[n][k];
}

// x Precompute permutations used -----------------------------------------------------------------------

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	lld t; cin >> t;
	// ! Computing modulus section ------------------------
	InverseofNumber(U_MOD);
	InverseofFactorial(U_MOD);
	factorial(U_MOD);
	// x Computing modulus section ------------------------
	// ! Precompute power of 2 ----------------------------
	// precomputePowerOfTwo(500000ll, U_MOD);
	//
	// for (auto i: power_of_twos) {
	// 	if (i > 99000) break;
	// 	cout << i << " ";
	// }
	// x Precompute power of 2 ----------------------------

	while (t--) { // Queries handled here MAIN MAIN MAIN MAIN MAIN >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		// lld ans = 0ll;
		lld n; cin >> n;
		vector<lld> arr(n);
		bool subtask2 = true;
		map<lld, lld> count;
		for (auto & i : arr) {
			cin >> i;
			count[i]++;
			if (count[i] == 2) subtask2 = false;
		}


		if (subtask2) {
			vector<lld> ans(n);
			lld greed = 1ll;
			for (lld i = 1; i <= n; i++) {
				ans[n - i] = greed;
				greed *= 2ll;
				greed %= U_MOD;
			}
			for (auto i : ans) {
				cout << i << " ";
			}
		} else {
			// //  O(n2) don't back off here.

			// precalculate permutations prefix sum
			// for (auto i : count) {
			// 	precalculatePerm(i.second, U_MOD);
			// }

			// cout << permutsum[3][2];

			// pratyek number ka  ans
			for (lld i = 1; i <= n; i++) {
				lld ans = 0ll;
				lld count_in_arr = count[i];
				// ek number ko kitna lekr chal rhe
				for(lld k = 1ll; k <= count_in_arr; k++) {
					lld partial_ans = Binomial(count_in_arr, k, U_MOD);
					// baki numbers ke contribution
					for (lld j = 1ll; j <= n; j++) {
						if (i == j) {
							continue;
						} else if (j < i and count[j]) {
							// kam hona chahiye
							lld touka = min(count[j], k-1);
							partial_ans *= get_perm_prefix_sum(count[j], touka);
							partial_ans %= U_MOD;
						} else if (j > i and count[j]) {
							// barabar ya kam chalega
							lld touka = min(count[j], k);
							partial_ans *=  get_perm_prefix_sum(count[j], touka);
							partial_ans %= U_MOD;
						}
					}
					ans += partial_ans;
					ans %= U_MOD;
				}
				cout << ans << " ";
			}

		}

		cout << "\n";
	}
	return 0;
}



//  Precompute NcR in o(1) time taken from :
// https://www.geeksforgeeks.org/queries-of-ncrp-in-o1-time-complexity/


/* Elegant debugging : --- --- --- --- >

1
3
2 2 3

1 has 0 count in array
  > Final ans is 0
2 has 2 count in array
  Selecting 1 of 2's in 2 ways
  Remaining 1 numbers are selected
  Selecting 2 of 2's in 1 ways
  Remaining 1 numbers are selected
  > Final ans is 6
3 has 1 count in array
  Selecting 1 of 3's in 1 ways
  Remaining 0 numbers are selected
  > Final ans is 1
*/



// for (lld i = 1ll; i <= n; i++) {
// 	lld ans = 0ll;
// 	lld count_in_arr = count[i];
// 	// cout << i << " has " << count_in_arr << " count in array\n";
// 	for (lld k = 1ll ; k <= count_in_arr; k++) {
// 		// cout << "  Selecting " << k << " of " << i << "\'s";
// 		lld factor = Binomial(count_in_arr, k, U_MOD);
// 		// cout << " in " << this_part_ans << " ways \n";
// 		lld this_part_ans = 0ll;

// 		for (lld j = 1ll; j<= n; j++) {

// 			if (i == j) {
// 				continue;
// 			} else if (i > j) {
// 				if (k-1 > 0 and count[j]) {
// 					lld sensei = min(count[j], k-1);
// 					lld kimchii = Binomial(count[j], sensei, U_MOD);
// 					lld second_part = (kimchii * power_of_twos[sensei]) - sensei + 1ll;
// 					this_part_ans += second_part;
// 					this_part_ans %= U_MOD;
// 				}
// 			} else {
// 				if (k > 0 and count[j]) {
// 					lld sensei = min(count[j], k);
// 					lld kimchii = Binomial(count[j], sensei, U_MOD);
// 					lld second_part = (kimchii * power_of_twos[sensei]) - sensei + 1ll;
// 					this_part_ans += second_part;
// 					this_part_ans %= U_MOD;
// 				}
// 			}
// 		}
// 		// if (this_part_ans == 0) this_part_ans++;
// 		ans += factor * (this_part_ans % U_MOD);
// 		ans %= U_MOD;
// 	}
// 	// cout << "  > Final ans is ";
// 	cout << ans << " ";
// 	// cout << "\n";
// }