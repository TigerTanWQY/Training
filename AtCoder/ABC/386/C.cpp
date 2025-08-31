#include <bits/stdc++.h>
using namespace std;

int cnts[128], cntt[128];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int k;
	string s, t;
	cin >> k >> s >> t; // s->t
	int n = s.size(), m = t.size();
	if(abs(n - m) > 1)
		cout << "No";
	else if(n == m) {
		bool flag = false;
		for(int i = 0; i < n; ++i)
			if(s[i] != t[i])
				if(flag) {
					cout << "No" << endl;
					return 0;
				} else
					flag = true;
		cout << "Yes";
	} else {
		if(n < m)
		{ swap(s, t); swap(n, m); }
		for(const auto& ch: s)
			++cnts[ch];
		for(const auto& ch: t)
			++cntt[ch];
		char id = '\0';
		for(char ch = 'a'; ch <= 'z'; ++ch)
			if(cnts[ch] != cntt[ch])
				if(id || cnts[ch] - cntt[ch] > 1) {
					cout << "No" << endl;
					return 0;
				} else
					id = ch;
		cout << "Yes";
	}
	cout << endl;
	return 0;
}
