#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

constexpr const int M = 1e6 + 3, N = 2e5 + 3;
vector<int> G[M];
string s[N];
int trie[M][26], dis[M], t[M], a[N], c[M], idx = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n >> s[n + 1];
	s[0] = string(M, 'z' + 1);
	for(int i = 1; i <= n + 1; ++i) {
		if(i <= n)
			cin >> s[i];
		int now = 0;
		for(const auto& ch: s[i]) {
			const int x = ch - 'a';
			if(!trie[now][x])
				trie[now][x] = ++idx;
			G[now].push_back(trie[now][x]);
			if(i <= n && s[i] < s[t[now]])
				t[now] = i;
			now = trie[now][x];
		}
		a[i] = now; c[now] = i;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
		G[a[i]].push_back(a[i % n + 1]);
	for(int i = 1; i <= n + 1; ++i) {
		int now = 0;
		for(const auto& ch: s[i]) {
			const int x = ch - 'a';
			if(!trie[now][x])
				trie[now][x] = ++idx;
			if(!c[now])
				G[now].push_back(a[t[now]]);
			now = trie[now][x];
		}
	}
	dis[0] = 1;
	queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& v: G[u])
			if(!dis[v]) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
	}
	cout << dis[a[n + 1]] - 1 << endl;
	return 0;
}