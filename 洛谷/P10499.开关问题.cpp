#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 33;
bool a[N][N], b[N];
int n;

void gauss() {
	int l = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = l; j <= n; ++j)
			if(a[j][i]) {
				for(int k = i; k <= n; ++k)
					swap(a[l][k], a[j][k]);
				swap(b[l], b[j]);
				break;
			}
		if(!a[l][i])
			continue;
		for(int j = 1; j <= n; ++j)
			if(j != l && a[j][i]) {
				for(int k = i; k <= n; ++k)
					a[j][k] ^= a[l][k];
				b[j] ^= b[l];
			}
		++l;
	}
	for(int i = l; i <= n; ++i)
		if(b[i]) {
			cout << "Oh,it's impossible~!!";
			return;
		}
	cout << (1 << n - l + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	while(_T--) {
		cin >> n;
		for(int i = 1; i <= n; ++i)
			cin >> b[i];
		for(int i = 1, x; i <= n; ++i) {
			cin >> x;
			b[i] ^= x;
			a[i][i] = 1;
		}
		for(int u, v; cin >> u >> v && (u || v); )
			a[v][u] = 1;
		gauss();
		cout << '\n';
		memset(a, 0, sizeof(int) * (n + 1) * (n + 1));
	}
	cout.flush();
	return 0;
}