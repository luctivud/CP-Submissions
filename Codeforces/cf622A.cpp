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
    llu a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3,greater<llu>());
    llu count = 0;
    for(int i=0;i<3;i++){
      if(a[i]>0){
        count+=1;
        a[i]-=1;
      }
    }
    // cout<<a[0]<<a[1]<<a[2];
    if (a[0]>=2){
      if(a[1] >=2){
        if(a[2]>=2){
          count+=3;
          a[0]-=2;a[1]-=2;a[2]-=2;
        } else if(a[2]>=1){
          count+=2;
          a[0]-=1;a[1]-=2;a[2]-=1;
        } else {
          a[0]-=1;a[1]-=1;
          count+=1;
          
        }
      } else if ( a[1] >= 1){
        if(a[2]>=1){
          a[0]-=2;a[1]-=1;a[2]-=1;
          count+=2;
        } else if(a[2]>=0){
          a[0]-=1;a[1]-=1;
          count+=1;
        }
      }
    } else if(a[0]>=1){
      if (a[1] >= 1){
        a[0]-=1;a[1]-=1;
        count+=1;
      }
    } 
    if(a[0] && a[1] && a[2]){
      count+=1;
      a[0]--;a[1]--;a[2]--;
    }
    cout<<count<<endl;
  }
  return 0;
}
