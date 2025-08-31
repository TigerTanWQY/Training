#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr const int N = 2e5 + 3;
vector<int> idx;
pair<int, int> a[N], b[N];
long long s[N * 3];

int get_id(const int& x)
{ return lower_bound(idx.cbegin(), idx.cend(), x) - idx.cbegin() + 1; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		idx.push_back(a[i].first);
	}
	for(int i = 1; i <= n; ++i)
		cin >> a[i].second;
	cin >> q;
	for(int i = 1; i <= q; ++i) {
		cin >> b[i].first >> b[i].second;
		idx.push_back(b[i].first); idx.push_back(b[i].second);
	}
	sort(idx.begin(), idx.end());
	idx.erase(unique(idx.begin(), idx.end()), idx.cend());
	for(int i = 1; i <= n; ++i)
		a[i].first = get_id(a[i].first);
	for(int i = 1; i <= q; ++i) {
		b[i].first = get_id(b[i].first);
		b[i].second = get_id(b[i].second);
	}
	for(int i = 1; i <= n; ++i)
		s[a[i].first] = a[i].second;
	for(int i = 1; i <= idx.size(); ++i)
		s[i] += s[i - 1];
	for(int i = 1; i <= q; ++i)
		cout << s[b[i].second] - s[b[i].first - 1] << '\n';
	cout.flush();
	return 0;
}