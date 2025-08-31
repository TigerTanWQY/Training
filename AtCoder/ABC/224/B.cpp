#include <iostream>
using namespace std;

const int N = 53;
int a[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> a[i][j];
	for(int i1 = 1; i1 < n; ++i1)
		for(int j1 = 1; j1 < m; ++j1)
			for(int i2 = i1 + 1; i2 <= n; ++i2)
				for(int j2 = j1 + 1; j2 <= m; ++j2)
					if(a[i1][j1] + a[i2][j2] > a[i2][j1] + a[i1][j2]) {
						cout << "No";
						return 0;
					}
	cout << "Yes";
	return 0;
}