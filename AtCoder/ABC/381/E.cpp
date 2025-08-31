#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, _q;
	string s;
	cin >> n >> _q >> s;
	vector<int> idx1, idx2, idx;
	for(int i = 0; i < n; ++i)
		if(s[i] == '1')
			idx1.push_back(i);
		else if(s[i] == '2')
			idx2.push_back(i);
		else
			idx.push_back(i);
	auto lb = [](const vector<int>& a, int x) -> int
	{ return lower_bound(cbegin(a), cend(a), x) - cbegin(a); };
	for(int L, R; _q--; cout.put('\n')) {
		cin >> L >> R; --L;
		auto chk = [&](int x) -> bool {
			if(x == 0) {
				int j = lb(idx, L);
				if(j >= size(idx))
					return false;
				else
					return idx[j] < R;
			}
			int i = lb(idx1, L);
			if(i + x - 1 >= size(idx1))
				return false;
			int j = lb(idx, idx1[i + x - 1]);
			if(j >= size(idx))
				return false;
			int k = lb(idx2, idx[j]);
			if(k + x - 1 >= size(idx2))
				return false;
			return idx2[k + x - 1] < R;
		};
		int bL = -1, bR = n + 1;
		while(bL + 1 < bR) {
			int M = (bL + bR) >> 1;
			if(chk(M))
				bL = M;
			else
				bR = M;
		}
		cout << (bL == -1? 0: bL * 2 + 1);
	}
	cout.flush();
	return 0;
}
