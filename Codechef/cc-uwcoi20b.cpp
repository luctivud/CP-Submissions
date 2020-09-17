/****************************************************************************
*                 L U C T I V U D   - x -   L  I  G  H  T                   *
*                               00.200207.00                                *
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
    llu n; cin>>n;
    llu odd=0, even=0;
    llu x;
    for(llu i=0; i<n; ++i){
        cin>>x;
        if(x%2) odd+=1;
        else even+=1;
    }
    cout<<odd*even<<endl;
  }
  return 0;
}
