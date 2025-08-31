#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

const int N = 13;
struct Node
{ double x, y; }
pos[N], ans, result;
int n, l;

bool calc(Node now) {
	double xx = now.x, yy = now.y;
	for(int i = 1; i <= n; ++i) {
		double dx = xx - pos[i].x, dy = yy - pos[i].y;
		if(sqrt(dx * dx + dy * dy) <= 1.0 * l / n)
			return false;
	}
	return true;
}

void SA() {
    for(double t = 100000; t > 1e-6; t *= 0.9975) {
		Node now;
		now.x = fmod(ans.x + fabs((2.0 * rand() - RAND_MAX) * t), l);
		now.y = fmod(ans.y + fabs((2.0 * rand() - RAND_MAX) * t), l);
		if(calc(now))
			result = ans = now;
        else
			if(1.0 * rand() / RAND_MAX < 0.5)
				ans = now;
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	#endif // ONLINE_JUDGE
	cin >> n >> l;
	for(int i = 1; i <= n; ++i) {
		cin >> pos[i].x >> pos[i].y;
		ans.x += pos[i].x;
		ans.y += pos[i].y;
	}
	ans.x /= n;
	ans.y /= n;
	while(1.0 * clock() / CLOCKS_PER_SEC < 1.9)
		SA();
	if(!calc(result))
		cout << "GG";
	else
		cout << fixed << setprecision(6) << result.x << ' ' << result.y;
	return 0;
}