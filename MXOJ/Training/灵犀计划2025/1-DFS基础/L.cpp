#include <bits/stdc++.h>
using namespace std;

const vector<tuple<int, int, int>> row{{0, 1, 2},
								 {3, 4, 5},
								 {6, 7, 8},
								 {0, 3, 6},
								 {1, 4, 7},
								 {2, 5, 8},
								 {0, 4, 8},
								 {2, 4, 6}};

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	array<int, 9> d;
	for(auto &&x: d)
		cin >> x;
	array<int, 9> od;
	iota(begin(od), end(od), 0);
	int cnt = 0, tot = 0;
	do {
		++tot;
		bool flg = false;
		for(auto &&[a, b, c]: row)
			if((d[a] == d[b] && od[a] < od[c] && od[b] < od[c]) ||
				(d[a] == d[c] && od[a] < od[b] && od[c] < od[b]) ||
				(d[b] == d[c] && od[b] < od[a] && od[c] < od[a]))
				flg = true;
		if(!flg)
			++cnt;
	} while(ranges::next_permutation(od).found);
	cout << setprecision(8) << (double)cnt / tot << endl;
	return 0;
}
