#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2003;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	return 0;
}