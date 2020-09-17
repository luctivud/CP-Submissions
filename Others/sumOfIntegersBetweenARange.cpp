#include <iostream> 
using namespace std; 

#define mod 1000000007 
typedef unsigned long long int llu ;

llu solve(llu l, llu r){
    llu sumL = l%2==0 ? (((l/2)%mod)*((l-1)%mod))%mod : ((l%mod)*((l-1)/2)%mod)%mod;
    llu sumR = r%2==0 ? (((r+1)%mod)*((r/2)%mod))%mod : ((((r+1)/2)%mod)*(r%mod))%mod;
    return sumR - sumL;
}
  
int main() { 
    llu l, r;
    cin >> l >> r;
    cout << solve(l, r) << endl;
    return 0; 
} 