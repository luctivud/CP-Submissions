#include <bits/stdc++.h>

using namespace std;
#define int long long 
const int M = 1e9+7;
const int MAXN = 1e6+10;

vector<int> prime(MAXN,0);

vector<int> dp;

int32_t main(){
    #ifdef LUCTIVUD
      // const auto start_time = std::chrono::high_resolution_clock::now();
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif
    int l, r, s; cin >> l >> r >> s;

    for(int i = 2; i <= 1e6+2; ++i){
        if(prime[i] > 0){
            continue;
        }
        for(int j = i; j <= 1e6+2; j+=i){
            prime[j] += 1;
        }
    }

    vector<int> a;
    for(int i=l; i<=r;++i){
        a.emplace_back(prime[i]);
        // cerr << prime[i] << ' ';
    }
    // cerr << endl;
    // sort(a.begin(),a.end());

    dp.assign(s+1,0);
    int n = a.size();

    dp[0] = 1;

    for(int i=0;i<n;++i){
        for(int j=s;j>=a[i];--j){
            dp[j] = (dp[j-a[i]] + dp[j])%M;
        }
    }

    cout << dp[s] << endl;
    return 0;
}