// template by luctivud aka carbon


#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

// typedef long long int lld;
typedef unsigned long long int lld;

#define         TESTCASES()    cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define         _input(V3C)    for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define   mems(A77AY, V4LU)    memset((A77AY), (V4LU), sizeof((A77AY)))
#define    CH3K(I7, E4, S7)    (((S7)<0) ? (I7)>(E4) : (I7)<(E4))
#define   for4(I7,S4,E4,S7)    for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define             deb1(x)    cout << #x << "=" << (x) << "\n";
#define             deb2(x)    cout << #x << "=" << (x) << " ";


lld n, k;
lld closestProduct = 0ll;

void allPermsBrute(vector<lld> &arr, vector<lld> &brr, lld closestProduct, lld power) {
	vector<lld> temp{brr};
	while(next_permutation(temp.begin(), temp.end())) {
		// cout << "ooj";
		lld thisClosestProduct = 0ll;
		for4(i, 0, n, 1) {
			thisClosestProduct += (arr[i] * temp[i]);
			// cout << temp[i] << " ";
		}
		// cout << "\n";

		if (llabs(thisClosestProduct - k) < llabs(closestProduct - k)) {
			// cout << "ok";
			closestProduct = thisClosestProduct;
			for4(i, 0, n, 1) {
				brr[i] = temp[i];
			}
		}
	}
}





void bruteAttack(vector<lld> &arr, vector<lld> &brr, lld power) {
	while (power-- > 0) {
		for (lld i = n - 1; i > 0; i--) {
			for (lld j = n-1; j >= 0; j--) {
				lld hairu = closestProduct;
				hairu += -(arr[i]*brr[i]) -(arr[j]*brr[j])
						+(arr[i]*brr[j]) + (arr[j]*brr[i]);
				if (llabs(hairu - k) < llabs(closestProduct - k)) {
					closestProduct = hairu;
					swap(brr[i], brr[j]);
					continue;
				// } else {
				// 	j--;
				}
			}
			// i--;
		} // backward

		for (lld i = 0; i < n - 1; i++) {
			// lld thisClosestProduct = closestProduct;
			// // cout << "ok";
			// lld leftIdx = i;
			for (lld j = 0; j < n; j++) {
				lld hairu = closestProduct;
				hairu += -(arr[i]*brr[i]) -(arr[j]*brr[j])
						+(arr[i]*brr[j]) + (arr[j]*brr[i]);
				if (llabs(hairu - k) < llabs(closestProduct - k)) {
					closestProduct = hairu;
					swap(brr[i], brr[j]);
					continue;
				// } else {
				// 	j++;
				}
			}

			// i++;
		} // forward
	} // vicious attack
	return;
}



void kawaiiBruteAttack(vector<lld> &arr, vector<lld> &brr, lld closestProduct, lld power) {
	while (power-- > 0) {
		for (lld i = n - 1; i > 0; ) {
			lld thisClosestProduct = closestProduct;
			// cout << "ok";
			lld leftIdx = i;
			for (lld j = n - 1; j >= 0; ) {
				lld hairu = closestProduct - (arr[i] * brr[i])
				            - (arr[j] * brr[j]) + (arr[i] * brr[j]) + (arr[j] * brr[i]);
				if (llabs(hairu - k) < llabs(thisClosestProduct - k)) {
					thisClosestProduct = hairu;
					leftIdx = j;
				} else {
					j--;
				}
			}

			if (llabs(thisClosestProduct - k) < llabs(closestProduct - k)) {
				closestProduct = thisClosestProduct;
				swap(brr[i], brr[leftIdx]);
			} else {
				i--;
			}
		} // backward

		for (lld i = 0; i < n - 1; ) {
			lld thisClosestProduct = closestProduct;
			// cout << "ok";
			lld leftIdx = i;
			for (lld j = i + 1; j < n; ) {
				lld hairu = closestProduct - (arr[i] * brr[i])
				            - (arr[j] * brr[j]) + (arr[i] * brr[j]) + (arr[j] * brr[i]);
				if (llabs(hairu - k) < llabs(thisClosestProduct - k)) {
					thisClosestProduct = hairu;
					leftIdx = j;
				} else {
					j++;
				}
			}

			if (llabs(thisClosestProduct - k) < llabs(closestProduct - k)) {
				closestProduct = thisClosestProduct;
				swap(brr[i], brr[leftIdx]);
			} else {
				i++;
			}
		} // forward
	} // vicious attack
	return;
}



