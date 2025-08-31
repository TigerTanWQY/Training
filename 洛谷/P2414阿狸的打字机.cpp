#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int N = 100003;
char s[N], t[N];
int nxt[N], f[N], n, m;

void kmp() {
	nxt[1] = 0;
	for(int i = 2, j = 0; i <= n; ++i) {
		while(j && t[i] != t[j + 1])
			j = nxt[j];
		if(t[i] == t[j + 1])
			++j;
		nxt[i] = j;
	}
	for(int i = 1, j = 0; i <= n; ++i) {
		while(j == m || (j && s[i] != t[j + 1]))
			j = nxt[j];
		if(s[i] == t[j + 1])
			++j;
		f[i] = j;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	vector<string> a;
	string tr;
	for(const auto& ch: str)
		if('a' <= ch && ch <= 'z')
			tr += ch;
		else if(ch == 'B')
			tr.pop_back();
		else
			a.push_back(tr);
	int _q;
	cin >> _q;
	for(int x, y; _q--; ) {
		cin >> x >> y;
		m = a[x - 1].size();
		n = a[y - 1].size();
		memcpy(s + 1, a[y - 1].c_str(), n);
		memcpy(t + 1, a[x - 1].c_str(), m);
		kmp();
		int ans = 0;
		for(int i = 1; i <= n; ++i)
			if(f[i] == m)
				++ans;
		cout << ans << '\n';
	}
	cout.flush();
	return 0;
}