#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define all(a) a.begin(),a.end()
#define mset(a,b) memset(a,b,sizeof(a));
#define rep(i,n) for(int i=0;i<n;i++)
#define repb(i,n) for(int i=n-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define rep1b(i,n) for(int i=n;i>=1;i--)
#define pi pair<int,int>
#define pb push_back
#define f first 
#define s second
#define endl "\n"
#define MAX (int)1e5+1
const int mod =(int)1e9+7;
int n,k; 
int arr[MAX];
int dp[MAX][100+2][3];

int fun(int i,int j,int cnt){
    if(i==n&&j==k&&cnt==1)return 0;
    if(i==n)return (int)-1e14; 
    if (j > k) return 0ll;
    if(dp[i][j][cnt]!=-1)return dp[i][j][cnt];
    int ans=LLONG_MIN;
    if(cnt==0){
        ans=max({ans,j*arr[i]+fun(i+1,j,1),fun(i+1,j,0)});
    }
    else{
        ans=max({ans,j*arr[i]+fun(i+1,j,1),fun(i,j+1,0)});
    } 
    return dp[i][j][cnt]=ans;
    
}
void solve(){
    cin>>n>>k;
    rep(i,n+1){
        rep(j,k+1){
            rep(cnt,3){
                dp[i][j][cnt]=-1;
            }
        }
    }
    rep(i,n)cin>>arr[i];
    cout<<fun(0,1,0);
 
}
int32_t main() 
{
    FIN;
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
}