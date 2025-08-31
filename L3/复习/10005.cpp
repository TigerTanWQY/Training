#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 2e5 + 3;
int a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n, V;
    cin >> n >> V;
    for(int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];
    long long ans = 0x3f3f3f3f3f3f3f3f, tot = 0;
    for(int i = 0; i < n; ++i) {
        if(i >= V)
            break;
        tot += a[i] + b[i];
        ans = min(ans, tot + (long long)b[i] * (V - i - 1));
    }
    cout << ans << endl;
    return 0;
}