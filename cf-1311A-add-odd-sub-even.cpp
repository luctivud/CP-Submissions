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
      ll a, b;
      cin>>a>>b;
      ll ans = 1;
      if (b==a){
          ans = 0;
      } else if (b>a){
          if ((b-a)%2==0) ans = 2;
      } else {
          if ((a-b)%2) ans = 2;
      }
      cout<<ans<<endl;
  }
  return 0;
}
