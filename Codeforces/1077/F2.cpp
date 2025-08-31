#include <iostream>
#include <cstring>
#include <deque>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 5'003;
int a[N];
LL f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k, m;
	cin >> n >> k >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	if(n / k > m) {
		cout << "-1" << endl;
		return 0;
	}
	memset(f, -0x3f, sizeof(f));
	f[0][0] = 0;
	for(int j = 1; j <= m; ++j) {
		deque<int> q{0};
		for(int i = 1; i <= n; ++i) {
			while(!q.empty() && q.front() + k < i)
				q.pop_front();
			f[i][j] = f[q.front()][j - 1] + a[i];
			while(!q.empty() && f[i][j - 1] >= f[q.back()][j - 1])
				q.pop_back();
			q.push_back(i);
		}
	}
	LL ans = 0;
	for(int i = n - k + 1; i <= n; ++i)
		ans = max(ans, f[i][m]);
	cout << ans << endl;
	return 0;
}