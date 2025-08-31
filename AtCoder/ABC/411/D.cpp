#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, _q;
	cin >> n >> _q;
	vector<pair<int, string>> a;
	a.reserve(200001);
	a.push_back({-1, ""});
	vector<int> pc(n + 1, 0);
	int svc = 0, cnt = 0;
	for(int i = 0; i < _q; ++i) {
		string op;
		cin >> op;
		if(op == "1") {
			int p;
			cin >> p;
			pc[p] = svc;
		} else if(op == "2") {
			int p;
			string s;
			cin >> p >> s;
			++cnt;
			int base = pc[p];
			a.push_back({base, s});
			pc[p] = cnt;
		} else if(op == "3") {
			int p;
			cin >> p;
			svc = pc[p];
		}
	}
	if(svc == 0)
		cout << endl;
	else {
		vector<string> pa;
		int cur = svc;
		while(cur != 0) {
			pa.push_back(a[cur].second);
			cur = a[cur].first;
		}
		reverse(begin(pa), end(pa));
		string ans;
		size_t len = 0;
		for(const string& s: pa)
			len += s.size();
		ans.reserve(len);
		for(const string& s: pa)
			ans += s;
		cout << ans << endl;
	}
	return 0;
}
