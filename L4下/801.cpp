#include <iostream>
using namespace std;

const int N = 1003;
bool f[N][N];
char s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	cin >> (s + 2);
	for(int j = 2; j <= m; ++j)
		f[1][j] = (s[j] == 'W');
	cin >> (s + 2);
	for(int i = 2; i <= n; ++i)
		f[i][1] = (s[i] == 'W');
	for(int i = 2; i <= n; ++i) {
		for(int j = 2; j <= m; ++j) {
			f[i][j] = !(f[i - 1][j] & f[i][j - 1]);
			if(f[i][j])
				cout << 'A';
			else
				cout << 'B';
		}
		cout << '\n';
	}
	cout.flush();
	return 0;
}