#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int ans = 0;
	unordered_map<int, int> cnt;
	queue<int> a;
	for(int x; n--; ) {
		cin >> x;
		a.push(x);
		++cnt[x];
		if(cnt[x] > 1) {
			ans = max(ans, int(a.size() - 1));
			for(; a.front() != a.back(); a.pop())
				if(--cnt[a.front()])
					cnt.erase(a.front());
			a.pop();
		}
	}
	ans = max(ans, int(a.size()));
	cout << ans;
	return 0;
}