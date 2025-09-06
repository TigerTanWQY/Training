#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 5e6 + 3;
int a[N], b[N], L[N], R[N], stk[N], top;
LL sb[N];

int main() {
	freopen("town.in", "r", stdin);
	freopen("town.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		sb[i + 1] = sb[i] + b[i];
	}
	top = -1;
	for(int i = 0; i < n; ++i) {
		for(; top >= 0 && a[stk[top]] >= a[i]; --top);
		L[i] = (top >= 0? stk[top]: -1);
		stk[++top] = i;
	}
	top = -1;
	for(int i = n - 1; i >= 0; --i) {
		for(; top >= 0 && a[stk[top]] >= a[i]; --top);
		R[i] = (top >= 0? stk[top]: n);
		stk[++top] = i;
	}
	LL ans = 0;
	for(int i = 0; i < n; ++i) {
		int l = L[i] + 1, r = R[i] - 1;
		LL s = min(sb[r + 1] - sb[l], (LL)a[i]);
		ans = max(ans, s * s);
	}
	cout << ans << endl;
	return 0;
}
