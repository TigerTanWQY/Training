#include <iostream>
#include <list>
using namespace std;

list<int> mrge(const list<int>& x, const list<int>& y) {
	list<int> res;
	auto itx = x.cbegin(), ity = y.cbegin();
	for(; itx != x.cend() && ity != y.cend(); )
		if(*itx < *ity) {
			res.push_back(*itx);
			++itx;
		} else {
			res.push_back(*ity);
			++ity;
		}
	for(; itx != x.cend(); ++itx)
		res.push_back(*itx);
	for(; ity != y.cend(); ++ity)
		res.push_back(*ity);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	list<int> a[2];
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		a[0].push_back(x);
	}
	for(int i = 1, x; i <= m; ++i) {
		cin >> x;
		a[1].push_back(x);
	}
	for(const auto& x: mrge(a[0], a[1]))
		cout << x << ' ';
	cout << endl;
	return 0;
}