#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e6 + 3;
int c[N], v[N], f[N], n;

bool chk(int L, int R) {
	unordered_set<int> st;
	for(int i = L; i <= R; ++i)
		st.insert(c[i]);
	for(int i = 1; i < L; ++i)
		if(st.count(c[i]))
			return false;
	for(int i = R + 1; i <= n; ++i)
		if(st.count(c[i]))
			return false;
	return true;
}

long long calc(int L, int R) {
	long long res = 0;
	for(int i = L; i <= R; ++i)
		res += v[i] * f[i-L+1];
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> c[i];
	for(int i = 1; i <= n; ++i)
		cin >> v[i];
	for(int i = 1; i <= n; ++i)
		cin >> f[i];
	long long ans = 1e18;
	for(int L = 1; L <= n; ++L)
		for(int R = L; R <= n; ++R)
			if(chk(L, R))
				ans = min(ans, calc(L, R));
	cout << ans << endl;
	return 0;
}
