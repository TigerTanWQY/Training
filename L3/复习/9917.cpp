#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define _t first
#define _x second

constexpr const int N = 1e5 + 3;
pair<int, vector<int>> p[N];
int cnt[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0, m, y; i < n; ++i) {
		cin >> p[i]._t >> m;
		while(m--) {
			cin >> y;
			p[i]._x.push_back(y);
		}
	}
	queue<int> q;
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		q.push(i);
		for(const auto& y: p[i]._x) {
			++cnt[y];
			if(cnt[y] == 1)
				++ans;
		}
		while(!q.empty() && p[q.front()]._t <= p[i]._t - 86400) {
			for(const auto& y: p[q.front()]._x) {
				--cnt[y];
				if(cnt[y] == 0)
					--ans;
			}
			q.pop();
		}
		cout << ans << '\n';
	}
	cout.flush();
	return 0;
}