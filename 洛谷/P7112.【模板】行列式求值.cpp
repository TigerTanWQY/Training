#include <bits/stdc++.h>
using namespace std;

int a[603][603];
// 13510833613@139.gd
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, _p;
	cin >> n >> _p;
	const int p = _p;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			a[i][j] %= p;
		}
	bool flg = false;
	int R = 1;
	for(int i = 1; i <= n; ++i) {
		int id = i;
		for(int j = i; j <= n; ++j)
			if(a[j][i]) {
				id = j;
				break;
			}
		if(a[id][i] == 0) {
			cout.put('0') << endl;
			return 0;
		}
		for(int j = id + 1; j <= n; ++j)
			if(a[j][i] && a[j][i] < a[id][i])
				id = j;
		if(i != id) {
			swap(a[id], a[i]);
			flg ^= true;
		}
		for(int j = i + 1; j <= n; ++j) {
			if(a[j][i] > a[i][i]) {
				swap(a[j], a[i]);
				flg ^= true;
			}
			while(a[j][i]) {
				int L = a[i][i] / a[j][i];
				for(int k = i; k <= n; ++k)
					a[i][k] = (a[i][k] + 1LL * (p - L) * a[j][k]) % p;
				swap(a[j], a[i]);
				flg ^= true;
			}
		}
		R = 1LL * R * a[i][i] % p;
	}
	cout << (flg? (p - R) % p: R) << endl;
	return 0;
}
