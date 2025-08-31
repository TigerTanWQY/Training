#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const LL INF = 0x3f3f3f3f3f3f3f3f;
constexpr const int N = (int)1e5 + 3, LOGN = (int)log2(N) + 3;
int lg[N];
LL amx[LOGN][N], amn[LOGN][N], bmx[LOGN][N], bmn[LOGN][N], afx[LOGN][N], azn[LOGN][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		amx[0][i] = amn[0][i] = x;
		afx[0][i] = (x < 0? x: -INF);
		azn[0][i] = (x >= 0? x: INF);
	}
	for(int i = 1, x; i <= m; ++i) {
		cin >> x;
		bmx[0][i] = bmn[0][i] = x;
	}
	for(int i = 2; i <= max(n, m); ++i)
		lg[i] = lg[i >> 1] + 1;
	for(int j = 1; j <= lg[n]; ++j)
		for(int i = 1; i + (1 << j) - 1 <= n; ++i) {
			int p = i + (1 << j - 1);
			amx[j][i] = max(amx[j - 1][i], amx[j - 1][p]);
			afx[j][i] = max(afx[j - 1][i], afx[j - 1][p]);
			amn[j][i] = min(amn[j - 1][i], amn[j - 1][p]);
			azn[j][i] = min(azn[j - 1][i], azn[j - 1][p]);
		}
	for(int j = 1; j <= lg[m]; ++j)
		for(int i = 1; i + (1 << j) - 1 <= m; ++i) {
			int p = i + (1 << (j - 1));
			bmx[j][i] = max(bmx[j - 1][i], bmx[j - 1][p]);
			bmn[j][i] = min(bmn[j - 1][i], bmn[j - 1][p]);
		}
	for(int La, Ra, Lb, Rb; q--; cout.put('\n')) {
		cin >> La >> Ra >> Lb >> Rb;
		const int lga = lg[Ra - La + 1], lgb = lg[Rb - Lb + 1], pa = Ra - (1 << lga) + 1, pb = Rb - (1 << lgb) + 1;
		const LL amax = max(amx[lga][La], amx[lga][pa]), amin = min(amn[lga][La], amn[lga][pa]), afmx = max(afx[lga][La], afx[lga][pa]), azmn = min(azn[lga][La], azn[lga][pa]), bmax = max(bmx[lgb][Lb], bmx[lgb][pb]), bmin = min(bmn[lgb][Lb], bmn[lgb][pb]);
		LL ans = -INF;
		ans = max({ans, amax * (amax >= 0? bmin: bmax), amin * (amin >= 0? bmin: bmax)});
		if(afmx != -INF)
			ans = max(ans, afmx * (afmx >= 0? bmin: bmax));
		if(azmn != INF)
			ans = max(ans, azmn * (azmn >= 0? bmin: bmax));
		cout << ans;
	}
	cout.flush();
	return 0;
}