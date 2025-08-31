#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a[2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1, x; i <= n; ++i) {
		char tp;
		cin >> x >> tp;
		if(tp == 'L')
			a[0].push_back(x);
		else
			a[1].push_back(x);
	}
	int totL = 0, totR = 0;
	for(int i = 1; i < a[0].size(); ++i)
		totL += abs(a[0][i] - a[0][i - 1]);
	for(int i = 1; i < a[1].size(); ++i)
		totR += abs(a[1][i] - a[1][i - 1]);
	cout << totL + totR;
	cout.flush();
	return 0;
}