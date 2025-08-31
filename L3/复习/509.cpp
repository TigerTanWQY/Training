#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{ int v, w, l; }
a[103];
int f[103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, V;
	cin >> n >> V;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].v >> a[i].w >> a[i].l;
	for(int i = 1; i <= n; ++i)
		for(int k = 0; k < a[i].l; ++k)
			for(int j = V; j >= a[i].v; --j)
				f[j] = max(f[j], f[j - a[i].v] + a[i].w);
	cout << f[V] << endl;
	return 0;
}