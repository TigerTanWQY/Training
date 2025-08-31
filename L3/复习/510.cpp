#include <iostream>
#include <vector>
using namespace std;

struct Node
{ int v, w, l; }
a[2003];
int f[2003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, V;
	cin >> n >> V;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].v >> a[i].w >> a[i].l;
	for(int i = 1; i <= n; ++i) {
		vector<int> c;
		for(int k = 1; a[i].l; k <<= 1)
			if(a[i].l >= k) {
				c.push_back(k);
				a[i].l -= k;
			} else
				break;
		if(a[i].l)
			c.push_back(a[i].l);
		for(const auto& k: c)
			for(int j = V; j >= a[i].v * k; --j)
				f[j] = max(f[j], f[j - a[i].v * k] + a[i].w * k);
	}
	cout << f[V] << endl;
	return 0;
}