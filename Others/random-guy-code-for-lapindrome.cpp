#include<bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	vector<string>name;
	int t, a[26], b[26];
	cin >> t;
	for (int i = 0; i < t; i++) {       //storing names in a vector
		string str;
		cin >> str;
		name.push_back(str);
	}

	for (int i = 0; i < t; i ++) {
		for (int i = 0; i <= 26; i++) {      // initialising arrays
			a[i] = 0;
			b[i] = 0;
		}
		string n = name[i];
		string sub1, sub2;

		int len = n.length();

		if (len % 2 == 0) {
			sub1 = n.substr(0, n.length() / 2);                 //division of string if length is even
			sub2 = n.substr(n.length() / 2, n.length());
		}
		else
		{
			sub1 = n.substr(0, n.length() / 2);
			sub2 = n.substr((n.length() + 1) / 2, n.length()); //division of string if length is odd
		}

		cout << sub1 << "\n";
		cout << sub2 << "\n";

		for (int i = 0; i < sub1.length(); i++) {
			if (a[sub1[i] - 97] == 0) {           //placing characters accorrding to ASCII values in sub1
				a[sub1[i] - 97] =  1;
			} else {
				a[sub1[i] - 97] ++;
			}
		}
		for (int i = 0; i < sub2.length(); i++) {
			if (b[sub2[i] - 97] != 0) {           //placing characters accorrding to ASCII values in sub2
				b[sub2[i] - 97] =  1;
			} else {
				b[sub2[i] - 97] ++;
			}
		}

		bool ans = true;
		for (int i = 0; i < 26; i++) {
			if (a[i] != b[i]) {
				ans = false;
				break;
			}
		}

		if (ans) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}