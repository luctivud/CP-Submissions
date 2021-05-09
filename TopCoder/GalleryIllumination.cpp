
#include <bits/stdc++.h>
using namespace std;

typedef long long int lld;

class GalleryIllumination {
  public:
   int countDarkCells(int n, int m, vector <string> s) {
   		for (int i=0; i<n; i++) {
   			for (int j = 0; j < m; j++) {
   				if (s[i][j] == 'O') {
   					int posx = i+1, posy = j+1;
   					while (posx < n and (s[posx][j] == '.' or s[posx][j] == '$')) {
   						s[posx++][j] = '$';
   					}
   					while (posy < m and (s[i][posy] == '.' or s[i][posy] == '$')) {
   						s[i][posy++] = '$';
   					}
   					posx = i-1, posy = j-1;
   					while (posx >= 0 and (s[posx][j] == '.' or s[posx][j] == '$')) {
   						s[posx--][j] = '$';
   					}
   					while (posy >= 0 and (s[i][posy] == '.' or s[i][posy] == '$')) {
   						s[i][posy--] = '$';
   					}
   				}
   			}
   		}

   		int ans = 0;

   		for (int i=0; i<n; i++) {
   			for (int j = 0; j < m; j++) {
   				cout << s[i][j];
   				if (s[i][j] == '.') {
   					ans++;
   				}
   			}
   			cout << "\n";
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
  GalleryIllumination obj;

  // lld N; vector<lld> arr(N);
  // readNumber(N); readVector(arr);

  cout << obj.countDarkCells(4, 5, (vector<string>){".....",".OO..",".....","....."});


  return 0;
}
