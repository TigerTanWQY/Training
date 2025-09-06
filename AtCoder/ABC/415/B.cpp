#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	bool flg = false;
	for(size_t i = 0; i < s.size(); ++i)
		if(s[i] == '#') {
			cout << i + 1 << ",\n"[flg];
			flg = !flg;
		}
	cout.flush(); return 0;
}
