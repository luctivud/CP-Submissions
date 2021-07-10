#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string p, string s) {
        int ws = 0, matched = 0;
        map<char, int> mp;
        for (auto i : p) {
            mp[i] += 1;
        }
        for (int we = 0; we < s.length(); we++) {
            char curr_char = s[we];
            if (mp.find(curr_char) != mp.end()) {
                mp[curr_char] -= 1;
                if (mp[curr_char] == 0) {
                    matched++;
                }
            }
            if (matched == mp.size()) {
                return true;
            }
            if (we >= p.length() - 1) {
                char left_char = s[ws];
                if (mp.find(left_char) != mp.end()) {
                    if (mp[left_char] == 0) {
                        matched--;
                    }
                    mp[left_char] += 1;
                }
                ws++;
            }
        }
        return false;
    }
};