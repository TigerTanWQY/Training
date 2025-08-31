#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
//#include <random>
#include <chrono>
#include <utility>
#define double long double
using namespace std;
using namespace chrono;
using PDD = pair<double, double>;

const int N = 10003;
struct
{ int x, y, w; }
a[N];
PDD ans;
int n;
double dis;

double Rand()
{ return 1.0 * rand() / RAND_MAX; }

//double Rand() {
//	random_device rd;
//	mt19937_64 x(rd());
//	uniform_real_distribution<> f(0, 1);
//	return f(x);
//}

double calc(const double& x, const double& y) {
	double res = 0;
	for(int i = 1; i <= n; ++i) {
		double dx = a[i].x - x, dy = a[i].y - y;
		res += sqrt(dx * dx + dy * dy) * a[i].w;
	}
	if(res < dis) {
		dis = res;
		ans.first = x;
		ans.second = y;
	}
	return res;
}

void SA() {
	double t = 100000;
	for(PDD now; t > 0.001; t *= 0.97) {
		PDD nt = {now.first + t * (Rand() * 2 - 1), now.second + t * (Rand() * 2 - 1)};
		double delta = calc(nt.first, nt.second) - calc(now.first, now.second);
		if(exp(-delta / t) > Rand()) {
			now.first = nt.first;
			now.second = nt.second;
		}
	}
	for(int _ = 0; _ < 1000; ++_) {
		PDD nt = {ans.first + t * (Rand() * 2 - 1), ans.second + t * (Rand() * 2 - 1)};
		calc(nt.first, nt.second);
	}
}

int main() {
	auto S = system_clock::now();
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	#endif // ONLINE_JUDGE
	srand(time(NULL));
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].x >> a[i].y >> a[i].w;
		ans.first += a[i].x;
		ans.second += a[i].y;
	}
	ans.first /= n;
	ans.second /= n;
	dis = calc(ans.first, ans.second);
	while(duration_cast<microseconds>(system_clock::now() - S).count() * microseconds::period::num < 980000)
		SA();
	cout << fixed << setprecision(3) << ans.first << ' ' << ans.second;
	return 0;
}