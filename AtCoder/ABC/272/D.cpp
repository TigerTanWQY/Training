#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int d[403][403];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	memset(d, -1, sizeof(d));
	d[0][0] = 0;
	queue<pair<int, int>> q;
	q.push({0, 0});
	while(!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for(int i = 0; i < n; ++i) {
			int a = m - (x - i) * (x - i), b = sqrt(a);
			if(a != b * b)
				continue;
			if(0 <= y - b && y - b < n && d[i][y - b] == -1) {
				d[i][y - b] = d[x][y] + 1;
				q.push({i, y - b});
			} if(0 <= y + b && y + b < n && d[i][y + b] == -1) {
				d[i][y + b] = d[x][y] + 1;
				q.push({i, y + b});
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j)
			cout << d[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}