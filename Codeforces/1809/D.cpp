#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
using LL = long long;

const LL W = 1000000000000LL;
const LL D = 1000000000001LL;
const int N = 300003;
int a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(string s; T--; ) {
		cin >> s;
		int n = s.size();
		s = '$' + s;
		for(int i = 1; i <= n; ++i)
			a[i] = a[i - 1] + s[i] - '0';
		for(int i = n; i; --i)
			b[i] = b[i + 1] + '1' - s[i];
		LL ans = 0x3f3f3f3f3f3f3f3f;
		for(int i = 0; i <= n; ++i)
			ans = min(ans, (a[i] + b[i + 1]) * D);
		for(int i = 1; i <= n; ++i)
			if(s[i] == '1' && s[i + 1] == '0')
				ans = min(ans, W + (a[i - 1] + b[i + 2]) * D);
		cout << ans << '\n';
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
	}
	return 0;
}