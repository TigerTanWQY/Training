#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e8;
vector<int> c;
int p[N + 3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i = 2; i <= N; ++i) {
		if(!p[i]) {
			p[i] = i;
			c.push_back(i);
		}
		for(int j = 0; j < c.size() && c[j] * i <= N; ++j) {
			p[i * c[j]] = c[j];
			if(p[i] == c[j])
				break;
		}
	}
	int _q;
	cin >> _q >> _q;
	for(int x; _q--; cout.put('\n')) {
		cin >> x;
		cout << c[x - 1];
	}
	cout.flush();
	return 0;
}
