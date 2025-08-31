#include <iostream>
using namespace std;
using LL = long long;

constexpr const int N = 100'003;
int a[N], d[N], n;
LL c1[N], c2[N];

LL lowbit(const LL x)
{ return x & (-x); }

LL query(int x) {
	LL res = 0;
	int id = x;
	for(; x; x -= lowbit(x))
		res += (id + 1) * c1[x] - c2[x];
	return res;
}

void modify(int x, const LL k) {
	int id = x;
	for(; x < N; x += lowbit(x)) {
		c1[x] += k;
		c2[x] += k * id;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		d[i] = a[i] - a[i - 1];
		modify(i, d[i] - d[i - 1]);
	}
	for(int opt; m--; ) {
		cin >> opt;
		if(opt == 1) {
			int L, R, k, d;
			cin >> L >> R >> k >> d;
			modify(L, k);
			modify(R + 1, -k - (LL) (R - L + 1) * d);
			modify(L + 1, d - k);
			modify(R + 2, k + (R - L) * (LL)d);
		} else {
			int p;
			cin >> p;
			cout << query(p) << '\n';
		}
	}
	cout.flush();
	return 0;
}