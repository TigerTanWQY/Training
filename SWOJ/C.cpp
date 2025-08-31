#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2000003;
char b[N], c[N], d[N], s[N], tmp[N];

int main() {
	char y;
	int n, x, ans = 0;
	scanf("%d%s%s%s%d%*c%c", &n, b + 1, c + 1, d + 1, &x, &y);
	for(int i = 1; i <= n; ++i)
		if(d[i] - '0')
			s[i] = c[i];
		else if(c[i] != b[i])
			s[i] = b[i];
		else if(c[i] != y)
			s[i] = y;
		else
			switch(c[i]) {
				case 'A':
					s[i] = 'B';
					break;
				case 'B':
					s[i] = 'C';
					break;
				case 'C':
					s[i] = 'D';
					break;
				case 'D':
					s[i] = 'A';
					break;
			}
	bool flag = false;
	for(int L = 1; L <= n - x + 1; ++L) {
		for(int i = 1; i <= n; ++i)
			tmp[i] = s[i];
		for(int i = L; i < L + x; ++i)
			tmp[i] = y;
		bool f = true;
		int tot = 0;
		for(int i = 1; i <= n && f; ++i)
			if(d[i] - '0')
				if(tmp[i] == c[i]) {
					if(tmp[i] == b[i])
						++tot;
				}
				else
					f = false;
			else
				if(tmp[i] != c[i]) {
					if(tmp[i] == b[i])
						++tot;
				}
				else
					f = false;
		if(f) {
			flag = true;
			ans = max(ans, tot);
		}
	}
	if(flag)
		printf("%d", ans);
	else
		printf("-1");
	return 0;
}
