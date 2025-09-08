#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 0; i < s.size(); ++i)
		for(int len = 1; i + len + len < s.size(); ++len) {
			int j = i + len, k = j + len;
			if(s[i] == 'A' && s[j] == 'B' && s[k] == 'C')
				++ans;
		}
	cout << ans << endl;
	return 0;
}
