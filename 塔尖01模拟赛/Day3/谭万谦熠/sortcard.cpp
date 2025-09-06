#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

vector<string> nxt(string u) {
	vector<string> res;
	int m = u.size();
	for(int i = 0; i < m; ++i)
		for(int L = 1; L <= m - i; ++L) {
			string s = u.substr(i, L),
				t = u.substr(0, i) + u.substr(i + L);
			for(int j = 0; j <= t.size(); ++j)
				res.push_back(t.substr(0, j) + s + t.substr(j));
		}
	return res;
}

int main() {
	freopen("sortcard.in", "r", stdin);
	freopen("sortcard.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	string st, ed;
	for(int i = 0, x; i < n; ++i) {
		cin >> x;
		st += '0' + x;
		ed += '0' + i + 1;
	}
	if(st == ed) {
		cout.put('0') << endl;
		return 0;
	}
	__gnu_pbds::gp_hash_table<string, int> dis1, dis2;
	dis1[st] = dis2[ed] = 0;
	queue<string> q1, q2;
	q1.push(st); q2.push(ed);
	int ans = -1;
	bool flg = false;
	while(!q1.empty() && !q2.empty() && !flg)
		if(q1.size() <= q2.size()) {
			int m = q1.size();
			for(int c = 0; c < m && !flg; ++c) {
				string u = q1.front();
				q1.pop();
				vector<string> tmp = nxt(u);
				for(const auto &v: tmp) {
					if(dis1.find(v) != dis1.end())
						continue;
					dis1[v] = dis1[u] + 1;
					if(dis2.find(v) != dis2.end()) {
						ans = dis1[v] + dis2[v];
						flg = true;
						break;
					}
					q1.push(v);
				}
			}
		} else {
			int m = q2.size();
			for(int c = 0; c < m && !flg; ++c) {
				string u = q2.front();
				q2.pop();
				vector<string> tmp = nxt(u);
				for(const auto &v: tmp) {
					if(dis2.find(v) != dis2.end())
						continue;
					dis2[v] = dis2[u] + 1;
					if(dis1.find(v) != dis1.end()) {
						ans = dis1[v] + dis2[v];
						flg = true;
						break;
					}
					q2.push(v);
				}
			}
		}
	cout << ans << endl;
	return 0;
}
