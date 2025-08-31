#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>
#include <utility>
#include <algorithm>
using namespace std;
#define _x first
#define _y second

const double eps = 1e-10;
const int N = 13;
pair<double, double> pos[N];
int n;

double dis(const double& x1, const double& y1, const double& x2, const double& y2)
{ return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); }

double check(const double& x, const double& y) {
	double res = 0;
	for(int i = 1; i <= n; ++i)
		res += dis(pos[i]._x, pos[i]._y, x, y);
	return res;
}

pair<double, double> SA() {
	double rx = 0.0, ry = 0.0;
	for(double t = 1000000.0; t > eps; t *= 0.99) {
		for(int i = 1; i <= n; ++i) {
			double tx = (rx + pos[i]._x) / 2, ty = (ry + pos[i]._y) / 2;
			auto dr = check(rx, ry), dt = check(tx, ty);
			if(dr < dt) {
				rx = tx;
				ry = ty;
			} else {
				random_device rd;
				mt19937_64 seed(rd());
				uniform_real_distribution<> distrib(0, 1);
				if(distrib(seed) <= 0.2) {
					rx = tx;
					ry = ty;
				}
			}
		}
	}
	return {rx, ry};
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 0; i <= n; ++i)
		cin >> pos[i]._x >> pos[i]._y;
	auto ans = SA();
	cout << fixed << setprecision(3) << ans._x << ' ' << ans._y;
	cout.flush();
	return 0;
}