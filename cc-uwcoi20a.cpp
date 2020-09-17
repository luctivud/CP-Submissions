/****************************************************************************
*                 L U C T I V U D   - x -   L  I  G  H  T                   *
****************************************************************************/
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int llu;
typedef long long int ll;

#define pb push_back
#define MOD 1000000007

#define TEST() int t; cin>>t; while(t--)
#define FORI(start,end) for(llu i=start; i<end; i++)

int main(){
  TEST(){
    llu n;
    cin>>n;
    llu mx = 0;
    for (llu i=0; i<n; i++){
        llu x; cin>>x;
        // cout<<mx<<" ";
        if (x>mx) mx = x;
    }
    cout << mx << endl;
  }
  return 0;
}
