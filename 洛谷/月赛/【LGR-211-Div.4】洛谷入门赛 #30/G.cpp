#include <bits/stdc++.h>
using namespace std;

string s[103], t[103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> s[i];
	cin >> m;
	for(int i = 1; i <= m; ++i)
		cin >> t[i];
	for(int i = 1; i <= n; cout.put('\n'), ++i) {
		bool flag = true;
		for(int j = 1; flag && j <= m; ++j)
			if(s[i].find(t[j]) != string::npos)
				flag = false;
		if(flag)
			cout << "No";
		else
			cout << "Yes";
	}
	cout.flush();
	return 0;
}
