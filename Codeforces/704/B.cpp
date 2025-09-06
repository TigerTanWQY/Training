#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 5e3 + 7;
int t[N];
LL x[N], a[N], b[N], c[N], d[N];

inline LL S(int i, int j)
{ return i < j ? x[j] - x[i] + d[i] + a[j] : x[i] - x[j] + c[i] + b[j]; }

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, s, e;
	cin >> n >> s >> e;
	for(int i = 1; i <= n; ++i)
		cin >> x[i];
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		cin >> b[i];
	for(int i = 1; i <= n; ++i)
		cin >> c[i];
	for(int i = 1; i <= n; ++i)
		cin >> d[i];
	LL ans = S(s, e); t[s] = e;
	for(int i = 1; i <= n; ++i)
		if(i != s && i != e) {
			pair<LL, int> o = {1e18, 0};
			for(int j = s; j != e; j = t[j])
				o = min(o, {S(j, i) + S(i, t[j]) - S(j, t[j]), j});
			t[i] = t[o.second]; t[o.second] = i; ans += o.first;
		}
	cout << ans << endl;
	return 0;
}
