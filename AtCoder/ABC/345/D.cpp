#include <iostream>
using namespace std;

const int N = 10;
int a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, h, w;
	cin >> n >> h >> w;
	for(int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i];
	return 0;
}