#include <bits/stdc++.h>
using namespace std;

int f[2][20003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1, w, v, s; i <= n; ++i) {
		cin >> w >> v >> s;
		for(int r = 0; r < w; ++r) {
			deque<int> q;
			for(int j = r; j <= m; j += w) {
				while(!q.empty() && q.front() < j - w * s)
					q.pop_front();
				while(!q.empty() && f[i-1&1][q.back()] + (j-q.back()) / w * v <= f[i-1&1][j])
					q.pop_back();
				q.push_back(j);
				f[i&1][j] = f[i-1&1][q.front()] + (j-q.front()) / w * v;
			}
		}
	}
	cout << f[n&1][m] << endl;
	return 0;
}
