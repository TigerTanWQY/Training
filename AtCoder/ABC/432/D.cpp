#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using LL = long long;

struct Rect
{ LL x1, x2, y1, y2; };

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; LL X, Y;
	cin >> n >> X >> Y;
	vector<Rect> a;
	a.push_back({0, X-1, 0, Y-1});
	for(int i = 0; i < n; ++i) {
		char ch; LL A, B;
		cin >> ch >> A >> B;
		vector<Rect> ta;
		for(const Rect& r: a)
			if(ch == 'X')
				if(r.x2 < A)
					ta.push_back({r.x1, r.x2, r.y1 - B, r.y2 - B});
				else if(r.x1 >= A)
					ta.push_back({r.x1, r.x2, r.y1 + B, r.y2 + B});
				else {
					ta.push_back({r.x1, A-1, r.y1 - B, r.y2 - B});
					ta.push_back({A, r.x2, r.y1 + B, r.y2 + B});
				}
			else
				if(r.y2 < A)
					ta.push_back({r.x1 - B, r.x2 - B, r.y1, r.y2});
				else if(r.y1 >= A)
					ta.push_back({r.x1 + B, r.x2 + B, r.y1, r.y2});
				else {
					ta.push_back({r.x1 - B, r.x2 - B, r.y1, A-1});
					ta.push_back({r.x1 + B, r.x2 + B, A, r.y2});
				}
		a = ta;
	}
	int na = a.size();
	atcoder::dsu dsu(na);
	unordered_map<LL, vector<int>> mpL, mpR, mpB, mpT;
	for(int i = 0; i < na; ++i) {
		const auto& [x1, x2, y1, y2] = a[i];
		mpL[x1].push_back(i);
		mpR[x2].push_back(i);
		mpB[y1].push_back(i);
		mpT[y2].push_back(i);
	}
	for(const auto& [x, lR]: mpR) {
		auto it = mpL.find(x + 1);
		if(it != mpL.cend()) {
			const vector<int>& lL = it->second;
			for(const auto& i: lR)
				for(const auto& j: lL)
					if(max(a[i].y1, a[j].y1) <= min(a[i].y2, a[j].y2))
						dsu.merge(i, j);
		}
	}
	for(const auto& [y, lT]: mpT) {
		auto it = mpB.find(y + 1);
		if(it != mpB.cend()) {
			const vector<int>& lB = it->second;
			for(const auto& i: lT)
				for(const auto& j: lB)
					if(max(a[i].x1, a[j].x1) <= min(a[i].x2, a[j].x2))
						dsu.merge(i, j);
		}
	}
	unordered_map<int, LL> sz;
	for(int i = 0; i < na; ++i)
		sz[dsu.leader(i)] += (a[i].x2 - a[i].x1 + 1) * (a[i].y2 - a[i].y1 + 1);
	vector<LL> ans;
	for(const auto& p: sz)
		ans.push_back(p.second);
	sort(begin(ans), end(ans));
	cout << ans.size() << '\n';
	for(const auto& x: ans)
		cout << x << ' ';
	cout << endl; return 0;
}
