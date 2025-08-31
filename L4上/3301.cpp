#include <iostream>
#include <utility>
#include <deque>
using namespace std;

const int N = 10003;
int f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, V;
	cin >> n >> V;
	for(int i = 1, v, w, t; i <= n; ++i) {
		cin >> v >> w >> t;
		for(int j = 0; j < v; ++j) {
			deque<pair<int, int>> q;
			for(int k = j, x = 1; k <= V; k += v, ++x) {
				int e = f[k] - x * w, y = x + t;
				while(!q.empty() && q.back().first <= e)
					q.pop_back();
				q.push_back({e, y});
				f[k] = q.front().first + x * w;
				while(!q.empty() && q.front().second == x)
					q.pop_front();
			}
		}
	}
	cout << f[V];
	cout.flush();
	return 0;
}