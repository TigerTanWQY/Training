#include <iostream>
using namespace std;

const int M = 10000;
int A[1003], buf1[2 * M + 3], buf2[2 * M + 3], buf3[2 * M + 3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, x, y;
	cin >> N >> x >> y;
	for(int i = 0; i < N; ++i)
		cin >> A[i];
	int *dp1 = buf1 + M, *dp2 = buf2 + M, *dp3 = buf3 + M;
	dp1[A[0]] = dp2[0] = 1;
	for(int i = 1; i < N; ++i) {
		for(int j = -M; j <= M; ++j)
			dp3[j] = 0;
		int a = A[i];
		if(!(i & 1)) {
			for(int j = -M; j <= M - a; ++j) {
				dp3[j + a] |= dp1[j];
				dp3[j] |= dp1[j + a];
			}
			swap(dp1, dp3);
		} else {
			for(int j = -M; j <= M - a; ++j) {
				dp3[j + a] |= dp2[j];
				dp3[j] |= dp2[j + a];
			}
			swap(dp2, dp3);
		}
	}
	if(dp1[x] && dp2[y])
		cout << "Yes";
	else
		cout << "No";
	return 0;
}