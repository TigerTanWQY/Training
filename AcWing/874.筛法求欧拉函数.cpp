#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
using LL = long long;

bitset<1000003> b;
vector<int> c;

LL phi(int x) {
	LL res = x;
	for(const auto& i: c)
		if(i * i <= x) {
			if(x % i == 0) {
				while(x % i == 0)
					x /= i;
				res = res * (i - 1) / i;
			}
		} else
			break;
	if(x > 1)
		res = res * (x - 1) / x;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	b[1] = true;
	for(int i = 2; i * i <= n; ++i)
		if(!b[i]) {
			c.push_back(i);
			for(int j = i + i; j * j <= n; j += i)
				b[j] = true;
		}
	long long ans = 0;
	for(int i = 1; i <= n; ++i)
		ans += phi(i);
	cout << ans;
	cout.flush();
	return 0;
}