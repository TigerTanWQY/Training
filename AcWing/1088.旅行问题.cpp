#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 1e6 + 3, M = N << 1;
bool f[N];
int p[M], d[M], q[M], n; // 必需手写 deque，不然会 MLE
LL sp[M], sd[M];

LL g(int j)
{ return sp[j] - sd[j]; }
LL h(int j)
{ return sd[j-2] - sp[j-1]; }
LL get_val1(int i, int j)
{ return sd[i-1] - sp[i-1] + g(j); }
LL get_val2(int i, int j)
{ return sp[i+n] - sd[i+n-1] + h(j); }

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> p[i] >> d[i];
		p[i+n] = p[i];
		d[i+n] = d[i];
	}
	for(int i = 1; i <= n<<1; ++i) {
		sd[i] = sd[i-1] + d[i];
		sp[i] = sp[i-1] + p[i];
	}
	int hh = 0, tt = -1;
	for(int i = 1; i <= n<<1; ++i) {
		for(; hh <= tt && i-q[hh] > n; ++hh);
		if(i > n && get_val1(i-n, q[hh]) >= 0)
			f[i-n] = true;
		for(; hh <= tt && g(q[tt]) >= g(i); --tt);
		q[++tt] = i;
	}
	hh = 0; tt = -1;
	for(int i = n<<1; i; --i) {
		for(; hh <= tt && q[hh]-i > n; ++hh);
		if(i <= n && get_val2(i, q[hh]) >= 0)
			f[i] = true;
		for(; hh <= tt && h(q[tt]) >= h(i); --tt);
		q[++tt] = i;
	}
	for(int i = 1; i <= n; ++i)
		cout << (f[i]? "TAK": "NIE") << '\n';
	cout.flush(); return 0;
}
