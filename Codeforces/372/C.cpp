#include <iostream>
#include <cmath>
#include <deque>
#include <algorithm>
using namespace std;
using LL = long long;

const int N = 150003;
const int M = 303;
int a[M], b[M], t[M];
LL f[2][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, d;
	cin >> n >> m >> d;
	for(int i = 1; i <= m; ++i)
		cin >> a[i] >> b[i] >> t[i];
	for(int i = 1; i <= n; ++i)
		f[1][i] = -0x3f3f3f3f3f3f3f3f;
	for(int i = 1; i <= m; ++i) {
		int now = (i & 1), last = ((i - 1) & 1);
		deque<int> q;
		for(int j = 1; j <= n; ++j) {
			while(!q.empty() && f[last][q.back()] <= f[last][j])
				q.pop_back();
			q.push_back(j);
			if(!q.empty() && q.front() < j - 1LL * (t[i] - t[i - 1]) * d)
				q.pop_front();
			f[now][j] = f[last][q.front()] + b[i] - abs(a[i] - j);
		}
		q.clear();
		for(int j = n; j; --j) {
			while(!q.empty() && f[last][q.back()] <= f[last][j])
				q.pop_back();
			q.push_back(j);
			if(!q.empty() && q.front() > j + 1LL * (t[i] - t[i - 1]) * d)
				q.pop_front();
			f[now][j] = max(f[now][j], f[last][q.front()] + b[i] - abs(a[i] - j));
		}
	}
	LL ans = -0x3f3f3f3f;
	for(int i = 1; i <= n; ++i)
		ans = max(ans, f[m & 1][i]);
	cout << ans;
	cout << endl;
	return 0;
}