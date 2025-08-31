#include <iostream>
using namespace std;

constexpr const int d[8][3]{{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
char s[103][103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> (s[i] + 1);
	for(int i = 1; i <= n; cout.put('\n'), ++i)
		for(int j = 1; j <= m; ++j)
			if(s[i][j] == '*')
				cout.put('*');
			else {
				int ans = 0;
				for(int k = 0; k < 8; ++k) {
					int tx = i + d[k][0], ty = j + d[k][1];
					if(1 <= tx && tx <= n && 1 <= ty && ty <= m && s[tx][ty] == '*')
						++ans;
				}
				cout << ans;
			}
	cout.flush();
	return 0;
}