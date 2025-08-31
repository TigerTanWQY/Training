#include <iostream>
#include <bitset>
using namespace std;

struct Node
{ int u, v, w; }
p[50'003];
bitset<2'003> c[2'003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i)
		cin >> p[i].u >> p[i].v >> p[i].w;
	int ans = 0;
	for(int a = 1; a <= n; ++a) {
		for(int i = 1; i <= m; ++i)
			if(p[i].u == a)
				c[p[i].v][p[i].w] = true;
		for(int i = 1; i <= m; ++i)
			if(c[p[i].u][p[i].v] && c[p[i].u][p[i].w] && c[p[i].v][p[i].w])
				++ans;
		for(int i = 1; i <= m; ++i)
			if(p[i].u == a)
				c[p[i].v][p[i].w] = false;
	}
	cout << ans;
	return 0;
}