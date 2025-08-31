#include <iostream>
#include <vector>
#include <bitset>
#include <array>
using namespace std;

constexpr const int N = 100'003;
array<vector<int>, N> v, w;
array<bitset<30>, N> a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	a.fill((1 << 30) - 1);
	for(int i, j, x; m--; ) {
		cin >> i >> j >> x;
		a[i] &= x;
		a[j] &= x;
		v[i].push_back(j);
		v[j].push_back(i);
		w[i].push_back(x);
		w[j].push_back(x);
	}
	for(int i = 1; i <= n; ++i) {
		a[i] = 0;
		for(int j = 0; j < v[i].size(); ++j)
			if(i != v[i][j])
				a[i] |= w[i][j] - a[v[i][j]].to_ullong();
			else
				a[i] |= w[i][j];
		cout << a[i].to_ullong() << ' ';
	}
	cout.flush();
	return 0;
}