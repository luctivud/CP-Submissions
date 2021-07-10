#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int ws = 0, maxLength = 0, maxRepeatLetterCount = 0;
        map<char, int> mp;
        for (int we = 0; we < (int)s.length(); we++) {
            char curr_char = s[we];
            mp[curr_char] += 1;
            maxRepeatLetterCount = max(maxRepeatLetterCount, mp[curr_char]);
            if (we - ws + 1 - maxRepeatLetterCount > k) {
                char left_char = s[ws];
                mp[left_char] -= 1;
                ws += 1;
            }
            maxLength = max(maxLength, we - ws + 1);
        }
        return maxLength;
    }
};