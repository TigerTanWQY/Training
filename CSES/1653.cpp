#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 20 + 1;
pair<int, int> f[1 << N];
int w[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; ++i)
        cin >> w[i];
    f[0] = {1, 0};
    for(int S = 1; S < 1 << n; ++S) {
        auto& ans = f[S];
        ans = {0x3f3f3f3f, 0x3f3f3f3f};
        for(int j = 0; j < n; ++j)
            if(S & 1 << j) {
                auto res = f[S ^ (1 << j)];
                if(res.second + w[j] <= x)
                    res = {res.first, res.second + w[j]};
                else
                    res = {res.first + 1, w[j]};
                ans = min(ans, res);
            }
    }
    cout << f[(1 << n) - 1].first << endl;
    return 0;
}