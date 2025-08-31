#include <iostream>
#include <utility>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using PII = pair<int, int>;
#define L first
#define R second

unordered_map<int, vector<int>> G;
PII a[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int _;
	cin >> _;
	for(int n; _--; ) {
		cin >> n;
		vector<int> idx;
		for(int i = 0; i < n; ++i) {
			cin >> a[i].L >> a[i].R;
			G[a[i].L].push_back(a[i].R);
			idx.push_back(a[i].L);
		}
		sort(idx.begin(), idx.end());
		idx.push_back(0x3f3f3f3f);
		priority_queue<int, vector<int>, greater<int>> q;
		bool flag = true;
		for(int i = idx.front(); i <= 1e9; ) {
			if(G.count(i))
				for(const auto& v: G[i])
					q.push(v);
			q.pop();
			if(q.empty())
				i = *lower_bound(idx.cbegin(), idx.cend(), i + 1);
			else {
				if(q.top() <= i) {
					flag = false;
					break;
				}
				++i;
			}
		}
		if(!q.empty())
			flag = false;
		if(flag)
			cout << "Yes";
		else
			cout << "No";
		cout << '\n';
		G.clear();
	}
	return 0;
}