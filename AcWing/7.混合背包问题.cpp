#include <bits/stdc++.h>
using namespace std;

int f[1003];

int main () {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, V;
	cin >> n >> V;
	for(int v, w, s; n--; ) {
		cin >> v >> w >> s;
		if(!s)
			for(int j = v; j <= V; ++j)
				f[j] = max(f[j], f[j-v] + w);
		else {
			s = abs (s);
			for(int k = 1; k <= s; k <<= 1) {
				for(int j = V; j >= v * k; --j)
					f[j] = max(f[j], f[j-v*k] + w*k);
				s -= k;
			}
			if(s)
				for(int j = V; j >= v * s; --j)
					f[j] = max(f[j], f[j-v*s] + w*s);
		}
	}
	cout << f[V] << endl;
	return 0;
}
