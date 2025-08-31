#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

constexpr const int N = 200'003, K = 20 + 1;
char s[N][K];
int f[1 << K], len;

void reverse(char* const s, const int l) {
	for(int i = 1, j = l; i < j; ++i, --j)
		swap(s[i], s[j]);
}

int getMin(char* const s, const int l) {
	int now = 1;
	for(int i = 1; i <= l; ++i) {
		now <<= 1;
		now |= (s[i] == '0');
	}
	return f[now];
}

int query(char* const s) {
	int res = 0x3f3f3f3f;
	for (int i = 0; i <= len; ++i) {
		reverse(s, i);
		res = min(res, getMin(s, i) + len - i);
		reverse(s, i);
	}
	return res;
}

int Solve(const char* const s, const char* const t) {
	int res = 0;
	for(int i = len; i; --i) {
		bool flag = true;
		for(int j = len; flag && j > len - i; --j)
			if(s[j] != t[i - (len - j)])
				flag = false;
		if(flag) {
			res = i;
			break;
		}
	}
	return len - res;
}

void Insert(const char* const s, const int val) {
	int now = 1;
	for(int i = 1; i <= len; ++i) {
		f[now] = min(f[now], val);
		now <<= 1;
		now |= (s[i] == '0');
	}
	f[now] = min(f[now], val);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> (s[i] + 1);
	len = strlen(s[1] + 1);
	int tag = len;
	memset(f, 0x3f, sizeof(f));
	f[1] = 0;
	for(int i = 2; i <= n; ++i) {
		int res = query(s[i]);
		res += tag;
		tag += Solve(s[i - 1], s[i]);
		reverse(s[i - 1], len);
		Insert(s[i - 1], res - tag);
	}
	cout << f[1] + tag;
	cout.flush();
	return 0;
}