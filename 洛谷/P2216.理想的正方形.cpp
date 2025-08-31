#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

constexpr const int N = 1'003;
int a[N][N], X[2][N][N], Y[2][N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> a[i][j];
	for(int i = 1; i <= n; ++i) {
		deque<int> q[2];
		q[0].push_back(1); q[1].push_back(1);
		for(int j = 2; j <= m; ++j) {
			while(!q[0].empty() && a[i][j] >= a[i][q[0].back()])
				q[0].pop_back();
			while(!q[1].empty() && a[i][j] <= a[i][q[1].back()])
				q[1].pop_back();
			q[0].push_back(j); q[1].push_back(j);
			while(j - q[0].front() >= k)
				q[0].pop_front();
			while(j - q[1].front() >= k)
				q[1].pop_front();
			if(j >= k) {
				X[0][i][j - k + 1] = a[i][q[0].front()];
				X[1][i][j - k + 1] = a[i][q[1].front()];
			}
		}
	}
	for(int j = 1; j <= m - k + 1; ++j) {
		deque<int> q[2];
		q[0].push_back(1); q[1].push_back(1);
		for(int i = 2; i <= n; ++i) {
			while(!q[0].empty() && X[0][i][j] >= X[0][q[0].back()][j])
				q[0].pop_back();
			while(!q[1].empty() && X[1][i][j] <= X[1][q[1].back()][j])
				q[1].pop_back();
			q[0].push_back(i); q[1].push_back(i);
			while(i - q[0].front() >= k)
				q[0].pop_front();
			while(i - q[1].front() >= k)
				q[1].pop_front();
			if(i >= k) {
				Y[0][i - k + 1][j] = X[0][q[0].front()][j];
				Y[1][i - k + 1][j] = X[1][q[1].front()][j];
			}
		}
	}
	int ans = 0x3f3f3f3f;
	for(int i = 1; i <= n - k + 1; ++i)
		for(int j = 1; j <= m - k + 1; ++j)
			ans = min(ans, Y[0][i][j] - Y[1][i][j]);
	cout << ans << endl;
	return 0;
}