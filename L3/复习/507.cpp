#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
#define _v first
#define _w second

pair<int, int> a[28];
long long f[30003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int V, n;
	cin >> V >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i]._v >> a[i]._w;
	for(int i = 1; i <= n; ++i)
		for(int j = V; j >= a[i]._v; --j)
			f[j] = max(f[j], f[j - a[i]._v] + (long long)a[i]._v * a[i]._w);
	cout << f[V] << endl;
	return 0;
}