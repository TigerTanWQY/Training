#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

struct Lawyer {
	int a, b, id;
	bool operator<(const Lawyer& A) const {
		if(a != A.a)
			return a < A.a;
		else
			return b < A.b;
	}
} w[1000003];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> w[i].a >> w[i].b;
		w[i].id = i;
	}
	sort(w + 1, w + n + 1);
	priority_queue<int, vector<int>, greater<int>> q;
	int L = 0, R = 0;
	for(int i = 1; i <= n; ++i) {
		q.push(w[i].b);
		while(q.size() > k)
			q.pop();
		if(q.size() == k && (q.top() - w[i].a) > (R - L)) {
			L = w[i].a;
			R = q.top();
		}
	}
	cout << R - L << '\n';
	vector<int> ans;
	int cnt = 0;
	for(int i = 1; i <= n; ++ i)
		if(w[i].a <= L && w[i].b >= R && cnt < k) {
			++cnt;
//			cout << w[i].id << ' ';
			ans.push_back(w[i].id);
		}
	sort(ans.begin(), ans.end());
	for(const auto& x: ans)
		cout << x << ' ';
	return 0;
}