#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using LL = long long;

const int N = 1003;
struct Ball
{ int x, y, z; }
a[N];
int fa[N], sz[N];

void init(const int& n) {
	for(int i = 1; i <= n; ++i) {
		fa[i] = i;
		sz[i] = 1;
	}
}

int fnd(const int& x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

void mrge(const int& x, const int& y) {
	int fx = fnd(x), fy = fnd(y);
	if(fx != fy) {
		if(sz[fx] > sz[fy])
			swap(sz[fx], sz[fy]);
		fa[fx] = fy;
		sz[fx] += sz[fy];
	}
}

bool same(const int& x, const int& y)
{ return fnd(x) == fnd(y); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int _T;
	cin >> _T;
	for(int n, h, r; _T--; ) {
		cin >> n >> h >> r;
		init(n);
		vector<LL> f[2];
		for(int i = 1; i <= n; ++i) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].z + r >= h)
				f[0].push_back(i);
			if(a[i].z - r <= 0)
				f[1].push_back(i);
			for(int j = 1; j <= i; ++j)
				if(1LL * (a[i].x - a[j].x) * (a[i].x - a[j].x) + 1LL * (a[i].y - a[j].y) * (a[i].y - a[j].y) + 1LL * (a[i].z - a[j].z) * (a[i].z - a[j].z) <= 4LL * r * r)
					mrge(i, j);
		}
		bool flag = false;
		for(const auto& x: f[0]) {
			for(const auto& y: f[1])
				if(same(x, y)) {
					flag = true;
					break;
				}
			if(flag)
				break;
		}
		if(flag)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}