#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 1'000'003;
struct Node {
	int v, t;
	bool operator<(const Node& x) const {
		if(t == x.t)
			return v > x.v;
		else
			return t > x.t;
	}
};
int a[N], b[N], pool[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + m + 1);
	int k = unique(b + 1, b + m + 1) - b - 1, ans = 0;
	priority_queue<Node> q;
	for(int i = 1, tot = 0; i <= m; ++i) {
		a[i] = lower_bound(b + 1, b + k + 1, a[i]) - b;
		if(pool[a[i]]) {
			++ans;
			++pool[a[i]];
		} else if(tot < n) {
			++tot;
			pool[a[i]] = 1;
		} else {
			Node u = q.top();
			q.pop();
			for(; pool[a[u.v]] != u.t; q.pop())
				u = q.top();
			++pool[a[i]];
			pool[a[u.v]] = 0;
		}
		q.push({i, pool[a[i]]});
	}
	cout << ans;
	cout << endl;
	return 0;
}