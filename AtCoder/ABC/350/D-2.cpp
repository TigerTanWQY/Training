#include <iostream>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	dsu uf(n);
	long long ans = 0;
	for(int a, b; m--; ) {
		cin >> a >> b;
		--a;
		--b;
		if(!uf.same(a, b))
			ans += 1LL * uf.size(a) * uf.size(b);
		uf.merge(a, b);
		--ans;
	}
	cout << ans;
	return 0;
}