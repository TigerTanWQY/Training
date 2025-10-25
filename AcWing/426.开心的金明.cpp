#include <bits/stdc++.h>
using namespace std;

int f[30003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int V, n;
	cin >> V >> n;
	for(int v, p; n--; ) {
		cin >> v >> p;
		for(int j = V; j >= v; --j)
			f[j] = max(f[j], f[j-v] + v * p);
	}
	cout << f[V] << endl;
	return 0;
}
