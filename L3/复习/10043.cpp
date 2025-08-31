#include <iostream>
using namespace std;

constexpr const int N = 10000, CAP = N * 2 + 3;
bool buf1[CAP], buf2[CAP], buf3[CAP];
int a[1003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x, y;
	cin >> n >> x >> y;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	bool *dp1 = buf1 + N, *dp2 = buf2 + N, *dp3 = buf3 + N;
	dp1[a[0]] = dp2[0] = true;
	for(int i = 1; i < n; ++i) {
		for(int j = -N; j <= N; ++j)
			dp3[j] = false;
		const int& k = a[i];
		if(i & 1) {
			for(int j = -N; j <= N - k; ++j) {
				dp3[j + k] |= dp2[j];
				dp3[j] |= dp2[j + k];
			}
			swap(dp2, dp3);
		} else {
			for(int j = -N; j <= N - k; ++j) {
				dp3[j + k] |= dp1[j];
				dp3[j] |= dp1[j + k];
			}
			swap(dp1, dp3);
		}
	}
	if(dp1[x] && dp2[y])
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	return 0;
}