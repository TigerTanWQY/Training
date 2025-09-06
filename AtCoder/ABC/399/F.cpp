#include <iostream>
#include <vector>
using namespace std;

constexpr const int MOD = 998244353;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	vector<int> S(N + 1);
	S[0] = 0;
	for (int i = 1; i <= N; i++)
		S[i] = (S[i - 1] + A[i - 1]) % MOD;
	vector<vector<int>> pow_S(N + 1, vector<int>(K + 1));
	for (int r = 0; r <= N; r++) {
		pow_S[r][0] = 1;
		for (int e = 1; e <= K; e++)
			pow_S[r][e] = (static_cast<long long>(pow_S[r][e - 1]) * S[r]) % MOD;
	}
	vector<vector<int>> prefix_e(K + 1, vector<int>(N + 1));
	for (int e = 0; e <= K; e++) {
		prefix_e[e][0] = pow_S[0][e];
		for (int r = 1; r <= N; r++)
			prefix_e[e][r] = (prefix_e[e][r - 1] + pow_S[r][e]) % MOD;
	}
	vector<int> comb(K + 1);
	comb[0] = 1;
	for (int i = 1; i <= K; i++)
		comb[i] = static_cast<long long>(comb[i - 1]) * (K - i + 1) / i;
	long long ans = 0;
	for (int i = 0; i <= K; i++) {
		int e = K - i;
		int c = comb[i];
		int sign = (e % 2 == 0) ? 1 : -1;
		int term = static_cast<long long>(c) * (sign == 1 ? 1 : MOD - 1) % MOD;
		long long sum_part = 0;
		const vector<int>& pe = prefix_e[e];
		for (int r = 1; r <= N; r++) {
			int s_i = pow_S[r][i];
			int pre = pe[r - 1];
			sum_part = (sum_part + static_cast<long long>(s_i) * pre) % MOD;
		}
		long long contribution = static_cast<long long>(term) * sum_part % MOD;
		ans = (ans + contribution) % MOD;
	}
	ans = (ans + MOD) % MOD;
	cout << ans << endl;
	return 0;
}
