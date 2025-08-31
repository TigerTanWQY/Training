#include <iostream>
#include <deque>
using namespace std;
using LL = long long;

constexpr const int N = 50003;
LL s[N], f[N];

double slope(const int& i, const int& j)
{ return 1.0 * (f[i] + (s[i] + i) * (s[i] + i) - f[j] - (s[j] + j) * (s[j] + j)) / (s[i] + i == s[j] + j? 1e-9: s[i] + i - s[j] - j); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, L;
	cin >> n >> L;
	++L;
	for(int i = 1; i <= n; ++i) {
		cin >> s[i];
		s[i] += s[i - 1];
	}
	deque<int> q;
	for(int i = 1; i <= n; ++i) {
		while(q.size() > 1 && slope(i - 1, q.back()) <= slope(q.back(), q[q.size() - 2]))
			q.pop_back();
		q.push_back(i - 1);
		while(q.size() > 1 && slope(q[1], q.front()) <= 2 * (s[i] + i - L))
			q.pop_front();
		const int j = q.front();
		f[i] = f[j] + (s[i] + i - s[j] - j - L) * (s[i] + i - s[j] - j - L);
	}
	cout << f[n];
	cout << endl;
	return 0;
}