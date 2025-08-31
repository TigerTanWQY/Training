#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
char s[N], t[N * 2];
int p[N * 2], L[N * 2], R[N * 2], n;

void manacher() {
	int m = 1;
	t[0] = '#'; t[1] = '$';
	for(int i = 1; i <= n; ++i)
	{ t[++m] = s[i]; t[++m] = '$'; }
	n = (n << 1) + 2;
	t[n] = '~';
	int mR = 0, M = 0;
	for(int i = 1; i <= n; ++i) {
		if(i > mR)
			p[i] = 1;
		else
			p[i] = min(p[M * 2 - i], mR - i);
		for(; t[i + p[i]] == t[i - p[i]]; ++p[i]);
		if(p[i] + i > mR)
		{ mR = p[i] + i; M = i; }
		R[i + p[i] - 1] = max(R[i + p[i] - 1], p[i] - 1);
		L[i - p[i] + 1] = max(L[i - p[i] + 1], p[i] - 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> (s + 1);
	n = strlen(s + 1);
	manacher();
	for(int i = n; i >= 1; i -= 2)
		R[i] = max(R[i], R[i + 2] - 2);
	for(int i = 1; i <= n; i += 2)
		L[i] = max(L[i], L[i - 2] - 2);
	int ans = 0;
	for(int i = 1; i <= n; i += 2)
		if(R[i] && L[i])
			ans = max(ans, L[i] + R[i]);
	cout << ans << endl;
	return 0;
}
