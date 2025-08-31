#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e6 + 3;
bitset<N> vis;
char st[N];
int len[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(; _T--; cout.put('\n')) {
		int cnt = 0, mx = 0, id = 0;
		vis.reset();
		memset(len, 0, sizeof(len));
		char ch = cin.get();
		st[0] = '~'; st[cnt = 1] = '#';
		for(; 'a' > ch || ch > 'z'; ch = cin.get());
		for(; 'a' <= ch && ch <= 'z'; ch = cin.get())
		{ st[++cnt] = ch; st[++cnt] = '#'; }
		st[cnt + 1] = '%';
		for(int i = 1; i <= cnt; ++i) {
			if(i <= mx)
				len[i] = min(mx - i, len[id * 2 - i]);
			for(; st[i + len[i]] == st[i - len[i]]; ++len[i]);
			if(i + len[i] > mx)
			{ mx = i + len[i] - 1; id = i; }
		}
		for(int i = cnt; i; --i)
			if(i + len[i] - 1 == cnt)
				vis[i] = true;
			else if(vis[i + len[i] - 2] && i == len[i])
				vis[i] = true;
		for(int i = 1; i <= cnt; ++i)
			if('a' <= st[i] && st[i] <= 'z' && vis[i])
				cout << i / 2 << ' ';
	}
	cout.flush(); return 0;
}
