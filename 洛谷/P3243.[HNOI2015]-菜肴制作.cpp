#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n, m; _T--; cout.put('\n')) {
		cin >> n >> m;
		vector<vector<int>> G(n+1);
		vector<int> in(n+1, 0), ans;
		for(int u, v; m--; ) {
			cin >> u >> v;
			++in[u];
			G[v].push_back(u);
		}
		__gnu_pbds::priority_queue<int> q;
		for(int i = 1; i <= n; ++i)
			if(!in[i])
				q.push(i);
		while(!q.empty()) {
			int u = q.top();
			q.pop();
			for(const auto& v: G[u]) {
				--in[v];
				if(!in[v])
					q.push(v);
			}
			ans.push_back(u);
		}
		if(ans.size() < n)
			cout << "Impossible!";
		else
			for(auto it = ans.crbegin(); it != ans.crend(); ++it)
				cout << (*it) << ' ';
	}
	cout.flush(); return 0;
}
