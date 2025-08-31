#include <bits/stdc++.h>
using namespace std;
using ULL = unsigned long long;

constexpr const ULL B1 = 911382629, B2 = 357147329;
constexpr const int N = 5e5 + 3;
ULL p1[N], p2[N], h1[N], h2[N], hr1[N], hr2[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	if(n == 1) {
		cout << s << endl;
		return 0;
	}
	p1[0] = p2[0] = 1;
	for(int i = 1; i <= n; ++i) {
		p1[i] = p1[i - 1] * B1;
		p2[i] = p2[i - 1] * B2;
	}
	for(int i = 0; i < n; ++i) {
		h1[i + 1] = h1[i] * B1 + s[i];
		h2[i + 1] = h2[i] * B2 + s[i];
	}
	string sr(s.crbegin(), s.crend());
	for(int i = 0; i < n; ++i) {
		hr1[i + 1] = hr1[i] * B1 + sr[i];
		hr2[i + 1] = hr2[i] * B2 + sr[i];
	}
	int id = n;
	for(int i = 0; i < n; ++i) {
		int l = n - i;
		ULL Hs1 = h1[n] - h1[i] * p1[l], Hr1 = hr1[l];
		ULL Hs2 = h2[n] - h2[i] * p2[l], Hr2 = hr2[l];
		if(Hs1 == Hr1 && Hs2 == Hr2) {
			id = i;
			break;
		}
	}
	string ans = s.substr(0, id);
	reverse(ans.begin(), ans.end());
	cout << s << ans << endl;
	return 0;
}
