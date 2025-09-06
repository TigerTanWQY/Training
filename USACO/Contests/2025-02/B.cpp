#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e6 + 3, LG = 20;
vector<int> words, valid;
int p[N], len[N], up[N][LG], cnt1[N], cnt2[N];

struct SegTree {
	int n;
	vector<int> tree;
	SegTree(int sz) {
		for(n = 1; n < sz; n <<= 1);
		tree.assign(2 * n, -1);
	}
	void update(int pos, int w) {
		pos += n;
		tree[pos] = w;
		for(pos >>= 1; pos >= 1; pos >>= 1)
			tree[pos] = max(tree[2 * pos], tree[2 * pos + 1]);
	}
	int query(int L, int R) {
		L += n; R += n;
		int res = -1;
		for(; L <= R; L >>= 1, R >>= 1) {
			if(L % 2 == 1)
				res = max(res, tree[L++]);
			if(R % 2 == 0)
				res = max(res, tree[R--]);
		}
		return res;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> p[i];
	len[0] = 0;
	for(int i = 1; i <= n; ++i) {
		len[i] = len[p[i]] + 1;
		up[i][0] = p[i];
		for (int j = 1; j < LG; ++j)
			up[i][j] = up[up[i][j - 1]][j - 1];
	}
	for(int x; cin >> x; words.push_back(x));
	int m = words.size();
	valid.assign(n, 0);
	SegTree st(n);
	for(const auto& w: words)
		for(int L = len[w]; L >= 0; --L) {
			int k = len[w] - L, u = w;
			for(int j = 0; j < LG; ++j)
				if(k & (1 << j))
					u = up[u][j];
			cnt1[u]++;
			if(cnt1[u] == 2) {
				cnt2[len[u]]++;
				if(cnt2[len[u]] == 1) {
					valid[len[u]] = 1;
					st.update(len[u], len[u]);
				}
			}
		}
	for(int i = 0; i < m; ++i) {
		int w = words[i], L = len[w], remaining = m - i;
		if(remaining == 1) {
			cout << "0\n";
			for(int L = len[w]; L >= 0; --L) {
				int k = len[w] - L, u = w;
				for(int j = 0; j < LG; ++j)
					if(k & (1 << j))
						u = up[u][j];
				cnt1[u]--;
				if(cnt1[u] == 1) {
					cnt2[len[u]]--;
					if(cnt2[len[u]] == 0) {
						valid[len[u]] = 0;
						st.update(len[u], -1);
					}
				}
			}
			continue;
		}
		int max_l = st.query(0, L), output = (max_l == -1)? 0: (max_l + 1);
		output = min(output, L);
		cout << output << '\n';
		for(int L = len[w]; L >= 0; --L) {
			int k = len[w] - L, u = w;
			for(int j = 0; j < LG; ++j)
				if(k & (1 << j))
					u = up[u][j];
			cnt1[u]--;
			if(cnt1[u] == 1) {
				cnt2[len[u]]--;
				if(cnt2[len[u]] == 0) {
					valid[len[u]] = 0;
					st.update(len[u], -1);
				}
			}
		}
	}
	cout.flush(); return 0;
}
