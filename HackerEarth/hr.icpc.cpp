#include<bits/stdc++.h>
using namespace std;

int checkSame(string a, string b, int m){
  int res = 0;
  for(int i=0;i<m;i++)
    if (a[i] == '1' || b[i] == '1')
      res+=1;
  return res;
}

int main(){
  int n, m;
  cin>>n>>m;
  string arr[n];
  string str;
  for (int i=0;i<n;i++){
    cin>>str;
    arr[i] = str;
  }
  int mx = -1;
  int count = 0;
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      int res = checkSame(arr[i],arr[j],m);
      if (res>mx){
        mx = res;
        count = 1;
      } else if(res == mx){
        count += 1;
      }
    }
  }
  cout<<mx<<"\n"<<count;
  return 0;
}