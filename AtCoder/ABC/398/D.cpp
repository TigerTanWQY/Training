#include <bits/stdc++.h>
using namespace std;

struct ph {
	template<class T1, class T2>
	size_t operator()(const pair<T1, T2>& p) const
	{ return hash<T1>{}(p.first) ^ (hash<T2>{}(p.second) << 1); }
};
constexpr const int N = 2e5 + 3;
int sr[N], sc[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, R, C; string s;
	cin >> n >> R >> C >> s;
	for(int t = 1; t <= n; ++t) {
		char ch = s[t - 1];
		int dr = 0, dc = 0;
		switch(ch) {
			case 'N':
				dr = -1; break;
			case 'S':
				dr = 1; break;
			case 'W':
				dc = -1; break;
			case 'E':
				dc = 1; break;
		}
		sr[t] = sr[t - 1] + dr;
		sc[t] = sc[t - 1] + dc;
	}
	unordered_set<pair<int, int>, ph> ss;
	unordered_map<pair<int, int>, vector<int>, ph> mps;
	ss.insert({0, 0});
	mps[{0, 0}].push_back(0);
	for(int k = 1; k <= n; ++k) {
		pair<int, int> tmp = {sr[k], sc[k]};
		if(ss.find(tmp) == ss.cend()) {
			ss.insert(tmp);
			mps[tmp].push_back(k);
		}
	}
	string ans;
	for(int t = 1; t <= n; ++t) {
		int s_r = sr[t] - R, s_c = sc[t] - C;
		auto it = mps.find({s_r, s_c});
		if(it == mps.cend()) {
			ans += '0';
			continue;
		}
		const auto& kl = it->second;
		ans += ('0' + (upper_bound(kl.cbegin(), kl.cend(), t) != kl.cbegin()));
	}
	cout << ans << endl;
	return 0;
}
