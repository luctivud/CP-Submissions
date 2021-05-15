
#include <bits/stdc++.h>
using namespace std;

typedef long long int lld;

class PickTwoCards {
	static double nc2(double n) {
		if (n < 2) return 0.0;
		return (n * (n-1)) / 2;
	}
  public:
  	double equalProbability(string cards) {
		map<char, double> cnt;
		for (auto i : cards) {
			cnt[i] += 1;
		}
		double ans = 0.0;
		for (auto i : cnt) {
			ans += nc2(i.second);
		}
		ans /= nc2((double)cards.length());
		return ans;
  	}
};




void readNumber(lld &N) {
  cin >> N;
}

void readVector(vector<lld> arr) {
  for (auto &i : arr) {
    cin >> i;
  }
}



signed main() {
  PickTwoCards obj;

  // lld N; vector<lld> arr(N);
  // readNumber(N); readVector(arr);

  cout << obj.equalProbability("ABA");


  return 0;
}
