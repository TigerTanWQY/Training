#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; string s;
	cin >> n >> s;
	vector<bool> p;
	for(int i = 0; i + 1 < n; i += 2)
		if(s[i] != s[i + 1])
			p.push_back(s[i] == 'G' && s[i + 1] == 'H');
	int cnt = 0;
	for(int i = 1; i < p.size(); ++i)
		if(p[i - 1] != p[i])
			++cnt;
	cout << cnt + (p.empty()? 0: p.back()) << endl; return 0;
}
