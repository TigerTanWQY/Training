#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	string s;
	cin >> n >> q >> s;
	int ans = 0;
	for(int i = 0; i < s.size() - 2; ++i)
		if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')
			++ans;
	for(int p; q--; cout.put('\n')) {
		char ch;
		cin >> p >> ch;
		--p;
		if(s[p] == 'C' && ch != 'C' && (p - 2 >= 0 && s[p - 2] == 'A') && (p - 1 >= 0 && s[p - 1] == 'B'))
			--ans;
		if(ch == 'C' && s[p] != 'C' && (p - 2 >= 0 && s[p - 2] == 'A') && (p - 1 >= 0 && s[p - 1] == 'B'))
			++ans;
		if(s[p] == 'B' && ch != 'B' && (p - 1 >= 0 && s[p - 1] == 'A') && (p + 1 < s.size() && s[p + 1] == 'C'))
			--ans;
		if(ch == 'B' && s[p] != 'B' && (p - 1 >= 0 && s[p - 1] == 'A') && (p + 1 < s.size() && s[p + 1] == 'C'))
			++ans;
		if(s[p] == 'A' && ch != 'A' && (p + 2 < s.size() && s[p + 1] == 'B' && s[p + 2] == 'C'))
			--ans;
		if(ch == 'A' && s[p] != 'A' && (p + 2 < s.size() && s[p + 1] == 'B' && s[p + 2] == 'C'))
			++ans;
		s[p] = ch;
		cout << ans;
	}
	cout.flush();
	return 0;
}