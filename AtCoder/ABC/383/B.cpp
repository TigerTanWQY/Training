#include <bits/stdc++.h>
using namespace std;

char s[13][13];

int main() {
	int n, m, d;
	scanf("%d%d%d", &n, &m, &d);
	for(int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	auto dis = [](int x1, int y1, int x2, int y2)
	{ return abs(x1 - x2) + abs(y1 - y2); };
	int ans = 0;
	for(int x1 = 1; x1 <= n; ++x1)
		for(int y1 = 1; y1 <= m; ++y1)
			for(int x2 = 1; x2 <= n; ++x2)
				for(int y2 = 1; y2 <= m; ++y2) {
					if(s[x1][y1] != '.' || s[x2][y2] != '.')
						continue;
					int cnt = 0;
					for(int i = 1; i <= n; ++i)
						for(int j = 1; j <= m; ++j)
							if(s[i][j] == '.' && (dis(x1, y1, i, j) <= d || dis(x2, y2, i, j) <= d))
								++cnt;
					ans = max(ans, cnt);
				}
	printf("%d\n", ans);
	return 0;
}
