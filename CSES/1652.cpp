#include <iostream>
using namespace std;

constexpr const int N = 1003;
char a[N][N];
int s[N][N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, _q;
	cin >> n >> _q;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (a[i][j] == '*');
		}
	for(int x1, y1, x2, y2; _q--; cout.put('\n')) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
	}
	cout.flush();
	return 0;
}
