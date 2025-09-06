#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 1e6 + 3;
int a[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	for(int i = 2; i < N; ++i)
		if(a[i] == 0)
			for(int j = i; j < N; j += i)
				++a[j];
	vector<LL> ans;
	for(LL i = 2; i < N; ++i)
		if(a[i] == 2)
			ans.push_back(i * i);
	int _q;
	cin >> _q;
	for(LL x; _q--; cout.put('\n')) {
		cin >> x;
		cout << *prev(upper_bound(cbegin(ans), cend(ans), x));
	}
	cout.put('\n'); return 0;
}
