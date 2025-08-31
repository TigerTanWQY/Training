#include <iostream>
#include <unordered_set>
using namespace std;

const int N = 1003;
int fa[N], enm[N];

void init(const int& n) {
	for(int i = 1; i <= n; ++i)
		fa[i] = i;
}

int fnd(const int& x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

void mrge(const int& x, const int& y) {
	int fx = fnd(x), fy = fnd(y);
	if(fx != fy)
		fa[fx] = fy;
}

bool same(const int& x, const int& y)
{ return fnd(x) == fnd(y); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	init(2 * n);
	for(char op; m--; ) {
		int p, q;
		cin >> op >> p >> q;
		if(op == 'F')
			mrge(p, q);
		else {
			if(enm[p] == 0)
				enm[p] = fnd(q);
			else
				mrge(q, enm[p]);
			if(enm[q] == 0)
				enm[q] = fnd(p);
			else
				mrge(p, enm[q]);
		}
	}
	unordered_set<int> s;
	for(int i = 1; i <= n; ++i)
		s.insert(fnd(i));
	cout << s.size();
	return 0;
}