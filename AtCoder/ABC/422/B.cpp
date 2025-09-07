#include <bits/stdc++.h>
using namespace std;

constexpr const int dxy[][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
char s[23][23];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> s[i][j];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(s[i][j] == '#') {
				int cnt = 0;
				for(int k = 0; k < 4; ++k) {
					int tx = i + dxy[k][0], ty = j + dxy[k][1];
					if(1 <= tx && tx <= n && 1 <= ty && ty <= m && s[tx][ty] == '#')
						++cnt;
				}
				if(cnt != 2 && cnt != 4) {
					cout << "No" << endl;
					return 0;
				}
			}
	cout << "Yes" << endl;
	return 0;
}
