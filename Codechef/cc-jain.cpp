/*```````````````````````````````````````
    **      **  *******  * *  ******
    **      **  **   **  ***    **
    **      **  **    *  * *    **
    ******* **  *******  * *    **
`````````````````````````````````````````*/

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int llu;
typedef long long int ll;

#define TESTCASES() llu TestCases; cin>>TestCases; while(TestCases--)
#define pb push_back
#define MOD 1000000007
#define FORI(start,end) for(llu i=start; i<end; i++)

int main(){
    TESTCASES(){
        llu n; cin>>n;
        llu arr[32] = {0};
            for (llu i=0; i<n; i++){
            string s; cin>>s;
            llu mask = 0;
            for (int j=0; j<s.length(); j++){
                if( s[j]=='a') mask = mask | (1<<4);
                if( s[j]=='e') mask = mask | (1<<3);
                if( s[j]=='i') mask = mask | (1<<2);
                if( s[j]=='o') mask = mask | (1<<1);
                if( s[j]=='u') mask = mask | (1<<0);
            }
            arr[mask]+=1;
        }
        llu count = 0;
        for(llu i=0; i<32; i++){
            for(llu j=i+1; j<32; j++){
                if((i|j) == 31) count += arr[i]*arr[j];
            }
        }
        cout<<count<<endl;
  }
  return 0;
}
