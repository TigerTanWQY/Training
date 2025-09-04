#include <bits/stdc++.h>
using namespace std;
using U = unsigned;

constexpr const int N = 1024;
namespace {
	constexpr const U P = 19260817, Q = 23333333, R = 20200214;
	U sd;
	void flush()
	{ sd = ((sd * P) ^ (sd << 13) ^ (sd >> 7)) + R; }
	U h(U x, U s)
	{ return ((x ^ s) * Q + s + (x >> 3)) % P; }
	U h(U x)
	{ return ((x ^ sd) * Q + sd + (x >> 3)) % P; }
}
#define M (L + R >> 1)
namespace encode {
	void print(int x, int L) {
		for(int i = L - 1; ~i; --i)
			cout.put('0' + (x >> i & 1));
	}
	void print_cnt(int x, int bas) {
		int L = bas;
		for(; (1 << L) <= x; ++L)
			cout.put('1');
		cout.put('0');
		print(x, L > bas? L - 1: L);
	}
	U k[N], v[N], H[N], ans[N];
	void solve(int L, int R) {
		if(R - L == 8) {
			int cnt = 0;
			for(; ; flush(), ++cnt) {
				int s = 0;
				for(int i = L; i < R; ++i) {
					H[i] = h(k[i]) & 7;
					s |= 1 << H[i];
				}
				if(s == 255) {
					for(int i = L; i < R; ++i)
						ans[L + H[i]] = v[i];
					break;
				}
			}
			print_cnt(cnt, 9);
			return;
		}
		int cnt = 0;
		for(; ; flush(), ++cnt) {
			int one = 0;
			for(int i = L; i < R; ++i)
				one += (H[i] = h(k[i]) & 1);
			if(one * 2 == R - L) {
				for(int i = L, j = R - 1; i < j; ++i, --j) {
					for(; i < j && !H[i]; ++i);
					for(; i < j && H[j]; --j);
					if(i < j)
					{ swap(k[i], k[j]); swap(v[i], v[j]); }
				}
				break;
			}
		}
		print_cnt(cnt, 3);
		solve(L, (L + R) >> 1);
		solve((L + R) >> 1, R);
	}
	void rmain() {
		for(int i = 0; i < N; ++i)
			cin >> k[i] >> v[i];
		solve(0, N);
		for(int i = 0; i < N; ++i)
			print(ans[i], 10);
	}
}
namespace decode {
	char *s;
	int read(int L) {
		int res = 0;
		for(int i = L - 1; ~i; --i)
			res = res * 2 + (*s++) - '0';
		return res;
	}
	int read_cnt(int bas) {
		int num = 0;
		for(; (*s++) == '1'; ++num);
		return !num? read(bas): (1 << (bas + num - 1)) + read(bas + num - 1);
	}
	#define ls (u << 1)
	#define rs (ls | 1)
	U T[N << 1], p[N], ans[N];
	void build(int u, int L, int R) {
		if(R - L == 8) {
			int cnt = read_cnt(9);
			for(; cnt; flush(), --cnt);
			T[u] = sd;
			return;
		}
		int cnt = read_cnt(3);
		for(; cnt; flush(), --cnt);
		T[u] = sd;
		build(ls, L, M);
		build(rs, M, R);
	}
	int qry(int u, int L, int R, U k) {
		if(R - L == 8)
			return L + (h(k, T[u]) & 7);
		if(h(k, T[u]) & 1)
			return qry(rs, M, R, k);
		return qry(ls, L, M, k);
	}
	void rmain() {
		s = new char[12500];
		cin >> s;
		build(1, 0, N);
		for(int i = 0; i < N; ++i)
			ans[i] = read(10);
		int _q;
		cin >> _q;
		for(U k; _q--; cout.put('\n')) {
			cin >> k;
			cout << ans[qry(1, 0, N, k)];
		}
	}
	#undef ls
	#undef rs
}
#undef M

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	char s[9];
	cin >> s;
	if(s[0] == 'e')
		encode::rmain();
	else
		decode::rmain();
    cout.flush(); return 0;
}
