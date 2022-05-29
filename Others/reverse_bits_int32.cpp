#include <bits/stdc++.h>
using namespace std;

int reverseBits(int input1) {
    int32_t num = input1, ans = 0; 

    bitset<32> bits{num};
    for (int i = 0; i < 32; i++) {
        ans += pow(2, 32-i-1) * bits[i];
    }

    return ans;
}

int main() {
    return 0;
}