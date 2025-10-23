#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int t[]={0, 1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};
bool mp[153][13];
int f[2][59053], nxt[13], pre[13], m;

int atoi(int* a) {
	int res = 0;
	for(int i = 1; i <= m; ++i)
		res += a[i] * t[i];
	return res;
}
void itoa(int x, int* a) {
	for(int i = 1; i <= m; ++i) {
		a[i] = x % 3;
		x /= 3;
	}
}

void dfs(int i, int j, int px, int st) {
	f[i&1][st] = max(f[i&1][st], px);
	if(j >= m)
		return;
	if(j < m - 1 && nxt[j] == 0 && nxt[j+1] == 0 && nxt[j+2] == 0) {
		nxt[j] = nxt[j+1] = nxt[j+2] = 2;
		dfs(i, j+3, px+1, atoi(nxt));
		nxt[j] = nxt[j+1] = nxt[j+2] = 0;
	}
	if(pre[j] == 0 && pre[j+1] == 0 && nxt[j] == 0 && nxt[j+1] == 0) {
		nxt[j] = nxt[j+1] = 2;
		dfs(i, j+2, px+1, atoi(nxt));
		nxt[j] = nxt[j+1] = 0;
	}
	dfs(i, j+1, px, st);
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n, k; _T--; cout.put('\n')) {
		cin >> n >> m >> k;
		memset(mp, 0, sizeof mp);
		for(int x, y; k--; ) {
			cin >> x >> y;
			mp[x][y] = true;
		}
		for(int i = 0; i <= t[m+1]; ++i)
			f[1][i] = -1;
		for(int i = 1; i <= m; ++i)
			pre[i] = mp[1][i] + 1;
		int st = atoi(pre);
		f[1][st] = 0;
		for(int i = 2; i <= n; ++i) {
			for(int j = 0; j <= t[m+1]; ++j)
				f[i&1][j] = -1;
			for(int j = 0; j <= t[m+1]; ++j) {
				if(f[(i+1)&1][j] == -1)
					continue;
				itoa(j, pre);
				for(int l = 1; l <= m; ++l)
					if(mp[i][l])
						nxt[l] = 2;
					else if(pre[l] == 2)
						nxt[l] = 1;
					else
						nxt[l] = 0;
				st = atoi(nxt);
				dfs(i, 1, f[(i+1)&1][j], st);
			}
		}
		cout << *max_element(f[n&1], f[n&1] + t[m+1]);
	}
	cout.flush(); return 0;
}
