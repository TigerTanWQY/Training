#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		cin >> n;
		vector<LL> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		vector<int> dis(n, -1);
		dis[0] = 0;
		set<pair<LL, int>> st;
		for(int i = 0; i < n; ++i)
			st.insert({a[i], i});
		auto it0 = st.find({a[0], 0});
		if(it0 != cend(st))
			st.erase(it0);
		queue<int> q;
		q.push(0);
		while(!q.empty() && dis[n - 1] == -1) {
			int u = q.front();
			q.pop();
			LL tmp = 2 * a[u];
			while(!st.empty()) {
				auto it = cbegin(st);
				if(it->first > tmp)
					break;
				int j = it->second;
				dis[j] = dis[u] + 1;
				q.push(j);
				st.erase(it);
				if(j == n - 1)
					break;
			}
		}
		cout << (dis[n - 1] == -1? -1: dis[n - 1] + 1);
	}
	cout.flush(); return 0;
}
