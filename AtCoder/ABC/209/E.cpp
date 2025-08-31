#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>

constexpr const int M = 2e5 + 3, N = M * 8, K = 128;
__gnu_pbds::gp_hash_table<int, int> idx;
vector<int> G[N];
string s[M];
int d[N], f[N], cnt = 0;

inline int hsh(const string& t)
{ return (t[0] - 'A') * K * K + (t[1] - 'A') * K + (t[2] - 'A'); }

void bfs() {
	memset(f, 0, sizeof(f));
	queue<int> q;
	for(int i = 1; i <= cnt; ++i)
		if(!d[i]) {
			f[i] = 1;
			q.push(i);
		}
	while(!q.empty()) {
		const int u = q.front();
		q.pop();
		for(const auto& v: G[u]) {
			--d[v];
			if(f[u] == 1 && f[v] == 0) {
				f[v] = -1;
				q.push(v);
			}
			if(f[v] == 0 && !d[v] && f[u] == -1) {
				f[v] = 1;
				q.push(v);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> s[i];
		const int u = hsh(s[i].substr(0, 3)), v = hsh(s[i].substr(s[i].size() - 3, 3));
		if(!idx[u])
			idx[u] = ++cnt;
		if(!idx[v])
			idx[v] = ++cnt;
		G[idx[v]].push_back(idx[u]);
		++d[idx[u]];
	}
	bfs();
	for(int i = 1; i <= n; ++i) {
		const int u = hsh(s[i].substr(s[i].size() - 3, 3));
		if(f[idx[u]] == 1)
			cout << "Takahashi";
		else if(f[idx[u]] == -1)
			cout << "Aoki";
		else if(f[idx[u]] == 0)
			cout << "Draw";
		cout.put('\n');
	}
	cout.flush();
	return 0;
}
