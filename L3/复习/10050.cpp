#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

constexpr const int N = 2e5 + 3;
unordered_map<int, int> idx;
vector<int> G[N * 2];
pair<int, int> e[N];
int dis[N * 2];

void bfs(const int rt) {
	memset(dis, 0, sizeof(dis));
	dis[rt] = 1;
	queue<int> q;
	q.push(rt);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& v: G[u])
			if(!dis[v]) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> m;
	vector<int> a;
	for(int i = 0; i < m; ++i) {
		cin >> e[i].first >> e[i].second;
		a.push_back(e[i].first);
		a.push_back(e[i].second);
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.cend());
	int n = 0;
	for(const auto& x: a)
		idx[x] = ++n;
	for(int i = 0; i < m; ++i) {
		G[idx[e[i].first]].push_back(idx[e[i].second]);
		G[idx[e[i].second]].push_back(idx[e[i].first]);
	}
	if(!idx.count(1)) {
		cout.put('1'); cout << endl;
		return 0;
	}
	bfs(idx[1]);
	for(auto cit = a.crbegin(); cit != a.crend(); ++cit)
		if(dis[idx[*cit]] - 1 > 0) {
			cout << *cit;
			break;
		}
	cout << endl;
	return 0;
}