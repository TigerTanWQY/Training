#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 103;
vector<int> G[N], p;
int d[N], n;

bool topsort() {
	queue<int> q;
	for(int u = 1; u <= n; ++u)
		if(!d[u]) {
			q.push(u);
			p.push_back(u);
		}
	while(!q.empty()) {
		int t = q.front();
		q.pop();
		for(const auto &x: G[t])
			if(--d[x] == 0) {
				q.push(x);
				p.push_back(x);
			}
	}
	return p.size() == n;
}

int main() {
	cin >> n;
	for(int u = 1, x; u <= n; ++u)
		while(cin >> x && x) {
			++d[x];
			G[u].push_back(x);
		}
	topsort();
	for(const auto& x: p)
		cout << x << ' ';
	return 0;
}