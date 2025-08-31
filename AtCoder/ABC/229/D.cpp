#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 200003;
int f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int k;
	cin >> s >> k;
	int n = s.size();
	for(int i = 0; i < n; ++i)
		if(s[i] == '.')
			f[i + 1] = f[i] + 1;
		else
			f[i + 1] = f[i];
	int ans = 0;
	for(int L = 0, R = 0; L < n; ++L) {
		while(R < n && f[R + 1] - f[L] <= k)
			++R;
		ans = max(ans, R - L);
	}
	cout << ans;
	return 0;
}