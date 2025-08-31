#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
using LL = long long;

const int N = 10'000'003;
vector<int> c;
bitset<N> b;
int phi[N];
LL s[N];

void init(const int& n) {
	b[1] = true;
	for(int i = 2; i <= n; ++i) {
		if(!b[i]) {
			c.push_back(i);
			phi[i] = i - 1;
		}
		for(const auto& x: c)
			if(x * i <= n) {
				b[x * i] = true;
				if(i % x == 0) {
					phi[i * x] = phi[i] * x;
					break;
				}
				phi[i * x] = phi[i] * (x - 1);
			} else
				break;
	}
	for(int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + phi[i];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	init(n);
	LL ans = 0;
	for(const auto& x: c)
		ans += s[n / x] * 2 + 1;
	cout << ans;
	cout.flush();
	return 0;
}