#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int P = 19930726, N = 1e6 + 3;
char s[N], t[N * 2];
int p[N * 2], cnt[N];
int len, n;
LL ans = 1, k;

LL qpow(LL a, LL b) {
	LL res = 1;
	for(; b; a = a * a % P, b >>= 1)
		if(b & 1)
			res = res * a % P;
	return res;
}

void manacher() {
	int m = 0;
	t[++m] = '$';
	for(int i = 1; i <= n; ++i)
	{ t[++m] = s[i]; t[++m] = '$'; }
	int M = 0, R = 0;
	for(int i = 1; i <= m; ++i) {
		if(i > R)
			p[i] = 1;
		else
			p[i] = min(p[2 * M - i], R - i + 1);
		for(; i > p[i] && i + p[i] <= m && t[i - p[i]] == t[i + p[i]]; ++p[i]);
		if(i + p[i] - 1 > R)
		{ M = i; R = i + p[i] - 1; }
		if((p[i] - 1) & 1)
			++cnt[p[i] - 1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k >> s;
	for(int i = n; i; --i)
		swap(s[i], s[i - 1]);
	manacher();
	int tot = 0;
	for(int i = n; i; --i) {
		if(!(i & 1))
			continue;
		tot += cnt[i];
		if(k >= tot) {
			ans = (ans * qpow(i, tot)) % P;
			k -= tot;
		} else {
			ans = (ans * qpow(i, k)) % P;
			k -= tot;
			break;
		}
	}
	if(k > 0)
		ans = -1;
	cout << ans << endl;
	return 0;
}
