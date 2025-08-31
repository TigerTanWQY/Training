#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define x first
#define y second

constexpr const int N = 2e5 + 3;
pair<LL, LL> a[N];
char s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	LL ans = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> (s + 1);
		for(int j = 1; s[j]; ++j)
			if(s[j] == 'X')
				++a[i].x;
			else {
				a[i].y += s[j] - '0';
				ans += (s[j] - '0') * a[i].x;
			}
	}
	sort(a + 1, a + n + 1, [](const pair<LL, LL>& A, const pair<LL, LL>& B)
		{ return A.x * B.y > A.y * B.x; });
	LL cnt = 0;
	for(int i = 1; i <= n; ++i) {
		ans += cnt * a[i].y;
		cnt += a[i].x;
	}
	cout << ans << endl;
	return 0;
}