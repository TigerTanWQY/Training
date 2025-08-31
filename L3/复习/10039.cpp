#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 403;
int d[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	memset(d, -1, sizeof(d));
	d[0][0] = 0;
	queue<pair<int, int>> q;
	q.push({0, 0});
	while(!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for(int i = 0; i < n; ++i) {
			int a = m - (x - i) * (x - i), b = sqrt(a);
			if(a != b * b)
				continue;
			if(0 <= y - b && y - b < n && !~d[i][y - b]) {
				d[i][y - b] = d[x][y] + 1;
				q.push({i, y - b});
			}
			if(0 <= y + b && y + b < n && !~d[i][y + b]) {
				d[i][y + b] = d[x][y] + 1;
				q.push({i, y + b});
			}
		}
	}
	for(int i = 0; i < n; cout.put('\n'), ++i)
		for(int j = 0; j < n; cout.put(' '), ++j)
			cout << d[i][j];
	cout.flush();
	return 0;
}