#include <bits/stdc++.h>
using namespace std;
int dp[10000] = {0};

int fibo(int n){
    if (n==1){
        dp[n] = 0;
    } else if(n == 2){
        dp[n] = 1;
    } else {
        if (dp[n] != 0){
            return dp[n];
        } else {
            dp[n] = fibo(n-1)+fibo(n-2);
        }
    }
    return dp[n];
}

int main(){
    int n = 7;
    cout<<fibo(n);
    return 0;
}