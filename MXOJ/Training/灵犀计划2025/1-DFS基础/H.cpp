#include <bits/stdc++.h>
using namespace std;

vector<string> G[3], a;
string r, c;
bool flg = false;
int n;

void dfs(int i, int S){
	if(flg)
		return;
	if(i == n) {
		if(!S) {
			cout << "Yes\n";
			for(const auto& x: a)
				cout << x << '\n';
			flg = true;
		}
		return;
	}
	for(const auto& x: G[r[i]-'A']) {
		a.push_back(x);
		int T = S;
		bool tmp = true;
		for(int j = 0; j < n; ++j) {
			if(x[j] == '.')
				continue;
			int tp = x[j] - 'A';
			if(!(S & (1 << (4 * j + tp)))) {
				tmp = false;
				break;
			}
			T ^= 1 << (4 * j + tp);
			if(S & (1 << (4 * j + 3))) {
				if(x[j] != c[j]) {
					tmp = false;
					break;
				}
				T ^= 1 << (4 * j + 3);
			}
		}
		if(tmp)
			dfs(i + 1, T);
		a.pop_back();
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> r >> c;
	string str = "ABC";
	while(str.size() < n)
		str.push_back('.');
	sort(begin(str), end(str));
	do {
		char ch = '.';
		for(const auto& x: str)
			if(x != '.') {
				ch = x;
			break;
		}
		G[ch - 'A'].push_back(str);
	} while(next_permutation(begin(str), end(str)));
	dfs(0, (1 << (4 * n)) - 1);
	if(!flg)
		cout << "No\n";
	cout.flush(); return 0;
}
