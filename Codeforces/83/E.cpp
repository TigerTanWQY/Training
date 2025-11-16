#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5+3;
char s[N][23];
int f[(1<<21)+3], len;

void reverse(char* const s, const int l) {
	for(int i = 1, j = l; i < j; ++i, --j)
		swap(s[i], s[j]);
}

int Min(char* const s, const int l) {
	int nw = 1;
	for(int i = 1; i <= l; ++i) {
		nw <<= 1;
		nw |= (s[i] == '0');
	}
	return f[nw];
}

int qry(char* const s) {
	int res = 1e9;
	for(int i = 0; i <= len; ++i) {
		reverse(s, i);
		res = min(res, Min(s, i) + len - i);
		reverse(s, i);
	}
	return res;
}

int solve(const char* const s, const char* const t) {
	int res = 0;
	for(int i = len; i; --i) {
		bool flg = true;
		for(int j = len; flg && j > len - i; --j)
			if(s[j] != t[i - (len - j)])
				flg = false;
		if(flg) {
			res = i;
			break;
		}
	}
	return len - res;
}

void ist(const char* const s, const int w) {
	int nw = 1;
	for(int i = 1; i <= len; ++i) {
		f[nw] = min(f[nw], w);
		nw <<= 1;
		nw |= (s[i] == '0');
	}
	f[nw] = min(f[nw], w);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> s[i];
		for(int j = strlen(s[i]); j; --j)
			swap(s[i][j], s[i][j-1]);
	}
	len = strlen(s[1] + 1);
	int tag = len;
	memset(f, 0x3f, sizeof(f));
	f[1] = 0;
	for(int i = 2; i <= n; ++i) {
		int res = qry(s[i]);
		res += tag;
		tag += solve(s[i - 1], s[i]);
		reverse(s[i - 1], len);
		ist(s[i - 1], res - tag);
	}
	cout << f[1] + tag << endl;
	return 0;
}
