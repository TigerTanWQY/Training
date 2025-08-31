#include <iostream>
#include <algorithm>
using namespace std;

int f[1003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, V;
	cin >> n >> V;
	for(int i = 1, tp, v, w, l; i <= n; ++i) {
		cin >> tp >> v >> w;
		if(tp == 1)
			for(int j = V; j >= v; --j)
				f[j] = max(f[j], f[j - v] + w);
		else if(tp == 2)
			for(int j = v; j <= V; ++j)
				f[j] = max(f[j], f[j - v] + w);
		else {
			cin >> l;
			while(l--)
				for(int j = V; j >= v; --j)
					f[j] = max(f[j], f[j - v] + w);
		}
	}
	cout << f[V] << endl;
	return 0;
}