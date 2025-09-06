#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		vector<int> rmax(n, -1), rid(n, -1);
		int cmax = -1, cid = -1;
		for(int i = n - 2; i >= 0; --i) {
			if(a[i + 1] > cmax) {
				cmax = a[i + 1];
				cid = i + 1;
			} else if(a[i + 1] == cmax)
				cid = i + 1;
			rmax[i] = cmax;
			rid[i] = cid;
		}
		int id = -1;
		for(int k = 0; k < n; ++k)
			if(rmax[k] != -1 && a[k] < rmax[k]) {
				id = k;
				break;
			}
		if(id != -1) {
			int j = rid[id];
			vector<int> tmp;
			tmp.reserve(n);
			for(int k = 0; k < id; ++k)
				tmp.push_back(a[k]);
			tmp.push_back(a[j]);
			for(int k = id; k < j; ++k)
				tmp.push_back(a[k]);
			for(int k = j + 1; k < n; ++k)
				tmp.push_back(a[k]);
			a = move(tmp);
		}
		vector<int> ans;
		for(const auto& x: a) {
			for(; !ans.empty() && x > ans.back(); ans.pop_back());
			ans.push_back(x);
		}
		for(int i = 0; i < ans.size(); ++i) {
			cout << ans[i];
			if(i != ans.size() - 1)
				cout.put(' ');
		}
	}
	cout.flush();
	return 0;
}
