#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	int cnt[4]{};
	for(const auto& ch: s)
		if('1' <= ch && ch <= '3')
			++cnt[ch - '0'];
	if(cnt[1] == 1 && cnt[2] == 2 && cnt[3] == 3)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	return 0;
}
