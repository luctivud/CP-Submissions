/* ----- Code By Nilesh Gupta -----*/
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mod 1000000007
#define vi vector<ll>
#define pp pair<ll, ll>
#define ff first
#define ss second
#define all(n) n.begin(),n.end()
#define INF 1e9

using namespace std;

#define lld int

// find totient Value complexity O(sqrt(N))
lld getPhiVal(lld n0n) {
    lld result = n0n;
    for (lld i = 2; i * i <= n0n; i++) {
        if (n0n % i == 0) {
            while (n0n % i == 0)
                n0n /= i;
            result -= result / i;
        }
    }
    if (n0n > 1)
        result -= result / n0n;
    return result;
}




bool isPrime(int n) {
    if(n == 0 || n == 1)
        return false;
    for(int i=2; i*i<=n; i++)
        if(n%i == 0)
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1, n, val;
    cin>>n>>t;

    vector<int> pri;
    pri.pb(0);
    for(int i=1; i<=n; i++) {
        cin>>val;

        int res = getPhiVal(val);

        if(isPrime(res)) {
            pri.pb(1);
        } else {
            pri.pb(0);
        }
    }

    for(int i=2; i<=n; i++)
        pri[i] += pri[i-1];

    while(t--)
    {
        int l, r;
        cin>>l>>r;
        cout<<pri[r] - pri[l-1]<<"\n";
    }
    
    return 0;
}