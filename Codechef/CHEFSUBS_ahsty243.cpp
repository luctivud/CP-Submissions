#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define int ll
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define ff first
#define ss second
#define vi vector<ll>
#define vii vector<vector<ll>>
#define viii vector<vii>
#define vpi vector<pii>
// #define mod 1000000007
#define MOD 1000000007
#define full(a) a.begin(),a.end()
#define inf 1e9
#define minf -1e9
#define dd long double
#define fori(i,x,n) for(ll i=x;i<=n;i++)
#define umap unordered_map<ll,ll>
#define mmap map<ll,ll>
#define mm 998244353
#define mod2 1000000009
#define br cout<<"\n"
#define MAX 1000005
#define N 1000005

ll dp[100001][101][2];
vi a;
int n, k;

void reset() {
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j][0] = dp[i][j][1] = -1e18;
    }
  }
}

int fun(int i, int j, int tak) {
  if (j == k + 1 and tak==0)return 0;
  if (i == n){
      if(j==k and tak==1)return 0;
      return -1e16;
  }

  int &res = dp[i][j][tak];
  if (res != -1e18)return res;

  if (tak == 0) {
    return res = max({fun(i + 1, j, 0), a[i] * j + fun(i + 1, j, 1)});
  }
  else {
    res = max({a[i] * j + fun(i + 1, j, 1), fun(i, j + 1, 0)});
    return res;
  }
}


void solve() {
  cin >> n >> k;
  // dp.resize(n, vii(k + 1, vi(2, -1e18)));
  reset();


  a.resize(n);
  fori(i, 0, n - 1)cin >> a[i];

  cout << fun(0, 1, 0) << "\n";

  
  a.clear();


  return;
}






int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif


  ll t;
  t = 1;
  cin >> t;
  // sieve();
  fori(test, 1, t) {



    solve();





  }


  return 0;
}