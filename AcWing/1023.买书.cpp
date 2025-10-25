#include <bits/stdc++.h>
using namespace std;

constexpr const int v[]{0, 10, 20, 50, 100};
constexpr const int n = 4;
int f[1003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int V;
	cin >> V;
	f[0] = 1;
	for(int i = 1; i <= n; ++i)
		for(int j = v[i]; j <= V; ++j)
			f[j] += f[j - v[i]];
	cout << f[V] << endl;
	return 0;
}
