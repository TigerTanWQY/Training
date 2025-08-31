#include <bits/stdc++.h>
using namespace std;
using LL = long long;

bitset<1000003> isp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	LL n;
	cin >> n;
	vector<LL> c;
	isp[0] = isp[1] = true;
	for(LL i = 2; i <= min((LL)1e6, n); ++i)
		if(!isp[i]) {
			c.push_back(i);
			for(LL j = i + i; j <= min((LL)1e6, n); j += i)
				isp[j] = true;
		}
	unordered_set<LL> st;
	for(const auto& x: c)
		if(x * x * x * x * x * x * x * x <= n)
			st.insert(x * x * x * x * x * x * x * x);
		else
			break;
	for(int i = 0; i < c.size(); ++i) {
		LL tmp = c[i] * c[i];
		if(tmp * tmp > n)
			break;
		for(int j = i + 1; j < c.size(); ++j)
			if(tmp * c[j] * c[j] <= n)
				st.insert(tmp * c[j] * c[j]);
			else
				break;
	}
	cout << st.size() << endl;
	return 0;
}
