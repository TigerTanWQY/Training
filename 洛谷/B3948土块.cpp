#include <iostream>
using namespace std;

const int N = 1003;
const int M = 4;
int a[M][N], b[M][N], c[M];

int check(const int& x, const int& y) {
	int tot = 0;
	for(int i = 0; i < M; ++i)
		tot += b[i][y];
	if(!tot)
		return 0;
	for(int i = 0; i < M; ++i)
		c[i] = a[i][x] + b[i][y];
	for(int i = 0; i < M; ++i)
		if(!~c[i])
			return 0;
	for(int i = 0; i < M; ++i)
		if(c[i])
			return 3;
	return 6;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < M; ++j)
			cin >> a[j][i];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < M; ++j) {
			cin >> b[j][i];
			b[j][i] *= -1;
		}
	for(int i = 0, ans = 0; i < n; cout << ' ', ++i, ans = 0) {
		for(int j = 0; j < n; ++j)
			ans += check((i + j) % n, j);
		cout << ans;
	}
	return 0;
}