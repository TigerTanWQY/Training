#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(string s; _T--; cout.put('\n')) {
		int n;
		cin >> n >> s;
		char ch = s[0];
		int len = 1, cnt0 = 0, cnt1 = 0, max0 = 0, max1 = 0;
		for(int i = 0; i < n; ++i)
			if(s[i] == '1')
				++cnt1;
			else
				++cnt0;
		for(int i = 1; i < n; ++i)
			if(s[i] == ch)
				++len;
			else {
				if(ch == '0')
					max0 = max(max0, len);
				else
					max1 = max(max1, len);
				ch = s[i]; len = 1;
			}
		if(ch == '0')
			max0 = max(max0, len);
		else
			max1 = max(max1, len);
		cout << min((cnt1 - max1) * 2 + cnt0, (cnt0 - max0) * 2 + cnt1);
	}
	cout.flush(); return 0;
}
