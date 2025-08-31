#include <iostream>
using namespace std;

int a[200003], f[200003], n;
long long g[200003];

bool check() {
	bool res = true;
	for(int i = 1; res && i <= n; ++i)
		if(!g[i])
			res = false;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(long long t = 1; !check(); ++t) {
		++f[0];
		for(int i = 1; i <= n; ++i)
			if(f[i - 1] > f[i] && f[i - 1] > a[i]) {
				--f[i - 1];
				++f[i];
			}
		for(int i = 1; i <= n; ++i)
			if(f[i] > 0 && !g[i])
				g[i] = t;
	}
	for(int i = 1; i <= n; ++i)
		cout << g[i] << ' ';
	return 0;
}