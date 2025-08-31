#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <iostream>
#include <vector>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
using LL = long long;
template<typename _Tp1, typename _Tp2>
using hash_mp = __gnu_pbds::gp_hash_table<_Tp1, _Tp2>;

hash_mp<int, vector<pair<LL, LL>>> G;
hash_mp<int, int> idx;
int cnt = 0;

int ext(void) {
	/*
	cout.flush();
	cerr.flush();
	*/
	fclose(stdin);
	fclose(stdout);
	fclose(stderr);
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x, d;
	cin >> n >> x >> d;
	/*
	if(d == 0) { // Anti-Mod-0
		if(x == 0)
			cout.put('1');
		else
			cout << n + 1;
		return ext();
	}
	*/
    for(int i = 0; i <= n; ++i) {
        if(!idx[i * x % d])
			idx[i * x % d] = ++cnt;
        G[idx[i * x % d]].push_back({(LL)i * (i - 1) / 2 + (LL)i * x / d, (2LL * n - 1 - i) * i / 2 + (LL)i * x / d});
    }
    LL ans = 0;
    for(int i = 1; i <= cnt; ++i) {
        sort(G[i].begin(), G[i].end());
        auto [L, R] = G[i][0];
        for(int j = 1; j < G[i].size(); ++j)
            if(G[i][j].first <= R)
				R = max(G[i][j].second, R);
            else {
				ans += R - L + 1;
				L = G[i][j].first;
				R = G[i][j].second;
			}
        ans += R - L + 1;
    }
    cout << ans;
    return ext();
}