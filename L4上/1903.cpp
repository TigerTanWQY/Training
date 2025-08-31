#include <iostream>
#include <iomanip>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
#define x first
#define y second

const int N = 200003;
pair<double, double> a[N], c[N];

double calc(const int& L, const int& R) {
	if(L >= R)
		return 0x3f3f3f3f;
	int M = (L + R) / 2, cnt = 0;
	double d = min(calc(L, M), calc(M + 1, R));
	for(int i = L; i <= R; ++i)
		if(abs(a[i].x - a[M].x) < d) {
			c[++cnt].x = a[i].y;
			c[cnt].y = a[i].x;
		}
	sort(c + 1, c + cnt + 1);
	for(int i = 1; i <= cnt; ++i)
		for(int j = i + 1; j <= cnt && c[j].x - c[i].x < d; ++j)
			d = min(d, sqrt((c[i].x - c[j].x) * (c[i].x - c[j].x) + (c[i].y - c[j].y) * (c[i].y - c[j].y)));
	return d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].x >> a[i].y;
	sort(a + 1, a + n + 1);
	cout << fixed << setprecision(7) << calc(1, n);
	return 0;
}