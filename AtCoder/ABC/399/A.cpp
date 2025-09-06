#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; string s, t;
	cin >> n >> s >> t;
	int ans = 0;
	for(int i = 0; i < n; ++i)
		if(s[i] != t[i])
			++ans;
	cout << ans << endl; return 0;
}
