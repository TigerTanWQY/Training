#include <iostream>
#include <algorithm>
using namespace std;

int v[103], w[103], f[103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, V;
	cin >> n >> V;
	for(int s; n--; ) {
		cin >> s;
		for(int i = 1; i <= s; ++i)
			cin >> v[i] >> w[i];
		for(int j = V; j >= 0; --j)
			for(int i = 1; i <= s; ++i)
				if(j >= v[i])
					f[j] = max(f[j], f[j - v[i]] + w[i]);
	}
	cout << f[V];
	return 0;
}