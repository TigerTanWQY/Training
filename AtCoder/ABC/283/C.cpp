#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int n = s.size(), ans = 0;
	for(int i = 0; i < n; ++ans, ++i)
		if(i + 1 < n && s[i] == '0' && s[i + 1] == '0')
			++i;
	cout << ans;
	return 0;
}