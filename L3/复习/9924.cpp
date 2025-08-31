#include <iostream>
#include <bitset>
#include <stack>
using namespace std;

constexpr const int N = 2e5 + 3;
stack<int> stk;
bitset<N> flag, c;
char s[1000003];
int a[N], T[N][3], n, idx;

int dfs(const int u, const int t) {
	a[u] ^= t;
	if(u <= n)
		return a[u];
	const int x = dfs(T[u][0], t ^ flag[T[u][0]]), y = dfs(T[u][1], t ^ flag[T[u][1]]);
	if(a[u] == 2) {
		if(x == 0)
			c[T[u][1]] = true;
		if(y == 0)
			c[T[u][0]] = true;
		return x & y;
	} else {
		if(x == 1)
			c[T[u][1]] = true;
		if(y == 1)
			c[T[u][0]] = true;
		return x | y;
	}
}

void dfs2(const int u) {
	if(u <= n)
		return;
	c[T[u][0]] = c[T[u][0]] | c[u];
	c[T[u][1]] = c[T[u][1]] | c[u];
	dfs2(T[u][0]);
	dfs2(T[u][1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin.getline(s, 1e6 + 3);
	cin >> n;
	idx = n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 0; s[i]; i += 2)
		if(s[i] == 'x') {
			int x = 0;
			++i;
			while(s[i] != ' ')
				x = x * 10 + s[i++] - '0';
			--i;
			stk.push(x);
		} else if(s[i] == '&' || s[i] == '|') {
			int x = stk.top(); stk.pop();
			int y = stk.top(); stk.pop();
			stk.push(++idx);
			if(s[i] == '&')
				a[idx] = 2;
			else
				a[idx] = 3;
			T[idx][0] = x;
			T[idx][1] = y;
		} else if(s[i] == '!')
			flag[stk.top()] = flag[stk.top()] ^ true;
	const int ans = dfs(idx, flag[idx]);
	dfs2(idx);
	cin >> q;
	for(int x; q--; cout.put('\n')) {
		cin >> x;
		cout << (c[x]? ans: !ans);
	}
	cout.flush();
	return 0;
}