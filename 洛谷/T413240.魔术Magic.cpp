#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
using LL = long long;
using __gnu_pbds::gp_hash_table;

constexpr const int MAXN = 1e6;
constexpr const int N = 2'003;
gp_hash_table<int, LL> c;
int a[N];

LL lowbit(const LL& x)
{ return x & (-x); }

LL query(LL x) {
	LL res = 0;
	for(; x; x -= lowbit(x))
		res += c[x];
	return res;
}

void modify(LL x, const LL& d) {
	for(; x < 2 * MAXN; x += lowbit(x))
		c[x] += d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] = MAXN + 1 - a[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans += query(a[i]);
		modify(a[i], 1);
	}
	cout << ans;
	cout.flush();
	return 0;
}