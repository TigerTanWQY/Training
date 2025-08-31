#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 3e6 + 3;
char s[N], t[N];
int nxt[N], pre[N], rd[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m >> s >> t;
	for(int i = n; i; --i)
		swap(s[i], s[i - 1]);
	for(int i = m; i; --i)
		swap(t[i], t[i - 1]);
	nxt[1] = 0; s[n + 1] = t[m + 1] = '$';
	for(int i = 2, k = 0; i <= m; ++i) {
		while(k && t[k + 1] != t[i])
			k = nxt[k];
		if(t[k + 1] == t[i])
			++k;
		nxt[i] = k;
	}
	for(int i = 1, k = 0; i <= n; ++i) {
		while(k && t[k + 1] != s[i])
			k = nxt[k];
		if(t[k + 1] == s[i])
			++k;
		if(k == m) {
			++pre[i - m + 1];
			k = nxt[k];
		}
	}
	for(int i = 1; i <= n; ++i)
		pre[i] += pre[i - 1];
	for(int i = 1; i <= n; ++i)
		pre[i] += pre[i - 1];
	unsigned ans = 0;
	for(int i = 1, mx = 0, R = 0; i <= n; ++i) {
		rd[i] = (i < R? min(R - i, rd[mx * 2 - i]): 1);
		while(s[i + rd[i]] == s[i - rd[i]])
			++rd[i];
		if(R < i + rd[i])
		{ mx = i; R = i + rd[i]; }
	}
	for(int i = 1; i <= n; ++i) {
		if(rd[i] * 2 - 1 < m)
			continue;
		int L = i - rd[i], R = i + rd[i] - m, M = (L + R) >> 1;
		ans += (pre[R] - pre[M] - pre[((L + R) & 1)? M: M - 1] + pre[L - 1]);
	}
	cout << ans << endl;
	return 0;
}
