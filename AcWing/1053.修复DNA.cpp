#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1003;
int test_case = 1;
int n, m;
char str[N];
int q[N];
int tr[N][4], fail[N], flag[N], idx;
int f[N][N];

int get(char x) {
	if(x == 'A')
		return 0;
	else if(x == 'G')
		return 1;
	else if(x == 'C')
		return 2;
	else
		return 3;
}

void ist() {
	int u = 0, len = strlen(str + 1);
	for(int i = 1; i <= len; i++) {
		int k = get(str[i]);
		if(!tr[u][k]) tr[u][k] = ++idx;
		u = tr[u][k];
	}
	flag[u] = true;
}
void build_ACAM() {
	int hh = 0, tt = -1;
	for(int i = 0; i < 4; i++) {
		if(tr[0][i]) q[++tt] = tr[0][i];
	}
	while(hh <= tt) {
		int u = q[hh++];
		for(int i = 0; i < 4; i++) {
			int p = tr[u][i];
			if(!p) tr[u][i] = tr[fail[u]][i];
			else {
				fail[p] = tr[fail[u]][i];
				q[++tt] = p;
				flag[p] |= flag[fail[p]];
			}
		}
	}
}
int main() {
	while(cin >> n, n) {
		memset(flag, false, sizeof(flag));
		memset(tr, 0, sizeof(tr));
		memset(fail, 0, sizeof(fail));
		idx = 0;
		for(int i = 1; i <= n; i++) {
			cin >> str;
			for(int j = strlen(str)+1; j; --j)
				swap(str[j], str[j-1]);
			ist();
		}
		cin >> str;
		for(int j = strlen(str)+1; j; --j)
			swap(str[j], str[j-1]);
		m = strlen(str + 1);
		build_ACAM();
		memset(f, 0x3f, sizeof(f));
		f[0][0] = 0;
		for(int i = 0; i < m; i++)
			for(int j = 0; j <= idx; j++)
				for(int k = 0; k < 4; k++) {
					int t = get(str[i + 1]) != k, p = tr[j][k];
					if(!flag[p]) f[i + 1][p] = min(f[i + 1][p], f[i][j] + t);
				}
		int ans = 0x3f3f3f3f;
		for(int i = 0; i <= idx; i++) ans = min(ans, f[m][i]);
		if(ans == 0x3f3f3f3f) ans = -1;
		cout << "Case " << test_case++ << ": " << ans << endl;
	}
	return 0;
}