void optimizedKaneki(vector<lld> &arr, vector<lld> &brr, lld power) {
	while (power--) {
		lld rightIdx = n - 1, leftIdx = 0;
		while (rightIdx > 0) {
			lld thisClosestProduct = closestProduct;
			thisClosestProduct += -(arr[rightIdx] * brr[rightIdx]) - (arr[leftIdx] * brr[leftIdx])
			                      + (arr[leftIdx] * brr[rightIdx] + brr[leftIdx] * arr[rightIdx]);

			lld maskLeftIdx = leftIdx;// maskRightIdx = rightIdx;
			lld ihehi = leftIdx;
			if (llabs(thisClosestProduct - k) > llabs(closestProduct - k)) {
				lld hairu = thisClosestProduct;
				while (maskLeftIdx < rightIdx) {
					hairu += -(arr[rightIdx] * brr[rightIdx]) - (arr[maskLeftIdx] * brr[maskLeftIdx])
					         + (arr[maskLeftIdx] * brr[rightIdx] + brr[maskLeftIdx] * arr[rightIdx]);
					if (llabs(hairu - k) < llabs(thisClosestProduct - k)) {
						leftIdx = maskLeftIdx;
						thisClosestProduct = hairu;
					}
					maskLeftIdx++;
				}

			}

			if (llabs(thisClosestProduct - k) > llabs(closestProduct - k)) {
				break;
			} else {
				closestProduct = thisClosestProduct;
				// edges[leftIdx] = rightIdx;
				// edges[rightIdx] = leftIdx;
				swap(brr[leftIdx], brr[rightIdx]);
			}
			leftIdx = ihehi;
			leftIdx = 0;

			leftIdx++; rightIdx--;
		}// while

	}// power
}


void hustleShuffle(vector<lld> &arr, vector<lld> &brr) {

	lld fac = k / n;
	

}




void solveEachTest(lld T35TC453N = 1) {
	// lld n, k;
	cin >> n >> k;

	vector<lld> arr(n), brr(n);

	_input(arr);
	_input(brr);

	sort(all(arr));
	sort(all(brr));


	closestProduct = 0ll;
	for4(i, 0, n, 1) {
		closestProduct += (arr[i] * brr[i]);
	}

	


	// // // /  comment here >>>>>>>>>>>>>>>>>>>>>>>>
	// deb1(llabs(closestProduct-k));


	if (n < 11) {
		allPermsBrute(arr, brr, closestProduct, 1000);
	} else if (n < 501) {
		bruteAttack(arr, brr, 33);
	} else if (n < 5001) {
		kawaiiBruteAttack(arr, brr, closestProduct, 33);
	} else {
		optimizedKaneki(arr, brr, 3);
	}


	optimizedKaneki(arr, brr, 1);



	// deb1(llabs(closestProduct-k));
	// //  comment here >>>>>>>>>>>>>>>>>>>>>>>>
	// closestProduct = 0ll;
	// for4(i, 0, n, 1) {
	// 	closestProduct += (arr[i] * brr[i]);
	// }
	// deb1(llabs(closestProduct-k));
	// cout << "comment it \n\n";






	// vector<lld> secondArr(n);
	for4(i, 0ll, n, 1ll) {
		cout << arr[i] << " ";
		// secondArr[i] = brr[edges[i]];
	} cout << "\n";

	for (auto b : brr) {
		cout << b << " ";
	}

	cout << "\n";
	return;
}


signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.precision(10);

	lld T3X0 = 0, T353 = 1;

	// TESTCASES()
	solveEachTest(T353 - T3X0);
	return 0;
}
// Random Thought :  my A and B are also randomly generated bruh ;}

// deb1(llabs(closestProduct-k));
// for4(i, 1, 1000, 1) {
// lld rightIdx = n - 1, leftIdx = 0;
// while (rightIdx > leftIdx) {
// 	leftIdx = 0;
// 	// sort(leftIdx+all(brr));
// 	leftIdx = 0;
// 	lld thisClosestProduct = closestProduct;
// 	// thisClosestProduct += -(arr[rightIdx] * brr[rightIdx]) - (arr[leftIdx] * brr[leftIdx])
// 	//                       + (arr[leftIdx] * brr[rightIdx] + brr[leftIdx] * arr[rightIdx]);

// 	lld maskLeftIdx = leftIdx;// maskRightIdx = rightIdx;
// 	// lld ihehi = leftIdx;
// 	if (llabs(thisClosestProduct - k) >= llabs(closestProduct - k)) {
// 		// cout << "h,\n";
// 		lld hairu = thisClosestProduct;
// 		while (maskLeftIdx < rightIdx) {
// 			hairu += -(arr[rightIdx] * brr[rightIdx]) - (arr[maskLeftIdx] * brr[maskLeftIdx])
// 			         + (arr[maskLeftIdx] * brr[rightIdx] + brr[maskLeftIdx] * arr[rightIdx]);
// 			if (llabs(hairu - k) < llabs(thisClosestProduct - k)) {
// 				// // cout << "hairubb\n";
// 				// lld baby = llabs(hairu - k);
// 				// deb1(baby);
// 				leftIdx = maskLeftIdx;
// 				thisClosestProduct = hairu;
// 			}
// 			maskLeftIdx++;
// 		}

// 	}

// 	if (llabs(thisClosestProduct - k) < llabs(closestProduct - k)) {
// 		// rightIdx = n-1; leftIdx = 0;
// 	// } else if (llabs(thisClosestProduct - k) > llabs(closestProduct - k)) {
// 	// 	break;
// 	// } else {
// 		closestProduct = thisClosestProduct;
// 		// edges[leftIdx] = rightIdx;
// 		// edges[rightIdx] = leftIdx;
// 		swap(brr[leftIdx], brr[rightIdx]);
// 	}
// 	// leftIdx = ihehi;

// 	// leftIdx++;
// 	rightIdx--;
// }// while

// } // multi attack