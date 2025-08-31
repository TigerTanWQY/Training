#include <bits/stdc++.h>
using namespace std;

struct ph {
	template<class T1, class T2>
	size_t operator()(const pair<T1, T2>& p) const
	{ return hash<T1>{}(p.first) ^ (hash<T2>{}(p.second) << 1); }
};
constexpr const int N = 103;
vector<int> G[N];
int col[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	unordered_set<pair<int, int>, ph> E;
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		if(u > v)
			swap(u, v);
		E.insert({u, v});
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(col, -1, sizeof(col));
	col[1] = 0;
	queue<int> q;
	q.push(1);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& v: G[u])
			if(!~col[v]) {
				col[v] = col[u] ^ 1;
				q.push(v);
			}
	}
	set<pair<int, int>> okE;
	for(int i = 1; i < n; ++i)
		for(int j = i + 1; j <= n; ++j)
			if(col[i] != col[j] && !E.count({i, j}))
				okE.insert({i, j});
	int m = okE.size();
	cout << (m & 1? "First": "Second") << endl;
	if(m & 1)
		for(int x, y; ; ) {
			if(okE.empty())
				break;
			auto e = *okE.cbegin();
			cout << e.first << ' ' << e.second << endl;
			okE.erase(okE.cbegin());
			cin >> x >> y;
			if(x == -1 && y == -1)
				break;
			if(x > y)
				swap(x, y);
			okE.erase({x, y});
		}
	else
		for(int x, y; ; ) {
			cin >> x >> y;
			if(x == -1 && y == -1)
				break;
			if(x > y)
				swap(x, y);
			okE.erase({x, y});
			if(okE.empty()) {
				cout << "-1 -1" << endl;
				break;
			}
			auto e = *okE.cbegin();
			cout << e.first << ' ' << e.second << endl;
			okE.erase(okE.cbegin());
		}
	return 0;
}
