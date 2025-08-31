#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, dep, f[15];

bool dfs(const int& d, int u) {
	if(f[d] == n)
		return true;
	if(d >= dep)
		return false;
	u = max(u, f[d]);
	if(u * (1 << dep - d) < n)
		return false;
	for(int i = 0; i <= d; ++i) {
		f[d + 1] = f[d] + f[i];
		if(dfs(d + 1, u))
			return true;
		f[d + 1] = abs(f[d] - f[i]);
		if(dfs(d + 1, u))
			return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin >> n && n) {
		if(n == 1) {
			cout << "0\n";
			continue;
		}
		f[0] = 1;
		for(dep = 1; !dfs(0, 1); ++dep); //IDDFS
		cout << dep << '\n';
	}
	return 0;
}