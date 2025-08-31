#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	vector<int> ans;
	for(int i = 0, j = 1; j < s.size(); ++j)
		if(s[j] == '|') {
			ans.push_back(j - i - 1);
			i = j;
		}
	for(const auto& x: ans)
		cout << x << ' ';
	cout << endl;
	return 0;
}
