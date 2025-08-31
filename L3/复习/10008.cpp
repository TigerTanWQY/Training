#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	unordered_map<int, int> x, v;
	for(int i = 1, m; i <= n; ++i) {
		cin >> m;
		for(int p, e; m--; ) {
			cin >> p >> e;
			if(x[p] == e)
				v[p] = 0;
			else if(x[p] < e) {
				v[p] = i;
				x[p] = e;
			}
		}
	}
	unordered_set<int> st{0};
	for(const auto& [_, p]: v)
		st.insert(p);
	cout << min((int)st.size(), n) << endl;
	return 0;
}