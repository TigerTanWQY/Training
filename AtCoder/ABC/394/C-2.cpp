#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	string ans;
	size_t i = 0;
	while(i < s.size())
		if(i + 1 < s.size() && s[i] == 'W' && s[i + 1] == 'A') {
			ans += "AC";
			i += 2;
		} else {
			ans += s[i];
			i += 1;
		}
	cout << ans << endl;
	return 0;
}
