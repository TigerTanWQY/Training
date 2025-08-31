#include <iostream>
using namespace std;

constexpr const int N = 2e5 + 3;
pair<int, int> op[N];
int t[N], ans[N];

inline int bit(const int x, const int i)
{ return (x >> i) & 1; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, c;
	cin >> n >> c;
	for(int i = 0; i < n; ++i)
		cin >> op[i].first >> op[i].second;
	for(int k = 0; k < 30; ++k) {
		int func[]{0, 1}, crr = bit(c, k);
		for(int i = 0; i < n; ++i) {
			int f[2], x = bit(op[i].second, k);
			if(op[i].first == 1) {
				f[0] = 0 & x;
				f[1] = 1 & x;
			} else if(op[i].first == 2) {
				f[0] = 0 | x;
				f[1] = 1 | x;
			} else {
				f[0] = 0 ^ x;
				f[1] = 1 ^ x;
			}
			func[0] = f[func[0]];
			func[1] = f[func[1]];
			crr = func[crr];
			ans[i] |= crr << k;
		}
	}
	for(int i = 0; i < n; ++i)
		cout << ans[i] << '\n';
	cout.put('\n');
	return 0;
}