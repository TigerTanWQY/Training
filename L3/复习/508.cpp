#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
#define _v first
#define _w second

pair<int, int> a[1003];
int f[1003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, V;
	cin >> n >> V;
	for(int i = 1; i <= n; ++i)
		cin >> a[i]._v >> a[i]._w;
	for(int i = 1; i <= n; ++i)
		for(int j = a[i]._v; j <= V; ++j)
			f[j] = max(f[j], f[j - a[i]._v] + a[i]._w);
	cout << f[V] << endl;
	return 0;
}