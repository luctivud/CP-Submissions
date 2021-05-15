
#include <bits/stdc++.h>
using namespace std;

typedef long long int lld;

class PointsInAPlane {
	static bool isCollinear(int x1, int y1, int x2, int y2, int x3, int y3) {
		return (x2-x1) * (y3-y1) == (x3-x1) * (y2-y1);
	}
  public:
   int howManyTriangles(vector <int> x, vector <int> y) {
   		int ans = 0;
   		int n = (int) x.size();
   		for (int i = 0; i < n; i++) {
   			for (int j = i+1; j < n; j++) {
   				for (int k = j+1; k < n; k++) {
   					if (!isCollinear(x[i], y[i], x[j], y[j], x[k], y[k])) {
   						ans += 1;
   					}
   				}
   			}
   		}
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
  PointsInAPlane obj;

  lld N; vector<lld> arr(N);
  readNumber(N); readVector(arr);


  return 0;
}
