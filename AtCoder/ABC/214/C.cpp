#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200003;
int s[N], t[N], f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> s[i];
	for(int i = 1; i <= n; ++i)
		cin >> t[i];
	for(int _ = 0; _ < 2; ++_)
		for(int i = 1; i <= n; ++i)
			f[i % n + 1] = min(f[i] + s[i], t[i % n + 1]);
	for(int i = 1; i <= n; ++i)
		cout << f[i] << '\n';
	return 0;
}