#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1003;
int a1[N][N], a2[N][N], a3[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	for(int x, y, z, ans = 0; q--; cout.put('\n')) {
		cin >> x >> y >> z;
		++a1[x][y];
		if(a1[x][y] == n)
			++ans;
		++a2[y][z];
		if(a2[y][z] == n)
			++ans;
		++a3[z][x];
		if(a3[z][x] == n)
			++ans;
		cout << ans;
	}
	cout.flush();
	return 0;
}
