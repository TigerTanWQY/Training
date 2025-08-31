#include <iostream>
#include <bitset>
#include <queue>
#include <algorithm>
using namespace std;
#define mkp make_pair

constexpr const int d[][3]{{-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}};
constexpr const int N = 1003;
pair<int, int> a[N];
bitset<N> vis;
int n;

void bfs(const int rt) {
	queue<int> q;
	q.push(rt);
	while(!q.empty()) {
		int f = q.front();
		q.pop();
		if(vis[f])
			continue;
		vis[f] = true;
		for(int k = 0; k < 6; ++k) {
			const int tx = a[f].first + d[k][0], ty = a[f].second + d[k][1];
			auto cit = lower_bound(a + 1, a + n + 1, mkp(tx, ty));
			if(*cit == mkp(tx, ty))
				q.push(cit - a);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if(!vis[i]) {
			bfs(i);
			++ans;
		}
	cout << ans << endl;
	return 0;
}