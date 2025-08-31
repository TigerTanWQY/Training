#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

constexpr const int N = 100'003;
vector<int> G[N];
int dis[N], fa[2][N];

int read() {
	int res = 0;
	bool neg = false;
	char ch = cin.get();
	if(ch == '-')
		neg = true;
	for(; ch != EOF && ('0' > ch || ch > '9'); ch = cin.get());
	for(; '0' <= ch && ch <= '9'; ch = cin.get())
		res = res * 10 + ch - '0';
	if(neg)
		res *= -1;
	if(ch == EOF)
		res = EOF;
	return res;
}

void bfs(const int rt, const int k) {
	memset(fa[k], 0, sizeof(fa[k]));
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
				fa[k][v] = u;
				q.push(v);
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = read(), _q = read();
	for(int _ = 1, u, v; _ < n; ++_) {
		u = read(); v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int u1, v1, u2, v2; _q--; ) {
		u1 = read(); v1 = read(); u2 = read(); v2 = read();
		bfs(u1, 0);
		bfs(u2, 1);
		unordered_set<int> st;
		for(int i = v1; i != u1; i = fa[0][i])
			st.insert(i);
		st.insert(u1);
		bool flag = false;
		for(int i = v2; !flag && i != u2; i = fa[1][i])
			if(st.count(i))
				flag = true;
		if(!flag && st.count(u2))
			flag = true;
		if(flag)
			cout.put('Y');
		else
			cout.put('N');
		cout.put('\n');
	}
	cout.flush();
	return 0;
}