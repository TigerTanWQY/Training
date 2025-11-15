#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)

int n, lmt, m, res, ans = 1e15;
vector<int> fac;
struct node {
	int a, c;
} p[1000003];
map<int, vector<int>> mp;
int f[12][(1 << 12)+3];

void dp() {
	memset(f, 2, sizeof f); f[0][0] = 0;
	for(auto val: mp) {
		int x = val.first; vector <int> mul;
		sort(val.second.begin(), val.second.end());
		if(val.second.size() > m) val.second.resize(m);
		rep(i, 0, (1 << m) - 1) {
			int tot = 1, tmp = x;
			rep(j, 0, m - 1) if(i & (1 << j))
				while(!(tmp % fac[j])) tot *= fac[j], tmp /= fac[j];
			mul.push_back(tot);
		}
		for(auto cst : val.second) {
			bool flg = 0;
			per(i, m - 1, 0) rep(j, 0, (1 << m) - 1)
			if(f[i][j] <= 1e13) {
				int C = (1 << m) - 1 - j;
				for(int k = C; k; k = (k - 1) & C) if(mul[k] <= lmt)
						if(f[i + 1][j | k] > f[i][j] + cst) f[i + 1][j | k] = f[i][j] + cst, flg = 1;
			} if(!flg) break;
		}
	}
}

signed main() {
	scanf("%lld%lld", &n, &lmt);
	rep(i, 1, n) scanf("%lld", &p[i].a),
		res = gcd(res, p[i].a);
	rep(i, 1, n) scanf("%lld", &p[i].c);
	if(!(res - 1)) return printf("0"), 0;
	rep(i, 2, 1e6) if(i <= res && !(res % i)) {
		fac.push_back(i);
		while(!(res % i)) res /= i;
	} else if(i > res) break;
	if(res - 1) fac.push_back(res);
	m = fac.size();
	rep(i, 1, n) {
		int nw = 1;
		rep(j, 0, m - 1)
		while(!(p[i].a % fac[j])) nw *= fac[j], p[i].a /= fac[j];
		mp[nw].push_back(p[i].c);
	} dp();
	rep(i, 1, m) ans = min(ans, f[i][(1<<m) - 1] * i);
	if(ans > 1e13) printf("-1");
	else printf("%lld", ans);
	return 0;
}
