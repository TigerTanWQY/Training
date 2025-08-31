#include <iostream>
#include <unordered_map>
using namespace std;
using LL = long long;

const int N = 1e9;
unordered_map<LL, LL> fa;

LL fnd(const LL x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

void mrge(const LL x, const LL y) {
	LL fx = fnd(x), fy = fnd(y);
	if(fx == fy)
		return;
	fa[fx] = fy;
}

bool same(const LL x, const LL y)
{ return fnd(x) == fnd(y); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int _T;
	cin >> _T;
	for(int n; _T--; ) {
		cin >> n;
		bool flag = false;
		for(int i = 1, w; i <= n; ++i) {
			LL u, v;
			cin >> u >> v >> w;
			/*
			- if a == c, b == c, then a == b。
			- if a == c, b != c, then a != b。
			- if a != c, b != c, then a == b or a != b。
			- if a != c, b == c, then a != b。
			*/
			if(!fa.count(u))
				fa[u] = u;
			if(!fa.count(v))
				fa[v] = v;
			if(!fa.count(u + N))
				fa[u + N] = u + N;
			if(!fa.count(v + N))
				fa[v + N] = v + N;
			if(flag)
				continue;
			else
				if(w)
					if(same(u, v + N) || same(u + N, v))
						flag = true;
					else
						mrge(u, v);
				else
					if(same(u, v))
						flag = true;
					else {
						mrge(u, v + N);
						mrge(u + N, v);
					}
		}
		if(flag)
			cout << "NO";
		else
			cout << "YES";
		cout << '\n';
		fa.clear();
	}
	cout.flush();
	return 0;
}