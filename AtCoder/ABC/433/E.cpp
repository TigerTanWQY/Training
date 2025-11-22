#include <bits/stdc++.h>
using namespace std;

struct Node {
	int n{}, m{};
	vector<int> X{}, Y{};

	bool chk() {
		if(*max_element(cbegin(X), cend(X)) != n*m ||
				*max_element(cbegin(Y), cend(Y)) != n*m)
			return false;
		if(count(cbegin(X), cend(X), n*m) != 1 ||
				count(cbegin(Y), cend(Y), n*m) != 1)
			return false;
		vector dx = X, dy = Y;
		sort(begin(dx), end(dx), greater<>());
		sort(begin(dy), end(dy), greater<>());
		for(int i = 0, j = 0, k = n*m, c0 = 0,
				c1 = 0, c2 = 0, c3 = 0; k; --k) {
			int tmp = (c0 + c1) * (c0 + c2) -
								 (c0 + c1 + c2) - c3;
			bool inX = (i < n && dx[i] == k),
				inY = (j < m && dy[j] == k);
			if(inX && inY) {
				if(tmp < 0)
					return false;
				++c0;
				++i;
				++j;
			} else if(inX) {
				if(c0+c2 == 0)
					return false;
				++c1;
				++i;
			} else if(inY) {
				if(c0+c1 == 0)
					return false;
				++c2;
				++j;
			} else {
				if(tmp <= 0)
					return false;
				++c3;
			}
		}
		return true;
	}

	auto make() {
		vector res(n, vector<int>(m, 0));
		vector<pair<int, int>> r, c;
		for(int i = 0; i < n; ++i)
			r.emplace_back(X[i], i);
		for(int j = 0; j < m; ++j)
			c.emplace_back(Y[j], j);
		sort(begin(r), end(r), greater<>());
		sort(begin(c), end(c), greater<>());
		vector<bool> b(n*m + 1, false);
		set<pair<int, int>> st;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				st.emplace(i, j);
		for(int k = n*m; k; --k) {
			bool ismx1 = false, ismx2 = false;
			int ir = -1, ic = -1;
			for(int i = 0; i < n; ++i)
				if(r[i].first == k && res[r[i].second][0] == 0) {
					ismx1 = true;
					ir = r[i].second;
					break;
				}
			for(int j = 0; j < m; ++j)
				if(c[j].first == k && res[0][c[j].second] == 0) {
					ismx2 = true;
					ic = c[j].second;
					break;
				}
			pair<int, int> pos{-1, -1};
			if(ismx1 && ismx2)
				pos = {ir, ic};
			else if(ismx1) {
				for(int j = 0; j < m; ++j)
					if(res[ir][j] == 0 && Y[j] >= k) {
						pos = {ir, j};
						break;
					}
			} else if(ismx2) {
				for(int i = 0; i < n; ++i)
					if(res[i][ic] == 0 && X[i] >= k) {
						pos = {i, ic};
						break;
					}
			} else {
				for(int i = 0; i < n; ++i) {
					for(int j = 0; j < m; ++j)
						if(res[i][j] == 0 && X[i] >= k && Y[j] >= k) {
							pos = {i, j};
							break;
						}
					if(pos.first != -1)
						break;
				}
			}
			if(pos.first == -1)
				for(int i = 0; i < n; ++i) {
					for(int j = 0; j < m; ++j)
						if(res[i][j] == 0) {
							pos = {i, j};
							break;
						}
					if(pos.first != -1)
						break;
				}
			if(pos.first == -1 || b[k])
				return vector<vector<int>>{};
			res[pos.first][pos.second] = k;
			b[k] = true;
			st.erase(pos);
		}
		return res;
	}
};

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(; _T--; ) {
		Node A;
		cin >> A.n >> A.m;
		A.X.resize(A.n);
		A.Y.resize(A.m);
		for(int i = 0; i < A.n; ++i)
			cin >> A.X[i];
		for(int j = 0; j < A.m; ++j)
			cin >> A.Y[j];
		if(!A.chk())
			cout << "No\n";
		else {
			auto res = A.make();
			if(res.empty())
				cout << "No\n";
			else {
				cout << "Yes\n";
				for(int i = 0; i < A.n; ++i) {
					for(int j = 0; j < A.m; ++j)
						cout << res[i][j] << ' ';
					cout.put('\n');
				}
			}
		}
	}
	cout.flush(); return 0;
}
