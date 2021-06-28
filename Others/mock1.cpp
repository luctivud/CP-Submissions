#include <bits/stdc++.h>

using namespace std;



int main() {
    #ifdef LUCTIVUD
      // const auto start_time = std::chrono::high_resolution_clock::now();
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    string s; cin >> s;
    string pattern = "abcdefghijklmnopqrstuvwxyz";
    int n = (int)s.size();
    vector<vector<int>> dp(n+1, vector<int>(27, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 26; j++) {
            if (s[i-1] == pattern[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // int a = (int) 78837997979881787;
    cout << a;

    // cout << 26 - dp[n][26] << "\n";
    return 0;
}