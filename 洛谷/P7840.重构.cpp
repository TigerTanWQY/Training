#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

struct Edge {
	int d, v;
	friend bool operator<(const Edge& A, const Edge& B)
	{ return (2 * A.d + 1) * A.v > (2 * B.d + 1) * B.v; }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	long long ans = 0;
	__gnu_pbds::priority_queue<Edge> q;
	for(int _ = 0, x; _ < n; ++_) {
		cin >> x;
		ans += x;
		q.push({1, x});
	}
	for(int _ = n - 2; _--; ) {
		auto [d, v] = q.top();
		q.pop();
		ans += (2 * d + 1) * v;
		if(d < n - 1)
			q.push({d + 1, v});
	}
	cout << ans << endl;
	return 0;
}
