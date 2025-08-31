#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int idx[128];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 0; i < s.size(); ++i)
		idx[s[i]] = i;
	for(char ch = 'B'; ch <= 'Z'; ++ch)
		ans += abs(idx[ch] - idx[ch - 1]);
	cout << ans << endl;
	return 0;
}