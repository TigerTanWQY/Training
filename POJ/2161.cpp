#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int N = 10003;
vector<int> G[N];
stack<int> stk;
char str[N];
int f[N], pos[N];

int deal(const int u) {
	int len = G[u].size(), maxn = f[G[u][0]];
	for(int i = 0; i < len; ++i)
		maxn = max(maxn, f[G[u][i]] + i);
	int res = maxn;
	for(int i = 1; i < len; ++i) {
		maxn = max(maxn - 1, f[G[u][i - 1]] + len - 1);
		if(res > maxn) {
			pos[u] = i;
			res = maxn;
		}
	}
	return res;
}

void dfs(const int u) {
	int len = G[u].size();
	if(len == 0) {
		f[u] = 1;
		return;
	}
	for(int i = 0; i < G[u].size(); ++i)
		dfs(G[u][i]);
	f[u] = deal(u);
}

void print(const int u) {
	int len = G[u].size();
	if(len == 0) {
		cout.put('a');
		return;
	}
	for(int i = 0; i < len; ++i)
		print(G[u][(pos[u] + i) % len]);
	cout << G[u].size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> (str + 1);
	int n = strlen(str + 1);
	for(int i = 1; i <= n; ++i) {
		if(str[i] != 'a') {
			stack<int> s;
			for(int _ = 0; _ < str[i] - '0'; ++_) {
				s.push(stk.top());
				stk.pop();
			}
			for(; !s.empty(); s.pop())
				G[i].push_back(s.top());
		}
		stk.push(i);
	}
	dfs(n);
	cout << f[n] << '\n';
	print(n);
	cout << '\n';
	cout.flush();
	return 0;
}