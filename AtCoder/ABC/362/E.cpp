#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MOD = 998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i)
        std::cin >> A[i];

    std::vector<std::unordered_map<long long, std::unordered_map<int, long long>>> dp(N);
    std::vector<long long> res(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        res[1] = (res[1] + 1) % MOD;
        dp[i][A[i]][0] = 1;

        for (auto &it : dp[i]) {
            long long val = it.first;
            for (auto &it2 : it.second) {
                int prevIndex = it2.first;
                if (prevIndex > i) continue;
                long long diff = A[i] - val;
                auto &next = dp[i][val + diff];
                next[prevIndex + 1] = (next[prevIndex + 1] + it2.second) % MOD;
                for (auto &it3 : next) {
                    int len = it3.first;
                    res[len + 1] = (res[len + 1] + it3.second) % MOD;
                }
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        std::cout << res[i] << (i == N ? '\n' : ' ');
    }
    return 0;
}