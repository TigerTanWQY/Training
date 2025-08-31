#include <iostream>
using namespace std;

char a[11][11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(; t--; ) {
		for(int i = 1; i <= 8; ++i)
			cin >> a[i] + 1;
		for(int i = 2; i < 8; ++i)
			for(int j = 2; j < 8; ++j)
				if(a[i - 1][j - 1] == '#' && a[i + 1][j - 1] == '#' && a[i - 1][j + 1] == '#' && a[i + 1][j + 1] == '#' && a[i][j] == '#') {
					cout << i << ' ' << j << '\n';
					break;
				}
	}
	return 0;
}