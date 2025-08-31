#include <iostream>
#include <unordered_set>
using namespace std;

constexpr const int N = 5'003;
int a[N], f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	unordered_set<int> st;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		st.insert(a[i]);
	}
	for(const auto& j: st)
		for(int i = 1; i <= n; ++i)
			f[i][j] = min(f[i - 1][j], f[i][j]);
	cout << f[n][st.size()];
	cout.flush();
	return 0;
}