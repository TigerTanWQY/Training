#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void c2d(char c, LL &dx, LL &dy) {
	dx = dy = 0;
	if(c == 'U')
		dx = -1;
	else if(c == 'D')
		dx = 1;
	else if(c == 'L')
		dy = -1;
	else if(c == 'R')
		dy = 1;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	LL Rt, Ct, Ra, Ca, n, m, L;
	cin >> Rt >> Ct >> Ra >> Ca >> n >> m >> L;
	vector<pair<char, LL>> sr, tr;
	for(LL i = 0; i < m; ++i) {
		char c; LL a;
		cin >> c >> a;
		sr.push_back({c, a});
	}
	for(LL i = 0; i < L; ++i) {
		char c; LL a;
		cin >> c >> a;
		tr.push_back({c, a});
	}
	vector<LL> se;
	vector<pair<LL, LL>> sd;
	LL sc = 0;
	for(const auto& [c, len]: sr) {
		sc += len;
		se.push_back(sc);
		LL dx, dy;
		c2d(c, dx, dy);
		sd.push_back({dx, dy});
	}
	vector<LL> te;
	vector<pair<LL, LL>> td;
	LL tc = 0;
	for(const auto& [c, len]: tr) {
		tc += len;
		te.push_back(tc);
		LL dx, dy;
		c2d(c, dx, dy);
		td.push_back({dx, dy});
	}
	set<LL> cst;
	cst.insert(1);
	cst.insert(n+1);
	for(const auto& x: se) {
		cst.insert(x);
		cst.insert(x+1);
	}
	for(const auto& x: te) {
		cst.insert(x);
		cst.insert(x+1);
	}
	vector<LL> cp(cst.cbegin(), cst.cend());
	LL dR = Rt - Ra, dC = Ct - Ca, ans = 0;
	for(int i = 0; i < cp.size() - 1; i++) {
		LL L = cp[i], R = cp[i+1] - 1;
		if(L > R)
			continue;
		LL len = R - L + 1;
		auto sit = lower_bound(se.begin(), se.end(), L);
		LL si = sit - se.begin();
		LL dxs = sd[si].first;
		LL dys = sd[si].second;
		auto tit = lower_bound(te.begin(), te.end(), L);
		LL ti = tit - te.begin();
		LL dxt = td[ti].first;
		LL dyt = td[ti].second;
		LL ddr = dxs - dxt;
		LL ddc = dys - dyt;
		if (ddr == 0 && ddc == 0) {
			if (dR == 0 && dC == 0) {
				ans += len;
			}
		} else if (ddr == 0) {
			if (dR == 0) {
				if (dC % ddc == 0) {
					LL i_val = -dC / ddc;
					if (i_val >= 1 && i_val <= len) {
						ans++;
					}
				}
			}
		} else if (ddc == 0) {
			if (dC == 0) {
				if (dR % ddr == 0) {
					LL i_val = -dR / ddr;
					if (i_val >= 1 && i_val <= len) {
						ans++;
					}
				}
			}
		} else
			if (dR * ddc == dC * ddr)
				if (dR % ddr == 0 && dC % ddc == 0) {
					LL i_val1 = -dR / ddr;
					LL i_val2 = -dC / ddc;
					if (i_val1 == i_val2 && i_val1 >= 1 && i_val1 <= len)
						ans++;
				}
		dR += len * ddr;
		dC += len * ddc;
	}
	cout << ans << endl;
	return 0;
}
